//
//  main.cpp
//  phoneBook
//
//  Created by Layla Tame on 4/25/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct contact
{
    int phone;
    string name;
};

vector<contact> vContacts;

void add(int phone, string name)
{
    bool bFound = false;
    for(int i=0; i<vContacts.size(); i++)
    {
        if(vContacts[i].phone == phone)
        {
            vContacts[i].name = name;
            bFound = true;
            break;
        }
    }
    if(bFound == false)
    {
        vContacts.push_back({phone, name});
        
    }
}

void del(int phone)
{
    for(int i=0; i<vContacts.size(); i++)
    {
        if(vContacts[i].phone == phone)
        {
            vContacts.erase(vContacts.begin()+i);
            break;
        }
    }
}

void find(int phone)
{
    string tempName;
    bool bFound = false;
    for(int i=0; i<vContacts.size(); i++)
    {
        if(vContacts[i].phone == phone)
        {
            tempName = vContacts[i].name;
            bFound = true;
            break;
        }
    }
    if(bFound == false)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << tempName << endl;
    }
}

void readFile(string type)
{
    int phone;
    string name;
    
    if(type == "add")
    {
        cin >> phone >> name;
        add(phone, name);
    }
    else if(type == "del")
    {
        cin >> phone;
        del(phone);
    }
    else if(type == "find")
    {
        cin >> phone;
        find(phone);
    }
}

int main(){
    
    int queries;
    string type;
    cin >> queries;
    
    for(int i=0; i<queries; i++)
    {
        cin >> type;
        readFile(type);
    }

}
