#include <iostream>

#include "queue.h"

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

    std::string node_at_end = q1->rear()->get_data();

    std::cout << "The person at the front of the queue: " << node_at_front << std::endl;
    std::cout << "The person at the end of the queue: " << node_at_end << std::endl;

    return 0;
}
