#ifndef _MEMALLOCATOR_H_
#define _MEMALLOCATOR_H_

/*
 *  allocates up to count blocks each of size bytes
 *  Must be called first before other API functions
 *  param:
 *  count: number of blocks in the list
 *  size: size of the data type
 *  return:
 * 
 */
void init(int count,int size);


/*
 *  Returns a pointer to one of the "count" blocks set up by Init()
 *  If no blocks remain returns NULL
 *  param:
 *  
 *  return:
 *  void* points to a free block
 */
void* Allocate(void);


/*
 *  Returns a block allocated by "Allocate()" to the block pool.
 *  param:
 *  *pBlock pointer to block to be released
 *  return:
 */
void Release(void *pBlock);

#endif  // _MEMALLOCATOR_H_