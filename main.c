#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ex1.h"

int main(int argc, char **argv) {
    void *ptr = NULL;
    unsigned int KB = 1024;
    unsigned int alignment = 32;

    ptr = aligned_malloc(KB, alignment);
    printf("Allocating uses aligned_malloc(), address returned: %p\n", &ptr);
    ptr = aligned_free(ptr);
};