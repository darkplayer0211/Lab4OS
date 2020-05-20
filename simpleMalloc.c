#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *simple_malloc (size_t size)
{
    void *p;
    p = sbrk (0) ;
    /* if(sbrk fails, we return NULL*/
    if (sbrk(size) == (void*)-1){
        return NULL;
    }
    return p;
}

int main(int argc, char **argv) {
    void *ptr = NULL;
    size_t maxMB = 1024*1024;
    for(int i = 0; i < 2; i++){
        ptr = malloc(maxMB);
        printf("%p and maxMB %zi\n", &ptr, maxMB);
        maxMB += maxMB;
    }
}