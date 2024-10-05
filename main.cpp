#include <iostream>
#include "Publisher.hpp"
#include "PubSubBroker.hpp"
#include "Subscriber.hpp"

int main() {
    PubSubBroker broker; // Broker to handle subscriptions and message delivery

    // Creating subscribers
    Subscriber subscriber1("Subscriber1");
    Subscriber subscriber2("Subscriber2");

    // Subscribing to topics
    broker.subscribe("news", &subscriber1);
    broker.subscribe("weather", &subscriber2);

    // Creating publisher and publishing messages
    Publisher publisher(&broker);
    publisher.publish("news", "AI writes poems!");
    publisher.publish("weather", "Sunny day ahead.");
    publisher.publish("news", "Tech conference next week.");
    publisher.publish("weather", "Rain expected this weekend.");
    publisher.publish("news", "New AI model released.");
    publisher.publish("weather", "Cold front approaching.");

    // Give time for messages to be delivered
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
