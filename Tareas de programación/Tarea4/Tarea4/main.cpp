//
//  main.cpp
//  Tarea4
//
//  Created by Layla Tame on 2/8/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    
    LinkedList<string> miLista;
    
    miLista.addFirst("HOLA");
    miLista.addFirst("ALEJANDRO");
    miLista.addFirst("Y");
    miLista.addFirst("PAOLA");
    
    // for( int i = 0; i < miLista.getSize(); i++ ) {
    //   cout << miLista.get(i) << " ";
    // }
    // cout << endl;
    
    miLista.print();
    
    miLista.addLast("!!!!!");
    miLista.add("Y SALON", 3);
    
    miLista.print();
    
    // miLista.deleteFirst();
    // miLista.print();
    
    // miLista.del(1);
    // miLista.print();
    
    // miLista.deleteLast();
    // miLista.print();
    
    // miLista.deleteAll();
    // miLista.print();
    
    cout << miLista.get(0) << endl;
    
    cout << miLista.set(0, "KEVIN") << endl;
    
    miLista.print();
    
    miLista.change(0, 3);
    
    miLista.print();
    
    return 0;
}
