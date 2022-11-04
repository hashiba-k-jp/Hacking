#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(unsigned int);

int main(int argc, char *argv[]){
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if(argc < 2){
        mem_size = 50;
    }else{
        mem_size = atoi(argv[1]);
    }

    printf("\t[+]Allocate %d bytes from the heap and assign the first address to char_ptr.\n", mem_size);
    char_ptr = (char *) errorchecked_malloc(mem_size);

    strcpy(char_ptr, "This will be copied to heap.");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);
    printf("\t[+]Allocate 12 bytes from the heap and assign the first address to int_ptr.\n");
    int_ptr = (int *) errorchecked_malloc(12);

    *int_ptr = 31337;
    printf("int_ptr  (%p) --> %d\n", int_ptr, *int_ptr);

    printf("\t[-]Free up heap memory directed by char_ptr.\n");
    free(char_ptr);

    printf("\t[+]Reallocate 15 bytes from the heap and assign the first address to char_ptr.\n");
    char_ptr = (char *) errorchecked_malloc(15);

    strcpy(char_ptr, "NEW MEMORY");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    printf("\t[-]Free up heap memory of int_ptr.\n");
    free(int_ptr);
    printf("\t[-]Free up heap memory of char_ptr.\n");
    free(char_ptr);

}

void *errorchecked_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL){
        fprintf(stderr, "ERROR: Failed to allocate heap memory.\n");
        exit(-1);
    }
    return ptr;
}