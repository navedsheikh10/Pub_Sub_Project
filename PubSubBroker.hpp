#ifndef PUBSUBBROKER_HPP
#define PUBSUBBROKER_HPP

#include <unordered_map>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Subscriber.hpp"

class PubSubBroker {
private:
    std::unordered_map<std::string, std::vector<Subscriber*>> subscribers; // Stores subscribers per topic
    std::queue<Message> messageQueue; // Message queue
    std::mutex mtx; // Mutex for thread safety
    std::condition_variable cv; // Condition variable to signal message availability
    bool stop = false;

    // Background thread to process messages asynchronously
    void processMessages() {
        while (!stop) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return !messageQueue.empty() || stop; }); // Wait for messages

            while (!messageQueue.empty()) {
                Message msg = messageQueue.front();
                messageQueue.pop();

                if (subscribers.count(msg.topic)) { // Deliver message to each subscriber of the topic
                    for (Subscriber* sub : subscribers[msg.topic]) {
                        sub->receive(msg);
                    }
                }
            }
        }
    }

    std::thread workerThread;

public:
    PubSubBroker() {
    workerThread = std::thread(&PubSubBroker::processMessages, this);
    }


    ~PubSubBroker() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true; // Signal the thread to stop
        }
        cv.notify_all();
        workerThread.join(); // Wait for thread to finish
    }

    // Subscribe a subscriber to a topic
    void subscribe(const std::string& topic, Subscriber* subscriber) {
        std::lock_guard<std::mutex> lock(mtx);
        subscribers[topic].push_back(subscriber);
    }

    // Publish a message
    void publish(const Message& msg) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            messageQueue.push(msg); // Add the message to the queue
        }
        cv.notify_one(); // Notify the thread that a new message is available
    }
};

#endif // PUBSUBBROKER_HPP
