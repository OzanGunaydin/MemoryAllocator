#include <stdio.h>
#include <assert.h>
#include "MemAllocator.h"

#define TEST_SIZE   10
#define TEST_DTYPE  int     //int, char, float etc

/*
================
* Main
* This is the executable unit test module for Memory Allocator.
* 
* Tests Usage: Remove DNDEBUG from CFLAGS in Makefile and rebuild.
*              Configure the tests using TEST_SIZE and TEST_DTYPE macros
* 
* Author: Ozan Gunaydin
* Oct 2022
================
*/
int main()
{
   // Test initialization
   init(TEST_SIZE, sizeof(TEST_DTYPE));
   // Array to keep track of returned pointers
   TEST_DTYPE* pBlock[TEST_SIZE+1];
   
   /* Executable test case 1
   *  allocate an integer and test operation
   *  Asserts:
   *      First returned pBlock is not NULL
   *      Reallocated pointer points to the address which was released previoulsy
   */

   pBlock[0] = Allocate();
   assert(pBlock[0] != NULL);
   TEST_DTYPE* previousAddress = pBlock[0];
   Release(pBlock[0]);
   TEST_DTYPE* reassignedAddress = Allocate();
   assert(reassignedAddress == previousAddress);
   Release(reassignedAddress);

   /* Executable test case 2
   *  check edge condition, allocate last block +1 and check
   *  Asserts:
   *      out of bounds returned pBlock is NULL
   *      last block returned pBlock is not NULL
   *      Check if different between the first and last address returned equals to 
   *      (sizeof(TEST_DTYPE)+sizeof(TEST_DTYPE*)) * (TESTSIZE-1)
   */
   for(int i=0; i<=TEST_SIZE; i++)
   {
     pBlock[i]= (TEST_DTYPE*) Allocate();
   }
   assert(pBlock[TEST_SIZE] == NULL);     //out of bounds
   assert(pBlock[TEST_SIZE-1] != NULL);   //last block

  //compute difference in bytes total to be allocated
  unsigned long computedDiffinAddr = (unsigned long)(TEST_SIZE-1) * (sizeof(TEST_DTYPE) + sizeof(TEST_DTYPE*));
  //compute real difference in addresses returned by the API
  unsigned long realDiffinAddr = ((unsigned long) (pBlock[TEST_SIZE-1]) - (unsigned long) (pBlock[0]));
  assert(realDiffinAddr == computedDiffinAddr );

   /* Executable test case 3
   *  release last block and check if it can be successfully reallocated
   *  Asserts:
   *      Reallocated last block pBlock is not NULL
   *      Reallocated last block pBlock address is the same one which has release before

   */
   previousAddress =pBlock[TEST_SIZE-1];
   Release(pBlock[TEST_SIZE-1]);
   pBlock[TEST_SIZE-1] = Allocate();
   assert((pBlock[TEST_SIZE-1] != NULL) && (pBlock[TEST_SIZE-1] == previousAddress));
   
   printf("Tests successfully completed\n");

   return 0;
}

