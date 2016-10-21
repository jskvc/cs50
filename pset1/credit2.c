#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    printf ("Unesi broj kartice\n");
    string s = GetString();
    int n = atoi (s);
    printf("%d\n", n);
    if (strlen(s) == 15)
    {
        int k=0;
        while (n > 0)
            {
                n = n % 10
                k = k + n;
            }
        printf("%d\n", k);
    }
    else
        {
        printf("pogresan unos\n");
        } 
    
}
