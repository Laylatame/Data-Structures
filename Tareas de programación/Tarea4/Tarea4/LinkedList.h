//
//  LinkedList.h
//  Tarea4
//
//  Created by Layla Tame on 2/8/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include "Node.h"
using namespace std;
#ifndef LinkedList_h
#define LinkedList_h

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    int iSize;
    void deleteHelp();
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &list); //No está
    
    T get(int iPos);
    T set(T data, int iPos); //Al reves
    bool isEmpty();
    int getSize();
    bool change(int iPos1, int iPos2);
    
    bool add(T data, int iPos);
    void addFirst(T data);
    void addLast(T data);
    
    bool del(int iPos);
    void deleteFirst();
    void deleteLast();
    int deleteAll();
    
    void print();
    void reverse();

    bool operator==(const LinkedList<T> &list);
    void operator+=(T data);
    void operator+=(const LinkedList<T> &list);
    void operator=(const LinkedList<T> &list);

};

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    iSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    deleteHelp();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    iSize = list -> iSize;
    Node<T> *currnt = list -> head;
    for (int i = 0; i < iSize; i++)
    {
        currnt -> addLast(currnt -> getData());
        currnt = currnt -> getNext();
    }
}

template <class T>
T LinkedList<T>::get(int iPos)
{
    Node<T> *currnt = head;
    for(int i=0; i<iPos; i++)
    {
        currnt = currnt->getNext();
    }
    return currnt->getData();
}

template <class T>
T LinkedList<T>::set(T data, int iPos)
{
    Node<T> *currnt = head;
    for(int i=0; i<iPos; i++)
    {
        currnt = currnt->getNext();
    }
    T temp = currnt->getData();
    currnt->setData(data);
    return temp;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (head == NULL);
}

template <class T>
int LinkedList<T>::getSize()
{
    return iSize;
}

template <class T>
bool LinkedList<T>::change(int iPos1, int iPos2)
{
    if (iPos1 == iPos2)
    {
        return true;
    }
    int minPos = (iPos1 < iPos2) ? iPos1 : iPos2;
    int maxPos = (iPos1 > iPos2) ? iPos1 : iPos2;
    
    Node <T> *currnt1 = head, currnt2;
    for (int i = 1; i <= minPos; i++)
    {
        currnt1 = currnt1 -> getNext();
    }
    
    currnt2 = currnt1;
    for (int i=minPos; i<=maxPos; i++)
    {
        currnt2 = currnt2 -> getNext();
    }
    
    T temp = currnt1 -> getData();
    currnt1->setData(currnt2->getData());
    currnt2->setData(temp);
    return true;
}

template <class T>
bool LinkedList<T>::add(T data, int iPos)
{
    if (iPos > iSize)
    {
        return false;
    }
    if (iPos == 0)
    {
        addFirst(data);
    }
    else if (iPos == iSize)
    {
        addLast(data);
    }
    else
    {
        Node<T> *currnt = head;
        for(int i=1; i<iPos; i++)
        {
            currnt = currnt->getNext();
        }
        currnt->setNext(new Node<T>(data, currnt->getNext()));
        iSize++;
    }
    return true;
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    iSize++;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
    if (isEmpty())
    {
        addFirst(data);
    }
    else
    {
        Node<T> *currnt = head;
        while (currnt -> getNext() != NULL)
        {
            currnt = currnt->getNext();
        }
        currnt = new Node<T>(data);
        iSize++;
    }
}

template <class T>
bool LinkedList<T>::del(int iPos)
{
    if (iPos < iSize)
    {
        if (iPos == 0)
        {
            deleteFirst();
        }
        else if (iPos == iSize - 1)
        {
            deleteLast();
        }
        else
        {
            Node<T> *currnt = head;
    
            for (int i=1; i<iPos; i++)
            {
                currnt = currnt->getNext();
            }
            
            Node<T> *temp = currnt -> getNext();
            currnt->setNext(currnt->getNext()->getNext());
            delete temp;
            iSize--;
        }
    }
    return true;
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (!this-> isEmpty())
    {
        Node<T> *currnt = head;
        head = head->getNext();
        delete currnt;
        iSize--;
    }
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (iSize <= 1)
    {
        deleteFirst();
    }
    else
    {
        Node<T> *currnt = head;
        while(currnt -> getNext() -> getNext() != NULL)
        {
            currnt = currnt -> getNext();
        }
        delete currnt ->getNext();
        currnt -> setNext(NULL);
        iSize--;
    }
}

template <class T>
int LinkedList<T>::deleteAll()
{
    deleteHelp();
    int iCount = iSize;
    iSize = 0;
    return iCount;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *currnt = head;
    while(currnt != NULL)
    {
        cout << currnt -> getData() << " " ;
        currnt = currnt -> getNext();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::reverse()
{
    Node<T> *currnt = nullptr;
    Node<T> *next = head->getNext();
    if(iSize >= 2)
    {
        while(next != nullptr)
        {
            head ->setNext(currnt);
            currnt = head;
            head = next;
            next = head->getNext();
        }
        head-setNext(currnt);
        delete next;
    }
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &list)
{
    Node<T> *currnt = list -> head;
    Node<T> *currnt1 = head;
    if (iSize != list -> iSize)
    {
        return false;
    }
    for (int i=0; i<iSize; i++)
    {
        if (currnt1 -> get(i) == list -> get(i))
        {
            currnt1 -> getNext();
            currnt = currnt -> getNext();
        }
        else
        {
            return false;
        }
    }
    return true;
    
    //OTRA
    /*Node<T> *curr = head;
     Node<T> *curr1 = LL.head;
     if ( iSize != LL.iSize()) {
     return false;
     }
     for ( int i = 0; i < iSize; i++) {
     if(curr->getData() != curr1 -> getData()) {
     return false;
     }
     curr = curr ->getNext();
     curr1 = curr1 ->getNext();
     }
     return true;*/
}

template <class T>
void LinkedList<T>::operator+=(T data)
{
    addLast(data);
}

template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &list)
{
    Node<T> *currnt = list -> head;
    for (int i=0; i<list -> iSize; i++)
    {
        addLast(currnt->getData());
        currnt =  currnt -> getNext();
    }
    
    //OTRO
    /*
     Node<T> *curr = head;
     Node<T> *curr1 = LL.head;
     while (curr -> getNext() != nullptr) {
     curr = curr -> getNext();
     curr1 = curr1 -> getNext();
     }
     */
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &list)
{
    deleteAll();
    Node<T> *currnt = head;
    iSize = list -> iSize;
    for(int i=0; i<iSize; i++)
    {
        currnt -> addLast(currnt -> getData());
        currnt = currnt -> getNext();
    }
    
    //OTRO
    /*
     deleteAll();
     this -> iSize = LL.iSize();
     head ) new Node<T>(LL.head --> getData(), nullptr);
     Node<T> *curr1 = LL.head->getNext();
     node<T> *Curr = head;
     while ( curr1 != nullptr) {
     curr -> setNext(new Node<T>(curr1->getData(), nullptr));
     curr = curr->getNext();
     curr1 = curr1->getNext();
     }
     */
}

#endif /* LinkedList_h */
