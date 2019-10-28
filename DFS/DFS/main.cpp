//
//  main.cpp
//  DFS
//
//  Created by Layla Tame on 5/3/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void leeListAdj(vector<vector<int>> &listAdj, int e)
{
    int a, b;
    for (int i=0; i<e; i++)
    {
        cin >> a >> b;
        listAdj[a-1].push_back(b-1);
        listAdj[b-1].push_back(a-1);
    }
}

void printListAdj(vector<vector<int>> &listAdj)
{
    for (int i=0; i<listAdj.size(); i++)
    {
        cout << (i+1) << ": ";
        for (int j=0; j<listAdj[i].size(); j++)
        {
            cout << "->" << listAdj[i][j]+1;
        }
        cout << endl;
    }
}

void DFS(vector<vector<int>> &listAdj)
{
    stack<int> pila;
    int data;
    vector<bool> status(listAdj.size(), false);
    pila.push(0);
    while(!pila.empty())
    {
        data = pila.top();
        pila.pop();
        if(!status[data])
        {
            status[data] = true;
            cout << (data+1) << " ";
            for (int j=listAdj[data].size()-1; j>=0; j--)
            {
                if(!status[listAdj[data][j]])
                {
                    pila.push(listAdj[data][j]);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    //v = Nodos (Vertex), e = Arcos (Edges)
    int v, e;
    cin >> v >> e;
    vector<vector<int>> listAdj(v);
    leeListAdj(listAdj, e);
    printListAdj(listAdj);
}
