#include "ex1.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *aligned_malloc(unsigned int size, unsigned int align){
    if(align <= 0 || align&(align-1) != 0 || size == 0) return NULL;
    void *ptr1 = NULL;
    void **ptr2 = NULL;
    int advanced = align - 1 + sizeof(void*);
    if((void*)(ptr1 = malloc(size + advanced)) == NULL) return NULL;
    ptr2 = (void**)(((size_t)(ptr1) + advanced)&~((size_t)align-1));
    ptr2[-1] = ptr1;
    return ptr2;    
}


void *aligned_free(void *ptr){
    void* pAligned = ((void**)pAligned)[-1];
    free(pAligned);
}
