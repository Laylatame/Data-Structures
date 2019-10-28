//
//  main.cpp
//  tarea6
//
//  Created by Layla Tame on 3/6/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//



#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int iTemp1, iTemp2, iNum, iData;
stack<int> stackPrueba;
queue<int> queuePrueba;
priority_queue <int, vector<int>, greater<int> > minPriority;

void stackFunction(string d)
{
    iTemp1 = stackPrueba.top();
    stackPrueba.pop();
    iTemp2 = stackPrueba.top();
    stackPrueba.pop();
    
    if (d == "+"){
        iNum = iTemp2 + iTemp1;
        stackPrueba.push(iNum);
    }
    if (d == "-"){
        iNum = iTemp2 - iTemp1;
        stackPrueba.push(iNum);
    }
    if (d == "*"){
        iNum = iTemp2 * iTemp1;
        stackPrueba.push(iNum);
    }
    if (d == "/"){
        iNum = iTemp2 / iTemp1;
        stackPrueba.push(iNum);
    }
}

void queueFunction(string d)
{
    iTemp1 = queuePrueba.front();
    queuePrueba.pop();
    iTemp2 = queuePrueba.front();
    queuePrueba.pop();
    
    if (d == "+"){
        iNum = iTemp2 + iTemp1;
        queuePrueba.push(iNum);
    }
    if (d == "-"){
        iNum = iTemp2 - iTemp1;
        queuePrueba.push(iNum);
    }
    if (d == "*"){
        iNum = iTemp2 * iTemp1;
        queuePrueba.push(iNum);
    }
    if (d == "/"){
        iNum = iTemp2 / iTemp1;
        queuePrueba.push(iNum);
    }
}

void minPriorityFunction(string d)
{
    iTemp1 = minPriority.top();
    minPriority.pop();
    iTemp2 = minPriority.top();
    minPriority.pop();
    
    if (d == "+"){
        iNum = iTemp2 + iTemp1;
        minPriority.push(iNum);
    }
    if (d == "-"){
        iNum = iTemp2 - iTemp1;
        minPriority.push(iNum);
    }
    if (d == "*"){
        iNum = iTemp2 * iTemp1;
        minPriority.push(iNum);
    }
    if (d == "/"){
        iNum = iTemp2 / iTemp1;
        minPriority.push(iNum);
    }
}

void borrarStack()
{
    unsigned long iSize = stackPrueba.size();
    for(int i=0; i<iSize; i++)
    {
        stackPrueba.pop();
    }
}

void borrarQueue()
{
    unsigned long iSize = queuePrueba.size();
    for(int i=0; i<iSize; i++)
    {
        queuePrueba.pop();
    }
}

void borrarMinPriority()
{
    unsigned long iSize = minPriority.size();
    for(int i=0; i<iSize; i++)
    {
        minPriority.pop();
    }
}

int main(){
    
    string d,data;
    getline(cin, data);
    while (data != "#"){
        stringstream ss;
        ss << data;
        //Lee cada linea y termina cuando acaba el último símbolo
        while (ss >> d){
            if(d != "-" && d != "+" && d != "*" && d != "/")
            {
                stringstream iss(d);
                iss >> iData;
                stackPrueba.push(iData);
                queuePrueba.push(iData);
                minPriority.push(iData);
            }
            else
            {
                stackFunction(d);
                queueFunction(d);
                minPriorityFunction(d);
            }
            
            //cout << d << " ";
        }
        cout << stackPrueba.top() << " " << queuePrueba.front() << " " << minPriority.top() << endl;
        borrarStack();
        borrarQueue();
        borrarMinPriority();
        getline(cin, data);
    }
}



