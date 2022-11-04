#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char buffer_one[8], buffer_two[8];

    strcpy(buffer_one, "one");
    strcpy(buffer_two, "two");
    int value = 5;


    printf("[prev] buffer_two is at %p, and its value is \'%s\'.\n", buffer_two, buffer_two);
    printf("[prev] buffer_one is at %p, and its value is \'%s\'.\n", buffer_one, buffer_one);
    printf("[prev] value      is at %p, and its value is %d (0x%08x).\n", &value, value, value);

    printf("\n[STRCPY] Copy %d bytes to buffer_two.\n\n", strlen(argv[1]));
    strcpy(buffer_two, argv[1]); /* 最初の引数をbuffer_twoにコピーする */

    printf("[next] buffer_two is at %p, and its value is \'%s\'.\n", buffer_two, buffer_two);
    printf("[next] buffer_one is at %p, and its value is \'%s\'.\n", buffer_one, buffer_one);
    printf("[next] value      is at %p, and its value is %d (0x%08x).\n", &value, value, value);

}