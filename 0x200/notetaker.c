#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "hacking.h"

void usage(char *prog_name, char *filename){
    printf("How to use: %s <the data to be added to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[]){
    int userid, fd;
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "../var/notes");

    if(argc < 2){
        usage(argv[0], datafile);
    }

    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1){
        fatal("In main(), failed to open the file.");
    }
    printf("[DEBUG] file descriptor: %d\n", fd);

    userid = getuid();
    //printf("[DEBUG] userid: %d\n", userid);


    // writing data
    if(write(fd, &userid, 4) == -1){
        fatal("In main(), failed to write userid to the file.");
    }
    write(fd, "\n", 1);

    if(write(fd, buffer, strlen(buffer)) == -1){
        fatal("In main(), failed to write buffer to the file.");
    }
    write(fd, "\n", 1);

    // close the file
    if(close(fd) == -1){
        fatal("In main(), failed to close the file.");
    }

    printf("The memo is completely saved!");
    free(buffer);
    free(datafile);
}