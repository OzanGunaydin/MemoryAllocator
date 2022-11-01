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

//Block structure keeps track of the list
typedef struct Block {
  /**
   * *next containts the address of next block in a list
   */
  struct Block *next;
} Block;

//main pointer to keep track of allocation
//always points to next free block, so allocation can always be achieved in O(1) time
static Block *allocPointer = NULL;


//--------------------------
//PUBLIC API FUNCTIONS
//


/*
 * Function:  init
 * --------------------
 * allocates up to count blocks each of size bytes
 *  
 *  count: number of blocks in the list
 *  size: size of the data type
 *  
 */
void init(int count, int size)
{

    //Allocate enough memory from heap to accommodate space for data and list pointers
    allocPointer = (void *) malloc(count*size + count*sizeof(Block*));

    //Create the list and links
    Block *currBlock = allocPointer;
     
    //Chain the list
    for (int i=0; i < count-1; ++i) {
     currBlock->next = (Block *)((char*)currBlock + size + sizeof(Block*));
     currBlock = currBlock->next;
    }
    //end of list
    currBlock->next= NULL;
           
}


/*
 * Function:  Allocate
 * --------------------
 *  returns a pointer to one of the blocks set by Init().
 *  If no blocks remain, returns NULL
 *  Executes in constant time O(1) since allocpointer always points to
 *  next free block
 */
void *Allocate(void)
{
    if(allocPointer==NULL)
    {
        return NULL;
    }
    Block *currBlock = allocPointer;
    allocPointer = currBlock->next;
    return currBlock;
    
}


/*
 * Function:  Release
 * --------------------
 *  returns a block allocated by Allocate() back to the block pool.
 *  Executes in constant time O(1) since allocpointer always points to
 *  next free block
 */
void Release(void *pBlock)
{
    //check if the pointer is null, return if nothing is there to be released
    if(pBlock==NULL)
    {
        printf("There is nothing to release\n");
        return;
    }

     Block *currBlock = pBlock;
     currBlock->next  =  allocPointer;
     allocPointer  = currBlock;
  
}
