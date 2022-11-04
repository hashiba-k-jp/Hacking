#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_initialized_var = 5;

void function(){
    int stack_var;

    printf("stack_var of function() is at address 0x%08x.\n", &stack_var);
}

int main(){
    int stack_var;
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *)malloc(4);

    // these variables will be stored in DATA SEGMENTS.
    printf("global_initialized_var is at address 0x%08x\n", &global_initialized_var);
    printf("static_initialized_var is at address 0x%08x\n\n", &static_initialized_var);

    // These variables will be stored in BSS SEGMENTS.
    printf("static_var is at address 0x%08x\n", &static_var);
    printf("global_var is at address 0x%08x\n\n", &global_var);

    // This variables will be stored in HEAP SEGMENTS.
    printf("heap_var_ptr is at address 0x%08x\n\n", heap_var_ptr);

    // These variables will be stored in STACK SEGMENTS.
    printf("stack_var is at address 0x%08x\n", stack_var);
    function();

    return 0;
}