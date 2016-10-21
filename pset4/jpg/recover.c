/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>

int main(int argc, char* argv[])
{
    // open memory card file
    FILE* f = fopen("card.raw", "rb");
    char word (
   
    // checkin if file can be opened
    if (f == NULL)
    {
        printf("Error. Could not open memory card.");
        return 1;
    } 
    
    // jpg counter
    int jpgn = 0;
    
    //crating buffer
    uint8_t buffer[512];
    
    // output file
    FILE *new = 0;
    
    // reserving name space
    char jpgname[8];
    
     while (!feof(f))
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {
                if (new != NULL)
                fclose(new);
                //char filename[8];
			    sprintf(jpgname, "%03d.jpg", jpgn);      
			    new = fopen(jpgname, "w");
                jpgn++;
                fwrite(buffer, sizeof(buffer), 1, new);    
            }
            
            else 
            {
                if (jpgn > 0)
                {
                fwrite(buffer, sizeof(buffer), 1, new);
                }
            }
            fread(buffer, 512, 1, f);
        }
            if (jpgn > 0)
            {
                fclose(new);
            }
            fclose(f);
            return 0;         
}
