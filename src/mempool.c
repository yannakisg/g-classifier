#include <stdlib.h>

#include "../include/mempool.h"

static MPool _memPool = {0};
static MPool *memPool = &_memPool;
static unsigned long blocks = 0;
static unsigned long blockSize = 0;
static unsigned long totalSize = 0;

int allocMem(unsigned long tBlocks, unsigned long bSize) {
	int i;
	MemNode *curMemNode;
	MemPool *_memPool;
	
	_memPool = (MemPool *) calloc(1, sizeof(MemPool));
	if (_memPool == NULL)
		return -1;
	
	_memPool->next = memPool->head;
	memPool->head = _memPool;
	
	blocks = tBlocks;
	blockSize = bSize;
	totalSize = tBlocks * (bSize + sizeof(MemNode));
	memPool->head->size_left = tBlocks;
	memPool->head->memBlock = calloc(1, totalSize);
	if (memPool->head->memBlock == NULL) {
		freeMemory();
		return -2;
	}
	
	for (i = 0; i < tBlocks; i++) {
		curMemNode = (MemNode *) ((unsigned char *)  memPool->head->memBlock + i * (bSize + sizeof(MemNode)));
		
		if (memPool->head->headFreeBlocks == NULL) {
			curMemNode->prev = curMemNode->next = curMemNode;
		} else {
			curMemNode->prev = memPool->head->headFreeBlocks->prev;
			curMemNode->next = memPool->head->headFreeBlocks;
			memPool->head->headFreeBlocks->prev->next = curMemNode;
			memPool->head->headFreeBlocks->prev = curMemNode;
		}			
		memPool->head->headFreeBlocks = curMemNode;
	}
	
	return 0;
}

void* getMemNode() {
	if (memPool == NULL)
		return NULL;
	
	MemPool *iter = memPool->head;
	
	while (iter != NULL && iter->headFreeBlocks == NULL)
		iter = iter->next;
	
	if (iter == NULL) {
		if ( allocMem(blocks, blockSize) < 0 ) {
			return NULL;
		}
		iter = memPool->head;
	}
	
	MemNode *curMemNode = iter->headFreeBlocks;
	
	if (curMemNode->next == curMemNode->prev && curMemNode == curMemNode->next) {
		iter->headFreeBlocks = NULL;
	} else {
		curMemNode->next->prev = curMemNode->prev;
		curMemNode->prev->next = curMemNode->next;
		iter->headFreeBlocks = curMemNode->next;
	}
	
	if (iter->tailAllocBlocks == NULL) {
		curMemNode->next = curMemNode->prev = curMemNode;
		iter->tailAllocBlocks = curMemNode;
	} else {
		curMemNode->next = iter->tailAllocBlocks;
		curMemNode->prev = iter->tailAllocBlocks->prev;
		iter->tailAllocBlocks->prev->next = curMemNode;
		iter->tailAllocBlocks->prev = curMemNode;
	}
	
	iter->size_left--;
	
	return (void *) ((unsigned char *) curMemNode + sizeof(MemNode));
}


void releaseMemNode(void *node) {
	
	if (node == NULL || memPool == NULL)
		return;
	
	MemPool *iter = memPool->head;
	MemNode *curMemNode;
	
	curMemNode = (MemNode *) ((unsigned char *) node - sizeof(MemNode));
	
	while (iter != NULL && (iter->memBlock >= node || node >= (void *) ((unsigned char *) iter->memBlock + totalSize)))
		iter = iter->next;
	
	if (curMemNode->next == curMemNode->prev && curMemNode->next == curMemNode) {
		iter->tailAllocBlocks = NULL;
	} else if (curMemNode == iter->tailAllocBlocks) {
		curMemNode->next->prev = curMemNode->prev;
		curMemNode->prev->next = curMemNode->next;
		iter->tailAllocBlocks = iter->tailAllocBlocks->prev;
	} else {
		curMemNode->next->prev = curMemNode->prev;
		curMemNode->prev->next = curMemNode->next;
	}
	
	if (iter->headFreeBlocks == NULL) {
		curMemNode->next = curMemNode->prev = curMemNode;
		iter->headFreeBlocks = curMemNode;
	} else {
		curMemNode->next = iter->headFreeBlocks;
		curMemNode->prev = iter->headFreeBlocks->prev;
		iter->headFreeBlocks->prev->next = curMemNode;
		iter->headFreeBlocks->prev = curMemNode;
	}
	
	
	iter->size_left++;
	
}

void freeMemory() {
	MemPool *iter = memPool->head;
	MemPool *temp;
	
	while (iter != NULL) {
		temp = iter;
		iter = iter->next;
		
		free(temp->memBlock);
		free(temp);
	}
	
	memPool = NULL;
}
