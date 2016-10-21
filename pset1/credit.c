#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int k = 0;
    int l = 0;
    printf ("Unesi broj kartice\n");
    string s= GetString();
    long long int n= atoll (s);  
    printf("%lld\n", n);
    if (strlen(s) == 15)
    {
        long long int x=n/10;
        while (x > 0)
        {
            int p = x%10;
            x = x/100;
            int a = 2*p;
            if (a>=10)
                {
                    a=a/10+a%10;
                }
            k = k + a;
        }
        printf("%d\n", k);
        long long int y=n;
        while (y>0)
        {
            int t= y%10;
            y=y/100;
            l = l + t;                    
        }
    int m = k+l;
    printf("%d\n", l);
    printf("%d\n", m);
    }
    else
    {
        printf("pogresan unos\n");
    } 
}
