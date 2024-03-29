//
//  main.cpp
//  BFS
//
//  Created by Layla Tame on 4/30/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 10

void iniMatAdj(bool matAdj[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[N][N], int e)
{
    int orig, dest;
    for(int i=0; i<e; i++)
    {
        cin >> orig >> dest;
        matAdj[orig-1][dest-1] = matAdj[dest-1][orig-1] = true;
    }
}

void printMatAdj(bool matAdj[N][N], int v)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout << (matAdj[i][j] ? "T" : "F") << "\t";
        }
        cout << endl;
    }
}

void BFS(bool matAdj[N][N], int v)
{
    queue<int> fila;
    vector<bool> status(v, false);
    int dato;
    
    fila.push(0);
    status[0] = true;
    while(!fila.empty())
    {
        dato = fila.front();
        fila.pop();
        cout << (dato+1) << " ";
        for(int j=0; j<v; j++)
        {
            if(!status[j] && matAdj[dato][j])
            {
                status[j] = true;
                fila.push(j);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    bool matAdj[N][N];
    int v, e = 0;
    
    cin >> v >> e;
    
    iniMatAdj(matAdj);
    leeMatAdj(matAdj, e);
    printMatAdj(matAdj, v);
}
