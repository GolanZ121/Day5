/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: implemnting a dyn_scanf function to read user string input 
*              with dynamic memory allocation
* Author: Golan Ziv
-------------------------------------------------------*/

#include "my_dyn_scanf.h"

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - read string using dyn_scanf and print result 
*
* Return Values - 0 for success, 1 for failure
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){
    char *input = NULL;

    printf("Enter string: ");

    input = dyn_scanf();
    if(!input){
        printf("Error while dyn_scanf!");
        return 1;
    }

    printf("\nYou Entered: '%s'", input);

    free(input);

    return 0;

}