Memory Allocator and tests 

------------
DESCRIPTION:
Allocates a pool of memory blocks as requested from the user code and maintains this pool.
Uses the heap only once during initialization.
All allocations and releases are constant time O(1)


------------
USAGE:
#include <MemAllocator.h> in your source file.
1) Call init first : init(int count,int size)
2) Allocate memory blocks using Allocate(), returns a pointer to one of the blocks
3) Release memory blocks using Release(void *pBlock), pass a pointer to the block to be released

------------
TEST:
Unit tests are provided in MemTest.c file. To enable tests remove NDEBUG flag from the MakeFile CFLAGS.
Configure the tests in Memtest.c using 2 macros:
#define TEST_SIZE 10
#define TEST_DTYPE int 




