#include<stdio.h>
#include<cs50.h>
#include<stdbool.h>

int main(void)
{ 
    bool ok = false;
    int n=-2;
    while (!ok)
    {
        if (n>0 && n < 24)
        {
            ok =true;
        }
        else 
        {
            printf("Height:"); 
            n = GetInt(); 
        }
    } 
            
        for (int i=1; i<=n; i++)
        {
            {
                for (int k=n-i; k>0; k--)
                {printf (" ");}
                for (int j=1; j<=i; j++)
                {printf("#");}
            }
            printf("#\n");
        }      
    
}
