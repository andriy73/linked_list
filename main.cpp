#include "linked_list.h"

int main()
{
    std::cout << "App init" << std::endl;
    LinkedList ls;
    ls.push_back(17);
    ls.push_front(33);
    ls.push_back(26);
    ls.push_front(11);
    ls.push_back(22);
    ls.push_front(19);
    ls.push_back(29);
    ls.push_front(14);
    ls.insert(3, 21);
    std::cout << "Index: " << ls.getIndex() << std::endl;
    ls.printList();
    ls.erase(10);
    std::cout << std::endl;
    ls.printList();

    return 0;
}