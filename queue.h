#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

template <class T>
class Queue
{
public:
    /**
        Create a queue
        set default size to 100
    */
    Queue();

    /**
        Create a queue
        @size - the size of queue
    */
    Queue(int size);

    /**
        Add node to queue
    */
    void enqueue(int key, T data);

    /**
        Remove the node in the front
    */
    bool dequeue();

    /**
        Peek the front of queue,
        same as top
        @return the pointer of Node
    */
    Node<T>* peek();

    /**
        Check the end of queue
    */
    Node<T>* rear();

    /**
        Get the current size of queue
    */
    int get_size() const;

    /**
        Print the queue
    */
    void print() const;

    /**
        Check if queue is full
        i.e. if _size_tracker > _size
    */
    bool isFull() const;

    /**
        Check if queue is empty
        i.e if _size is 0
    */
    bool isEmpty() const;

private:
    int _size;
    int _size_tracker;
    LinkedList<T>* myList;
};

template <class T>
Queue<T>::Queue()
{
    myList = new LinkedList<std::string>();
    _size = 100;
    _size_tracker = 0;
}

template <class T>
Queue<T>::Queue(int s): _size(s) {}

template <class T>
void Queue<T>::enqueue(int key, T data)
{
    if (_size > 100)
        return;

    myList->insertNodeHead(key, data);
    ++_size_tracker;
}

template <class T>
void Queue<T>::print() const
{
    myList->print();
    std::cout << "Current queue size: " << _size_tracker << std::endl;
}

template <class T>
int Queue<T>::get_size() const
{
    return _size_tracker;
}

template <class T>
bool Queue<T>::dequeue()
{
    if (myList->deleteNodeTail())
    {
        --_size_tracker;
        return true;
    }
    return false;
}

template <class T>
Node<T>* Queue<T>::peek()
{
    //peekTail is the last node of the linked list
    //but its the head of queue
    return myList->peekTail();
}

template <class T>
Node<T>* Queue<T>::rear()
{
    return myList->peekHead();
}

template <class T>
bool Queue<T>::isFull() const
{
    return _size_tracker >= _size;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return _size_tracker == 0;
}

#endif
