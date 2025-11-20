/*------------------------------------------------------
* Filename: sort.c
* Description: implement generic bubble sort function
* Author: Golan Ziv
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "../DynamicScanf/my_dyn_scanf.h"

#define ARRAY_SIZE 5

/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - swap cells in void* array 
*
* Parameters –  [INOUT arr - array of void pointers] 
*		        [IN length – amount of elements in the array]
*		        [IN i – index in array]
*		        [IN j – index in array]
*
* Return Values - void
*
* Author - Golan
-------------------------------------------------------*/
void swap(void **arr, size_t length, size_t i, size_t j){
    void * temp = NULL;
    if(i < 0 || j < 0 || i >= length || j >= length || i == j || !arr)
        return;

    if(!arr[i] || !arr[j]) return;
    
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
} 


/*------------------------------------------------------
* Function Name - sort
*
* Function Purpose - sort an array by given compare function 
*
* Parameters –  [INOUT arr - array of void pointers] 
*		        [IN length – amount of elements in the array]
*		        [IN cmp_ptr – a pointer to a comparing function]
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void sort(void **arr, size_t length, int (*cmp_ptr)(void *, void *)){    
    if(length < 2 || !arr || !cmp_ptr) return;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(cmp_ptr(arr[j] , arr[j+1]) > 0)
                swap(arr, length, j, j+1);
        }
    }

}

/*------------------------------------------------------
* Function Name - alpha_cmp
*
* Function Purpose - compare elements by alphabatically order 
*
* Parameters –  [IN x - pointer to void value] 
*		        [IN y - pointer to void value]
*
* Return Values - positive number if x is later in alphabet order than y and vice versa. will return 0 if equal ("a" == "A")
*
* Author - Golan Ziv
-------------------------------------------------------*/
int alpha_cmp(void *x, void *y){
    char *s1 = (char *) x;
    char *s2 = (char *) y;
    
    return _stricmp(s1, s2); // used to be case insensiative since strcmp will say "a" > "Z" but _stricmp will say "Z" > "a"
}


/*------------------------------------------------------
* Function Name - len_cmp
*
* Function Purpose - compare elements by length order 
*
* Parameters –  [IN x - pointer to void value] 
*		        [IN y - pointer to void value]
*
* Return Values - positive number if x is longer then y and vice versa. will return 0 if same length
*
* Author - Golan Ziv
-------------------------------------------------------*/
int len_cmp(void *x, void *y){
    size_t lx = strlen((char *) x);
    size_t ly = strlen((char *) y);

    if(lx == ly) return 0;
    else if(lx > ly) return 1;
    else return -1;
}

/*------------------------------------------------------
* Function Name - print_arr
*
* Function Purpose - print an array of char *
*
* Parameters –  [IN arr - array of strings] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void print_arr(char *arr[ARRAY_SIZE]){
    char comma;
    for(int i = 0; i < ARRAY_SIZE; i++){
        comma = (i == ARRAY_SIZE - 1) ? '\n' : ',';
        printf("%s%c", arr[i], comma);
    }
}

/*------------------------------------------------------
* Function Name - alpha_cmp
*
* Function Purpose - compare elements by alphabatically order 
*
*
* Return Values - 0 for success, 1 for failure
*
* Author - Golan Ziv
-------------------------------------------------------*/
int main(){

    char * arr[ARRAY_SIZE];
    char * temp = NULL;
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("enter string %d: ", i+1);
        temp = dyn_scanf();
        if(!temp){
            printf("scanf failed!");
            return 1;
        }
        arr[i] = strdup(temp);
        free(temp);
    }
    

    printf("\nSorted in alphabetical order:\n");
    sort((void **)arr, ARRAY_SIZE, alpha_cmp);
    print_arr(arr);
    
    printf("\nSorted in length order:\n");
    sort((void **)arr, ARRAY_SIZE, len_cmp);
    print_arr(arr);

    for(int i = 0; i < ARRAY_SIZE; i++)
        free(arr[i]);

    return 0;
}