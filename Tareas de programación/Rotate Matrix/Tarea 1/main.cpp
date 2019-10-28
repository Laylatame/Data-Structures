//
//  main.cpp
//  Tarea 1
//
//  Created by Layla Tame on 1/15/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int spin;
    int mat[4][4], newmat[4][4];
    
    //Input
    cin >> spin;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    //Negative spins
    if (spin < 0)
    {
        if (spin % 4 == 0 || spin % 4 == -2)
        {
            spin = abs(spin);
        }
        
        if (spin % 4 == -1)
        {
            spin = 3;
        }
        
        if (spin % 4 == -3)
        {
            spin = 1;
        }
    }
    
    //Case 0
    if (spin % 4 == 0)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                newmat[i][j] = mat[i][j];
            }
        }
    }
    
    //Case 1
    if (spin % 4 == 1)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                newmat[j][i] = mat[3-i][j];
            }
        }
    }
    
    //Case 2
    if (spin % 4 == 2)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                newmat[j][i] = mat[3-j][3-i];
            }
        }
    }
    
    //Case 3
    if (spin % 4 == 3)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                newmat[j][i] = mat[i][3-j];
            }
        }
    }
    
    //PRINT
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << newmat[i][j];
            if(j<3)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
