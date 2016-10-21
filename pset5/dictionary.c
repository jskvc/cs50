
/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"
//#include "hashtable2.h"

FILE *f= NULL;
int k = 0;
const int TABLE_SIZE = 65536;

struct node {
       char *data;
       struct node *next;
};

struct node *hashtable[TABLE_SIZE];
struct node *hashtable_alloc(void);
unsigned int hasha(const char *string)
{
	unsigned int num = 0;
	while(*string++ != '\0')
			num += *string;
    return num % TABLE_SIZE;	
}
bool hashtable_check(const char *word)
{
    char data[50];
	int i=0;    
    for(i = 0; word[i]; i++){
      data[i] = tolower(word[i]);
    }  
    data[i] = '\0';
    
    unsigned int x = hasha(data);
    struct node *tmp;
	for(tmp = hashtable[x]; tmp != NULL; tmp = tmp->next) 
	{
	   if(tmp->data != 0) 
	   { 
			if(0==strcmp(data, tmp->data))
			    { 
			    return true;
			    }
        }
	}
	return false;
}
void hashtable_add(char *word)
{
    char data[50];
	int i=0;    
    for(i = 0; word[i]; i++){
      data[i] = tolower(word[i]);
    }  
    data[i] = '\0';
   	unsigned int x = hasha(data);
	struct node *tmp;
	for(tmp = hashtable[x]; tmp != NULL; tmp = tmp->next)
    {
		if(tmp->data != 0) 
		{ 
			if(!strcmp(data, tmp->data))
			     return;
		}
	}
   	for(tmp = hashtable[x]; tmp->next != NULL; tmp = tmp->next);
	;
        if(tmp->next == NULL) 
	    { 
		         tmp->next = hashtable_alloc();
		         tmp = tmp->next;
		         tmp->data = malloc (strlen (data) + 1);
		         strcpy (tmp->data, data);
		         tmp->next = NULL;
	    } 
	    else
		    exit(EXIT_FAILURE); 
}

void hashtable_init(void)
{
	int x;

	for(x = 0; x <TABLE_SIZE; x++) 
	{
	      hashtable[x] = hashtable_alloc();
	}

}

struct node *hashtable_alloc(void)
{
	struct node *tmp = calloc(1, sizeof(struct node));
	if(tmp == NULL) 
	{
	       fprintf(stderr, "Error: calloc()\n");
	       exit(EXIT_FAILURE);
	}
	
	tmp->next = NULL;	

	return tmp;       
}

void hashtable_free(void)
{
	struct node *tmp;
	struct node *fwd;
	int x;

	for(x = 0; x < TABLE_SIZE; x++) 
	{

	      tmp = hashtable[x];
	      while(tmp != NULL) 
	      {
	            fwd = tmp->next;
		        free(tmp->data);
		        free(tmp);
		        tmp = fwd;
	      }
	}
}

/*
 *  Returns true if word is in dictionary else false.
 */
 
bool check(const char* word)
{
    return hashtable_check(word);
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{       
        f = fopen(dictionary, "r");
        char words[50];
        if (f == NULL)
        {
            return false;
        }
        
        hashtable_init();
        while (fgets(words, 100, f))
        //while(fscanf(f, "%s", words)!=EOF)//
        {
             hashtable_add(words);  
             k++;        
        }         
                
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
 
unsigned int size(void)
{
   if(k==0)
   {   
        char words[50];
       rewind(f);       
        while (fscanf(f, "%s", words)!=EOF)
        {
                k++;           
        } 
    }
    
    return k;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 
bool unload(void)
{
    return 0 == fclose (f);
    //hashtable_free();
    
    for(int x = 0; x <TABLE_SIZE; x++) 
	{
	      hashtable_free();
	}
}




