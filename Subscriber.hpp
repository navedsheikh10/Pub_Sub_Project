#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <string>
#include <iostream>
using namespace std;
// Message structure with a topic and content
struct Message {
    string topic;
    string content;
};

class Subscriber {
private:
    string id;

public:
    Subscriber(string id) {
        this->id = id;
    }


    // Receive and print the message
    void receive(const Message& msg) {
        cout << id << " received message on topic '" << msg.topic 
                  << "': " << msg.content << endl;
    }
};

#endif // SUBSCRIBER_HPP
