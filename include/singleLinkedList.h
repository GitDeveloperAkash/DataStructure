#include <iostream>
using namespace std;

template <class T>
class NODE
{
public:

    T data;
    class NODE* next;
    NODE(T data)
    {
        this->data = data;
    }
};





template <class T>
class singleLinkedList
{
    public:
        singleLinkedList();
        virtual ~singleLinkedList();

        void PushBack(T val);
        void PushFront(T val);
        void Insert(int Pos, T val);

        void DeleteBack();
        void DeleteFront();
        void Delete(int Pos);

        void Reverse();

        void display();
        int getSize();

    protected:
        int SIZE;

    private:
        NODE<T> *Head;
        NODE<T> *Tail;
};


template <class T>
void singleLinkedList<T>::Reverse()
{
    NODE<T> *Next = nullptr;
    NODE<T> *Current = nullptr;
    NODE<T> *Prev = nullptr;

    Current = Head;

    while(Current)
    {
        Next = Current->next;
        Current->next = Prev;
        Prev = Current;
        Current = Next;
    }
    Head = Prev;
}

template <class T>
void singleLinkedList<T>::Delete(int Pos)
{
    if(Pos < 1 || Pos > SIZE)
    {
        cout << "Invalid Position " << endl;
        return;
    }

    NODE<T> *current;
    current = Head;

    if(Pos == 1)
    {
        Head = Head->next;
        return;
    }
    else
    {
        while(Pos > 2)
        {
            current = current->next;
            Pos--;
        }
        current->next = current->next->next;
        return;
    }
    SIZE--;
}

template <class T>
void singleLinkedList<T>::DeleteFront()
{
    if(!Head)
    {
        cout << " No NODE is found to delete" << endl;
        return;
    }
    if(Head == Tail)
    {
        Head = Tail = nullptr;
        SIZE--;
        return;
    }

    Head = Head->next;
    SIZE--;
}

template <class T>
void singleLinkedList<T>::DeleteBack()
{
    if(!Head)
    {
        cout << " No NODE is found to delete" << endl;
        return;
    }
    if(Head == Tail)
    {
        Head = Tail = nullptr;
        SIZE--;
        return;
    }

    NODE<T> *current;
    current = Head;
    while(current->next)
    {
        if(current->next == Tail)
        {
            current->next = nullptr;
            Tail = current;
            SIZE--;
            return;
        }
        current = current->next;
    }
}

template <class T>
int singleLinkedList<T>::getSize()
{
    return SIZE;
}

template <class T>
void singleLinkedList<T>::Insert(int Pos, T val)
{
    if(Pos < 1 || Pos > SIZE)
    {
        cout << "Invalid Position " << endl;
        return;
    }
    NODE<T> *newNode;
    newNode = new NODE<T>(val);
    newNode->next = nullptr;

    NODE<T> *current;
    current = Head;

    while(--Pos)
        current = current->next;

    if(current == Head)
    {
        newNode->next = Head;
        Head = newNode;
    }
    else if(current == Tail)
    {
        Tail->next = newNode;
        Tail = newNode;
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
    }

    SIZE++;
}


template <class T>
void singleLinkedList<T>::PushBack(T val)
{
    NODE<T> *newNode;
    newNode = new NODE<T>(val);
    newNode->next = nullptr;

    if(Tail)
    {
        Tail->next = newNode;
        Tail = newNode;
    }
    else
    {
        Tail = newNode;
        Head = Tail;
    }
    SIZE++;
}

template <class T>
void singleLinkedList<T>::PushFront(T val)
{
    NODE<T> *newNode;
    newNode = new NODE<T>(val);
    newNode->next = nullptr;

    if(Head)
    {
        newNode->next = Head;
        Head = newNode;
    }
    else
    {
        Head = newNode;
        Tail = Head;
    }
    SIZE++;
}



template <class T>
void singleLinkedList<T>::display()
{
    struct NODE<T> *current;
    current = Head;
    while(current)
    {
        cout << current->data;
        current = current->next;
        if(current)
            cout << " --> " ;
    }
    cout << endl;
}

template <class T>
singleLinkedList<T>::singleLinkedList():Head(nullptr), Tail(nullptr),SIZE(0)
{
    cout << "constructor invoked " << endl;

}

template <class T>
singleLinkedList<T>::~singleLinkedList()
{
    cout << "distructor invoked " << endl;
}


