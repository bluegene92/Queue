#ifndef NODE_H
#define NODE_H

template <class T>
/**
    Store key and data to be use on Data Structure
    i.e. LinkedList, Binary Tree, Stack, Queue
*/
class Node
{
public:
    /**
        Create a new node
        @key - the key of the node
        @data - the data to be stored in the node
    */
    Node(int key, T data);

    /**
        Get the key of the node
        @return the key of the node
    */
    int get_key() const;

    /**
        Get the data of the node (i.e. string, int, double, etc)
        @return the data of the node
    */
    T get_data() const;

    /**
        Get the next node
        [current]-[next]-...
    */
    Node* get_next() const;

    /**
        Get the previous node
        [previous]-[current]-...
    */
    Node* get_prev() const;

    /**
        Set the pointer of node to point the next node
    */
    void set_next(Node *p_next);

    /**
        Set the pointer of node to point to the previous node
    */
    void set_prev(Node *p_prev);
private:
    int key;
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <class T>
Node<T>::Node(int key, T data)
{
    this->key = key;
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
int Node<T>::get_key() const
{
    return this->key;
}

template <class T>
T Node<T>::get_data() const
{
    return this->data;
}

template <class T>
Node<T>* Node<T>::get_next() const
{
    return next;
}

template <class T>
Node<T>* Node<T>::get_prev() const
{
    return prev;
}

template <class T>
void Node<T>::set_next(Node<T>* p_next)
{
    this->next = p_next;
}

template <class T>
void Node<T>::set_prev(Node<T>* p_prev)
{
    this->prev = p_prev;
}

#endif
