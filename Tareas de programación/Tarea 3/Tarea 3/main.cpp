//
//  main.cpp
//  Tarea 3
//
//  Created by Layla Tame on 1/22/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool sortcol( const vector<int>& v1, const vector<int>& v2 )
{
    return v1[3] > v2[3];
}


int main()
{
    int t, p, s;
    
    cin >> t >> p;
    
    string names[t];
    vector<vector<int>> vec;
    vec.resize(t, vector<int>(p+3,0));
    string team, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char prob, acc;
    int time, count = 0;
    
    for (int i = 0; i<t; i++)
    {
        cin >> names[i];
    }
    
    for (int i = 0; i<t; i++)
    {
        vec[i][0] = i;
    }
    
    cin >> s;

    //Sumar problemas y tiempos
    while (count < s)
    {
        cin >> team >> prob >> time >> acc;
        for (int j = 0; j<t; j++)
        {
            if (names[j] == team)
            {
                for (int k = 0; k<26; k++)
                {
                    if (alphabet[k] == prob)
                    {
                        if (acc == 'W')
                        {
                            vec[j][k+1] += 1;
                        }
                        else
                        {
                            vec[j][p+2] = vec[j][p+2] + time + vec[j][k+1]*20;
                            vec[j][p+1] += 1;
                        }
                        break;
                    }
                }
                break;
            }
        }
        count++;
    }
    
    //ORDENAR
    sort(vec.begin(), vec.end(),sortcol);
    for (int i = 0; i<t-1; i++)
    {
        if (vec[i][3] == vec[i+1][3])
        {
            if (vec[i][4] > vec[i+1][4])
            {
                vector <int> &v1 = vec[i];
                vector <int> &v2 = vec[i+1];
                v1.swap(v2); //v[K].swap(v[L])
            }
        }
    }
    
    //PRINT RESULTS
    for (int i = 0; i<t; i++)
    {
        cout << i+1 << " - " << names[vec[i][0]] << " " << vec[i][3] << " ";
        if (vec[i][4] != 0)
        {
            cout << vec[i][4] << endl;
        }
        else
        {
            cout << "-" << endl;
        }
    }
    
    //Esto no va
        cout << endl << endl;
    for (int i = 0; i<t; i++)
    {
        cout << names[i] << endl;
    }
    
    cout << endl << endl;
    
    
    for (int i = 0; i<t; i++)
    {
        for (int j = 0; j<p+3; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }//
}
