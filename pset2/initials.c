#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
string s=GetString();
string word = strtok (s," ");
while (word!=NULL)
{

    for (int i=0; i<1; i++)
    {         
        printf ("%c", toupper(word [i]));
        word = strtok (NULL," ");
    }
}    
printf("\n");
}
