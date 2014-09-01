#ifndef _MEMPOOL_H_
#define _MEMPOOL_H_

typedef struct _MemNode {
	struct _MemNode *next;
	struct _MemNode *prev;
}MemNode;

typedef struct _MemPool {
	struct _MemPool *next;
	struct _MemNode *tailAllocBlocks;
	struct _MemNode *headFreeBlocks;
	void *memBlock;
	unsigned long size_left;
}MemPool;

typedef struct _MPool {
	MemPool *head;
} MPool;

int allocMem(unsigned long tBlocks, unsigned long bSize);

void *getMemNode();

void releaseMemNode(void *node);

void freeMemory();

#endif
