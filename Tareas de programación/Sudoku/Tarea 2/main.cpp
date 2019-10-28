//
//  main.cpp
//  Tarea 2
//
//  Created by Layla Tame on 1/16/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int sud[9][9];
    bool outp = true;
    
    //Input Sudoku
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> sud[i][j];
        }
    }
    
    //Check Rows
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=i+1;k<9;k++)
            {
                if(sud[j][i] == sud[j][k])
                {
                    outp = false;
                    break;
                }
            }
        }
    }
    
    //Check Columns
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=i+1;k<9;k++)
            {
                if(sud[i][j] == sud[k][j])
                {
                    outp = false;
                    break;
                }
            }
        }
    }
    
    //3X3 checker
    for(int a=0;a<9;a+=3)
    {
        for(int b=0;b<9;b+=3)
        {
            for(int m=a; m<a+2; m++)
            {
                for(int n=b; n<b+3; n++)
                {
                    for(int i=a; i<a+3; i++)
                    {
                        for(int j=b; j<b+3; j++)
                        {
                            if(i!=m && j!=n)
                            {
                                if(sud[m][n] == sud[i][j])
                                {
                                    outp = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //Print Result
    if (outp == true)
    {
        cout << "YES";
    }
    
    if (outp == false)
    {
        cout << "NO";
    }
}
