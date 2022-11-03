#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
}

int main(int argc, char *argv[]){
    int i, count;

    count = atoi(argv[2]);
    printf("Repeat %d times.\n", count);

    for(i = 0; i < count; i++){
        printf("%3d - %s\n", i, argv[1]);
    }

    return 0;
}

// This program will CAUSE ERROR with only 1 argument except for the filename.
// like...
// % ./convert2 <sometext>