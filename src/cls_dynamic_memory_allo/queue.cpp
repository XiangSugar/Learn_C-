// queue.cpp

#include <cstdlib>
#include "queue.h"

// 成员初始化列表
/*
1. This form can be used only with constructors.
2. You must (at least, in pre-C++11) use this form to initialize a nonstatic const data
member.
3. You must use this form to initialize a reference data member.

Data members are initialized in the order in which they appear in the class declaration, not
in the order in which initializers are listed.
*/
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}
Queue::~Queue()
{
    Node *temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}


bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node *add = new Node;
    add->next = nullptr;
    add->item = item;
    items++;

    if (front == nullptr)
        front = add;
    else
        rear = rear->next;
    rear = add;

    /*
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    */

return true;
}

bool Queue::dequeue(Item & item)
{
    if (isempty())
        return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;
}

//customer method

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
