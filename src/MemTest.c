#include <stdio.h>
#include <assert.h>
#include "MemAllocator.h"

#define TEST_SIZE 10

/*
================
* Main
* This is the executable unit test module for Memory Allocator.
* 
* Tests Usage: Remove DNDEBUG from CFLAGS in Makefile and rebuild.
* 
* Author: Ozan Gunaydin
* Oct 2022
================
*/
int main()
{
   // TODO
   // Test initialization
   init(TEST_SIZE, sizeof(int));
   int* pBlock[TEST_SIZE+1];

   /* Executable test case 1
   // allocate an integer and test operation
   *  Asserts:
   *      First returned pBlock is not NULL
   */

   pBlock[0] = Allocate();
   assert(pBlock[0] != NULL);
   Release(pBlock[0]);

   /* Executable test case 2
   *  check edge condition, allocate 11th integer and check
   *  Asserts:
   *      11th returned pBlock is NULL
   *      10th returned pBlock is not NULL
   */
   for(int i=0; i<=TEST_SIZE; i++)
   {
     pBlock[i]= (int*) Allocate();
     
   }
   assert(pBlock[10] == NULL);   //11th block
   assert(pBlock[9] != NULL);   //10th block
   
   /* Executable test case 3
   *  release 10th block and check if 10th can be successfully reallocated
   *  Asserts:
   *      Reallocated 10th block pBlock is not NULL
   */
   Release(pBlock[9]);
   pBlock[9] = Allocate();
   assert(pBlock[9] != NULL);

   printf("Tests successfully completed\n");

   return 0;
}

