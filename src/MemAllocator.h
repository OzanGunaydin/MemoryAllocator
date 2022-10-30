#ifndef _MEMALLOCATOR_H_
#define _MEMALLOCATOR_H_

//Allocate up to "count" blocks each of "size" bytes
//Heap can only be used once during init, and init must be called first.
void init(int,int);

//Returns a pointer to one of the "count" blocks set up by Init(). If no
//blocks remain, return NULL
//Must execute in constant time O(1)
void* Allocate(void);


//Returns a block allocated by "Allocate()" to the block pool. Release()
//may assume pBlock is not NULL and was returned by Allocate().
//Must execute in constant time O(1)
void Release(void*);

#endif  // _MEMALLOCATOR_H_