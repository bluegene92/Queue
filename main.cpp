#include <iostream>

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
        Peek the front of queue
        @return the pointer of Node
    */
    Node<T>* peek();

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
    return myList->peekTail();
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



int main()
{
    Queue<std::string>* q1 = new Queue<std::string>();
    std::cout << "Before inserting into queue, size: " << q1->get_size() << std::endl;
    if (q1->isEmpty())
        std::cout << "Queue is empty" << std::endl;

    q1->enqueue(1, "Dat");
    q1->enqueue(2, "Timmy");
    q1->enqueue(3, "Matt");
    q1->print();



    if(q1->dequeue())
    {
        std::cout << "After dequeue" << std::endl;
        q1->print();
    }

    q1->enqueue(4, "Nancy");
    q1->print();

    q1->dequeue();
    q1->print();

    std::string node_at_front = q1->peek()->get_data();

    std::cout << "The person in the front right now is " << node_at_front << std::endl;

    return 0;
}
