// queue.h -- interface of queue
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

// This queue will contain Customer items
class Customer
{
private:
    long arrive;
    // arrival time for customer
    int processtime;
    // processing time for customer
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    enum
    {
        Q_SIZE = 10
    };

    const int qsize;
    int items;
    struct Node
    {
        struct Node *next;
        Item item;
    };
    Node *front;
    Node *rear;
    // preemptive definitions to prevent public copying
    // TO DO  explain
    Queue(const Queue &q);
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};
#endif
