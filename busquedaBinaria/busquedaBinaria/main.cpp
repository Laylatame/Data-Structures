//
//  main.cpp
//  busquedaBinaria
//
//  Created by Layla Tame on 3/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include "BST.h"
using namespace std;

int main() {
    
    BST binTree, binTree2;
    
    int iData;
    string s, data;
    stringstream ss;
    //Leer input
    cout << "Input: ";
    getline(cin,s);
    ss << s;
    while(ss >> data)
    {
        stringstream iss(data);
        iss >> iData;
        binTree2.add(iData);
    }
    
    //56 47 69 22 49 11 29 51 50 59 72 70
    
    binTree.add(56);
    binTree.add(47);
    binTree.add(69);
    binTree.add(22);
    binTree.add(49);
    binTree.add(11);
    binTree.add(29);
    binTree.add(51);
    binTree.add(50);
    binTree.add(59);
    binTree.add(72);
    binTree.add(70);
    
    //56 47 69 22 49 11 29 51 59 72 70 50
    //20 14 25 10 18 17 28 27 30 19
    
    //binTree.remove(56);
    //binTree.add(60);
    /*
    binTree.print(1);
    binTree.printLeaves();
    binTree.count();
    cout << binTree.getHeight() << endl;
    binTree.printAncestors(50);
    */
    cout << "Preorden: ";
    binTree2.print(1);;
    cout << "Inorden: ";
    binTree2.print(2);
    cout << "Postorden: ";
    binTree2.print(3);
    cout << "Nodos hoja: ";
    binTree2.printLeaves();
    cout << "Count: ";
    binTree2.count();
    cout << "What level: " << binTree2.whatLevel(14) << endl;
    cout << "Height: " << binTree2.getHeight() << endl;
    cout << "Ancestors: ";
    binTree2.printAncestors(51);
    cout << "Level by level: ";
    binTree2.print(5);
    cout << "Max Width: ";
    cout << binTree2.maxWidth() << endl;
    cout << "Nearest Relative: " << binTree2.nearestRelative(29, 51) << endl;
    
    BST binTree3 = binTree2;
    cout << "Preorden COPY CONSTRUCTOR: ";
    binTree3.print(2);
    cout << "Mirror: ";
    binTree2.mirror();
    binTree2.print(2);
    
    cout << "Are equal? ";
    if(binTree == binTree3)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}


