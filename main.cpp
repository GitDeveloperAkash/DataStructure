#include <iostream>
#include <singleLinkedList.h>
using namespace std;

int main()
{
    singleLinkedList<int> _list;

    _list.PushBack(10);
    _list.PushBack(20);
    _list.PushBack(30);
    _list.PushFront(80);
    _list.PushBack(40);
    _list.PushFront(70);
    _list.PushFront(90);

    _list.Insert(1,50);
    _list.DeleteBack();
    _list.display();


    return 0;
}
