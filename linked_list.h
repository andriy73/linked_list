#include <iostream>
#include <string.h>
#include <fstream>

enum OrderSide
{
    front,
    back
};
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class LinkedList
{
private:
    Node *first;
    unsigned index;

public:
    LinkedList();
    ~LinkedList();

    int getIndex() const;
    void printList() const;
    void listFile(const std::string &fileName) const;
    void fileList(const std::string &fileName, OrderSide order);
    void push_back(const int value);
    void push_front(const int value);
    void insert(unsigned index_, const int value);
    void erase(unsigned index_);
    int operator[](const unsigned index);
};