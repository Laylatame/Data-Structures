//
//  Priority.h
//  priorityQueue
//
//  Created by Layla Tame on 4/25/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#ifndef Priority_h
#define Priority_h

#include <iostream>
#include <vector>
using namespace std;

class Priority{
private:
    int iSize;
    bool bPriority;
    vector<int> fila;
    void pushMenor(int);
    void pushMayor(int);
public:
    Priority();
    Priority(bool);
    void push(int);
    void pop();
    int top();
    int size();
    bool empty();
    void print();
};

Priority::Priority()
{
    fila.assign(101,0);
    iSize = 0;
    bPriority = true; //La prioridad es de mayor valor
}

Priority::Priority(bool bPrior)
{
    fila.assign(101, 0);
    iSize = 0;
    bPriority = bPrior;
}

void Priority::pushMayor(int iNum)
{
    int tempSize = (iSize-1)/2;
    int tempIndex = 0;
    
    if(iSize == 0 || fila[0] <= iNum)
    {
        fila.insert(fila.begin(), iNum);
    }
    else if(fila[iSize-1] >= iNum)
    {
        fila.insert(fila.begin()+iSize, iNum);
    }
    else
    {
        while(fila[tempSize] < iNum || fila[tempSize+1] > iNum)
        {
            while(fila[tempSize] > iNum)
            {
                tempIndex = tempSize;
                tempSize += iSize/2;
            }
            
            tempSize = (tempIndex+tempSize)/2;
        }
        
        fila.insert(fila.begin()+tempSize+1, iNum);
    }
    iSize++;
}

void Priority::pushMenor(int iNum)
{
    int tempSize = (iSize-1)/2;
    int tempIndex = 0;
    
    if(iSize == 0 || fila[0] >= iNum)
    {
        fila.insert(fila.begin(), iNum);
    }
    else if(fila[iSize-1] <= iNum)
    {
        fila.insert(fila.begin()+iSize, iNum);
    }
    else
    {
        while(fila[tempSize] > iNum || fila[tempSize+1] < iNum)
        {
            while(fila[tempSize] < iNum)
            {
                tempIndex = tempSize;
                tempSize += iSize/2;
            }
            
            tempSize = (tempIndex+tempSize)/2;
        }
        
        fila.insert(fila.begin()+tempSize+1, iNum);
    }
    iSize++;
}

void Priority::push(int iNum)
{
    if(bPriority)
    {
        pushMayor(iNum);
    }
    else
    {
        pushMenor(iNum);
    }
}


void Priority::pop()
{
    fila.erase(fila.begin());
    iSize--;
}

int Priority::top()
{
    return fila[0];
}

int Priority::size()
{
    return iSize;
}

bool Priority::empty()
{
    if(iSize == 0)
    {
        return true;
    }
    return false;
}

void Priority::print()
{
    for (int i=0; i<iSize; i++)
    {
        cout << fila[i] << " ";
    }
    cout << endl;
}

#endif /* Priority_h */
