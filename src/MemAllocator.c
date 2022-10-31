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
#include <stdio.h>
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
//always points to next free block, so allocation can always be achieved in O(1) time
static Block  *allocPointer = NULL;



//--------------------------
//PUBLIC API FUNCTIONS
//

//Allocate up to "count" blocks each of "size" bytes
//Heap can only be used once during init, and init must be called first.
void init(int count, int size)
{
    //cast return pointer to Block type and assign as first block
    allocPointer = (Block *) malloc(count*size);
 
    //Create the list and links
   Block *currBlock = allocPointer;
  
   for (int i=0; i < count-1; ++i) {
     currBlock->next = (Block *)(currBlock + size);
     currBlock = currBlock->next;
   }
 
   //end of list
   currBlock->next = NULL;
 
}

//Returns a pointer to one of the "count" blocks set up by Init(). If no
//blocks remain, return NULL
//Must execute in constant time O(1)
void *Allocate(void)
{
    //TODO: allocation
    if(allocPointer==NULL)
    {
        printf("No Pool has been initialized or the pool is fully allocated");
        return NULL;
    }
    
}

//Returns a block allocated by "Allocate()" to the block pool. Release()
//may assume pBlock is not NULL and was returned by Allocate().
//Must execute in constant time O(1)
void Release(void *pBlock)
{
    //check if the pointer is null, return if nothing is there to be released
    //TODO: deallocation
}
