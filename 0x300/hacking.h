void fatal(char *message){
    char *error_message[100];

    strcpy(error_message, "[!!] Fatal error:");
    srtncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL){
        fatal("Failed to allocate memory in ec_malloc().");
    }
    return ptr;
}