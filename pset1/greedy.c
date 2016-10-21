#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<stdbool.h>

int main(void)
{
    bool ok = false;
    printf ("Hi! How much change is owed?\n");
    float f = GetFloat()*100; 
    while (!ok)
    {
        if (f>0)
        {
            ok =true;
        }
        else 
        {
            printf ("How much change is owed?\n");
            f = GetFloat()*100; 
        }
    }
    
    /*printf ("Hi! How much change is owed?\n");
    float f = GetFloat()*100;*/
    int x = round (f);
    int n = 0;
    /*while (x>100)    
    {
        x = x-100;
         n = n+1;
    }  */ 
    while (x >= 25)
    {
        x = x-25;
        n = n+1;
    }
    while (x >= 10)
    {
        x = x-10;
        n = n+1;
    }
    while (x >= 5)
    {
        x = x-5;
        n = n+1;
    }
    while (x >= 1)
    {
        x = x-1;
        n = n+1;
    }
    printf ("%d\n",n);
}
