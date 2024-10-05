# Pub-Sub Model with Multithreading in C++

This project implements a Publisher-Subscriber (Pub-Sub) model using C++ with multithreading. The project simulates the asynchronous delivery of messages from publishers to subscribers based on different topics, with the `PubSubBroker` acting as the intermediary. 

## Table of Contents
- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)

## Project Overview
This project implements an efficient Pub-Sub system using Object-Oriented Programming (OOP) principles and multithreading to handle the asynchronous delivery of messages. The system consists of:
- **Publisher**: Publishes messages to the broker under specific topics.
- **Subscriber**: Receives messages from the broker for the topics they are subscribed to.
- **PubSubBroker**: Handles subscriptions and the delivery of messages asynchronously using a separate thread.

## Key Features
- Multithreaded message delivery using C++ `std::thread`.
- Asynchronous processing of messages using a background worker thread.
- Thread-safe access to shared resources using `mutex` and `condition_variable`.
- Supports multiple subscribers and publishers.
- FIFO message delivery through a message queue.

## Project Structure
.
├── Publisher.hpp    # Publisher class header
├── Subscriber.hpp   # Subscriber class header
├── PubSubBroker.hpp # PubSubBroker class header
├── main.cpp         # Entry point of the program
└── README.md        # This file

**Example Output**
The program demonstrates message delivery for two topics: news and weather. Below is an example output:
Subscriber1 received message on topic 'news': AI writes poems!
Subscriber2 received message on topic 'weather': Sunny day ahead.
Subscriber1 received message on topic 'news': Tech conference next week.
Subscriber2 received message on topic 'weather': Rain expected this weekend.
Subscriber1 received message on topic 'news': New AI model released.
Subscriber2 received message on topic 'weather': Cold front approaching.

## How It Works
**Main Program (main.cpp)**: Sets up the broker, creates subscribers, and subscribes them to specific topics. Publishers publish messages, which are handled asynchronously by the broker.

**PubSubBroker**: Manages the subscription of topics, queuing of messages, and their delivery using a background thread. The broker uses mutex and condition_variable to ensure thread safety while accessing the message queue.

**Multithreading**: A worker thread in the PubSubBroker runs the processMessages() function, which processes messages from the queue and delivers them to the subscribers asynchronously.

**Message Queue**: Ensures that messages are delivered in a First-In-First-Out (FIFO) manner.

**Key Components**:
**Publisher**: Publishes a message by creating a Message object and sending it to the broker.
**Subscriber**: Receives messages on topics they are subscribed to.
**PubSubBroker**: Uses multithreading to process messages and deliver them to subscribers asynchronously.

