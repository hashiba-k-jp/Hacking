#include <stdio.h>

int main(){
    int int_var = 5;
    int *int_ptr;

    int_ptr = &int_var;

    printf("int_ptr = 0x%08x\n", int_ptr);
    printf("&int_ptr = 0x%08x\n", &int_ptr);
    printf("*int_ptr = 0x%08x\n\n", *int_ptr);

    printf("int_var stored : 0x%08x , its value : %d\n", &int_var, int_var);
    printf("int_ptr stored : 0x%08x , its value : 0x%08x, pointing value : %d\n", &int_ptr, int_ptr, *int_ptr);

    return 0;
}