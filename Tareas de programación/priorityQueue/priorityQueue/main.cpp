//
//  main.cpp
//  priorityQueue
//
//  Created by Layla Tame on 4/25/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include "Priority.h"
#include <vector>
using namespace std;

int main()
{
    Priority myPq;
    
    myPq.push(2);
    myPq.push(3);
    myPq.push(1);
    myPq.push(4);
    myPq.push(10);
    myPq.push(5);
    
    cout << "Priority: ";
    myPq.print();
    
    cout << "Size: " << myPq.size() << endl;
    
    cout << "After pop: ";
    myPq.pop();
    myPq.print();

    cout << "Top: " << myPq.top() << endl;
    
    cout << "Size: " << myPq.size() << endl;
    
    cout << "Empty: ";
    if(myPq.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
}
