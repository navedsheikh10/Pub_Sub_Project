#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <string>
#include "PubSubBroker.hpp"
using namespace std;
class Publisher {
private:
    PubSubBroker* broker;

public:
    Publisher(PubSubBroker* b) {
        broker = b;
    }

    // Publish a message to the broker
    void publish(const string& topic, const string& message) {
        Message msg{topic, message}; // Create a message
        broker->publish(msg);        // Send it to the broker
    }
};

#endif // PUBLISHER_HPP
