#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - take user string input, and dynamiccaly allocate more memory
*                    if needed, returning a pointer to the allocated memory address.
*                    ensuring null termination.  
*
* Return Values - address to char block, or NULL if somthing failed.
*
* Author - Golan Ziv
-------------------------------------------------------*/
char *dyn_scanf(void){
    char *str = NULL, *temp = NULL;
    int c; 
    size_t length = 0; 
    size_t init_capacity = 1000;
    
    str = malloc(init_capacity);
    if(!str)
        return NULL;

    while((c = getchar()) != EOF && c != '\n' && length < SIZE_MAX - 1){
        length++; // it cant overflow, the max chars are SIZE_MAX - 1 (not including '\0')
        if(length > init_capacity){
            temp = realloc(str, length);
            if(!temp){ 
                if (str) free(str);
                return NULL; // realloc failed
            }
            str = temp;
        }

        str[length - 1] = c;
    }

    length++;
    temp = realloc(str, length); // for '\0'

    if(!temp){ 
        if (str) free(str);
        return NULL; // realloc failed
    }

    str = temp;
    str[length-1] = '\0';

    return str;
  
}