/*
================
* Memory Allocator
* 
* Initializes a requested number of blocks from heap
* and maintaines these blocks via Allocate and Release calls
*
* init function must be called first.
*
* Author: Ozan Gunaydin
* Oct 2022
===============
*/

#include <stdlib.h>
#include "MemAllocator.h"

//-----
//LOCAL DATA
//

typedef struct Block {
  /**
   * *next containts the address of next block in a list
   */
  struct Block *next;
} Block;

//main pointer to keep track of allocation
static Block  *allocPointer = NULL;



//--------------------------
//PUBLIC API FUNCTIONS
//

//Allocate up to "count" blocks each of "size" bytes
//Heap can only be used once during init, and init must be called first.
void init(int count, int size)
{
    void *memPool =  malloc(size*count);
}

//Returns a pointer to one of the "count" blocks set up by Init(). If no
//blocks remain, return NULL
//Must execute in constant time O(1)
void *Allocate(void)
{
    //TODO: allocation
    return NULL;
}

//Returns a block allocated by "Allocate()" to the block pool. Release()
//may assume pBlock is not NULL and was returned by Allocate().
//Must execute in constant time O(1)
void Release(void *pBlock)
{
    //TODO: deallocation
}
