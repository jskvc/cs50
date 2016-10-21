/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    // TODO: implement a searching algorithm
    int f = 0; 
    int l = n-1;
    int m = (f+l)/2;
    int p = 0;
    while (f < l)
        {
            if(array[m] == value)
            {
                return true;
                p=1;
            }
            else if (value < array[m])
            {
                l = m;
            }
            else if (value > array[m])
            {
            f = m;
            }
            m = (f+l)/2;
        }
    return false;
}      

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // TODO: implement an O(n) sorting algorithm
    int flag = 1;
       
    for (int k=0; k<=n-1; k++)
    {
        flag = 0;
        for (int i=0; i<n-1; i++)
        {
            int x=values[i];
            if (x>values[i+1])
                {
                    values[i]=values[i+1];
                    values[i+1]=x;  
                    flag=1;          
                }              
        }  
    }
   return;
}
