#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc>2)
    {
        printf("yell\n");
        return 1;
    }
    if (argc<2)
    {
        printf("Usage: /home/jharvard/Dropbox/pset2/caesar <key>");
        return 1;
    }
    string h = argv[1];
    int k = atoi(h);    
    string s=GetString();    
    string word = s;    
    {        
        for (int i=0, n=strlen(word); i<n; i++)
        {         
            int p = word[i];
            int c = p;
            
            if((96<p) && (p<123))
            {
                c = 'a' + (p-97+k)%26;             
            }
            else if ((64<p) && (p<91))
            {
                c = 'A' + (p-65+k)%26;
            }   
            word[i] = c;                              
        } 
        printf("%s\n", word);        
    }     
    return 0;
}
