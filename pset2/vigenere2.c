#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("error %d words in command line\n", argc);
        return 1;
    }
    string h = argv[1];     
    string s=GetString();    
    string word = s;               
        for (int i=0, j=0, n=strlen(word); i<n; i++)
        {         
                int p = word[i];
                int c = p;
                if (h[j]<65)
                {
                int k = h[j];
                }
                else
                {
                int k = tolower(h[j])-97;
                }  
                if((96<p) && (p<123))
                {
                    c = 'a' + (p-97+k)%26;
                    j++;             
                }
                else if ((64<p) && (p<91))
                {
                    c = 'A' + (p-65+k)%26;
                    j++;
                }   
                word[i] = c; 
                if (j>=strlen(h))  
                {
                    j=0;
                }                           
            } 
            printf("%s\n", word);     
    return 0;
}
