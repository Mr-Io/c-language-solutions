#include "mystdlib.h"

#include <unistd.h>
#include <stdio.h>

/* 8 bit aligned header */
union header{
    struct{
        union header *next;
        long int size; 
    }s; 
    long double foo; /* never used, required for 8 byte alignment */ 
};
typedef union header Header;

/* useless 0 size block to avoid emptying completely the linked list */
static Header size0 = {.s = {&size0, 0}}; 
 /* circular ordered linked list of free memory blocks */
static Header *freep = &size0;

/*
* _morecore - increment free linked list with a new block
* @nunits: size of the block in multiples of [sizeof(HEADER)] bytes
*
* add a new block of size [max(nunits,NALLOC) * sizeof(HEADER)] bytes
* to the free linked list. The new block is constructed with memory 
* requested from the OS with sbrk() system call. It return -1 on error
* and 0 on success.
*/
static int _morecore(int nunits){
    nunits = (nunits < NALLOC)? NALLOC : nunits;
    /* request memory to the OS*/
    Header *p = (Header *) sbrk(nunits * sizeof(Header));
    if ((void *)p == (void *)-1)
        return -1;
    /* add to the free memory linked list */
    p->s.size = nunits;
    free(p+1);
    return 0;
}

/*
* free - insert a memory block in free linked list 
* @puser: pointer to memory block (user area)
*
* The proper position to add the block is found by finding the 
* logical previous and next blocks. If the block is adjacent to 
* either the previous or next block it is coalesced into a single 
* bigger one before inserting it.
*/
void free(void *puser){
    /* move pointer to begining of the block */
    Header *p = (Header *)puser;
    p -= 1;
    /* size check */
    if (p->s.size <= 0){
        fprintf(stderr, 
                "free() error: block of size %ld\n", 
                p->s.size);
        return;
    }
    /* find where to add the block */
    Header *prev, *next ;
    for (prev = freep ; ; prev = prev->s.next){
        next = prev->s.next;
        /* between 2 blocks  */ 
        if (p > prev && p < next )      
            break;
        /* at one end of the list*/ 
        if (next <= prev &&  (p > prev || p < next))  
            break;
    }
    /* insert the block */
    /* try to combine p and next*/
    if (p + p->s.size == next){
        p->s.size += next->s.size;
        p->s.next = next->s.next;
    }else{
        p->s.next = next;
    }
    /* once p and next are done try to combine prev with p */
    if (prev + prev->s.size == p){
        prev->s.size += p->s.size;
        prev->s.next = p->s.next;
    }else{
        prev->s.next = p;
    }
    /* update freep is mandatory cuz maybe we deleted the block
    *  currently pointed by freep */
    freep = prev;
}


/*
* malloc - provides the user of at least nbytes of continues memory
* @nbytes: pointer to memory block (user area)
*
* It first find an appropriate block from the free linked list to 
* delete. If no block is found then the free list is incremented
* by calling _morecore(), and the process is repeated. 
* It then removes the block from the linked list if it has the 
* same size as the memory asked or shrunk it otherwise. 
*/
void *malloc(long unsigned int nbytes)
{
    if (nbytes > MAXALLOC)
        return NULL;
    int nunit = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
    /* run through linked list of free memory until a free block 
    *  with enough memory is reached */
    Header *p, *prevp;
    for(prevp = freep, p = prevp->s.next; ; prevp = p, p = p->s.next){
        if (p->s.size >= nunit){
            break;
        }
        /* whole iteration -> allocate more and start again*/
        if (p == freep){
            if(_morecore(nunit) == -1)
                return NULL;
            /* block pointed by p may have been removed so reset */
            p = freep; 
        }
    }
    /* remove chunk from linked list and update freep */
    if (p->s.size == nunit){
        prevp->s.next = p->s.next;
    }else{
        p->s.size -= nunit;
        p += p->s.size;
        p->s.size = nunit;
    }
    /* update freep: next search begin, also freep block may 
    have been removed if p selected was freep and exact size */
    freep = prevp;

    return (void *) (p + 1);
}


void *calloc(long unsigned int n, long unsigned int size)
{
    char *p;
    long unsigned tsize = n*size;
    if ((p = (char *)malloc(tsize)) == NULL)
        return NULL;    
    
    long unsigned int i;
    for (i = 0; i < tsize; i++)
        p[i] = 0;
    return p;
}


void bfree(void *p, long int n)
{
    long int nunits;
    Header *hp;

    nunits = n / sizeof(Header);
    if (nunits <= 0)
        return;

    hp = (Header *)p;
    hp->s.size = n;
    free(hp + 1);
}