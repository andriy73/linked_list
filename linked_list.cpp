#include "linked_list.h"

LinkedList::LinkedList() : first(nullptr), index(0) {}
LinkedList::~LinkedList() {}

int LinkedList::getIndex() const { return index; }
void LinkedList::printList() const
{
    unsigned count = 0;
    Node *current = first;
    do
    {
        std::cout << current->data << std::endl;
        current = current->next;
        ++count;
    } while (count < index);
}
void LinkedList::push_back(const int value)
{
    if (first == nullptr)
    {
        first = new Node(value);
        ++index;
    }
    else
    {
        if (first->prev == nullptr)
        {
            first->prev = new Node(value);
            first->prev->next = first;
            first->prev->prev = first;
            first->next = first->prev;
            ++index;
        }
        else
        {
            Node *previos = first->prev;
            first->prev = new Node(value);
            first->prev->next = first;
            first->prev->prev = previos;
            previos->next = first->prev;
            ++index;
        }
    }
}
void LinkedList::push_front(const int value)
{
    if (first == nullptr)
    {
        first = new Node(value);
        ++index;
    }
    else
    {
        if (first->next == nullptr)
        {
            first->next = new Node(value);
            first->next->prev = first;
            first->next->next = first;
            first->prev = first->next;
            first = first->next;
            ++index;
        }
        else
        {
            Node *previos = first->prev;
            first->prev = new Node(value);
            first->prev->next = first;
            first->prev->prev = previos;
            previos->next = first->prev;
            first = first->prev;
            ++index;
        }
    }
}
void LinkedList::insert(unsigned index_, const int value)
{
    unsigned count = 1;
    Node *current = first;
    bool is_first = true;
    if (index_ > index)
        index_ -= index;
    while (count < index_)
    {
        if (current->next != nullptr)
        {
            current = current->next;
            ++count;
            if (is_first)
                is_first = false;
        }
        else
        {
            //going out of the list
        }
    }
    Node *prev = current->prev;
    current->prev = new Node(value);
    current->prev->prev = prev;
    current->prev->next = current;
    prev->next = current->prev;
    if (is_first)
        first = current->prev;
    ++index;
}
void LinkedList::erase(unsigned index_)
{
    unsigned count = 1;
    Node *current = first;
    bool is_first = true;
    if (index_ > index)
        index_ -= index;
    while (count < index_)
    {
        if (current->next != nullptr)
        {
            current = current->next;
            ++count;
            if (is_first)
                is_first = false;
        }
        else
        {
            //going out of the list
        }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (is_first)
        first = current->next;
    delete current;
    --index;
}
int LinkedList::operator[](const unsigned index)
{
    unsigned count = 0;
    Node *current = first;
    ++count;
    while (count != index)
    {
        if (current->next != nullptr)
        {
            current = current->next;
            ++count;
        }
        else
        {
            //going out of the list
            return -1;
        }
    }
    return current->data;
}