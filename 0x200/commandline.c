#include <stdio.h>

int main(int arg_count, char *arg_list[]){
    int i;
    printf("%d command line arguments are given.\n", arg_count);
    for(i = 0; i < arg_count; i++){
        printf("Argument#%d: %s\n", i, arg_list[i]);
    }
}
