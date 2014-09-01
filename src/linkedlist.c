#include <stdlib.h>
#include <string.h>

#include "../include/linkedlist.h"

int linkedList_insert_tail(LinkedList *lList, void *data, int dataSize) {
	if (lList == NULL || data == NULL)
		return -1;
		
	Node *node = (Node *)getMemNode();
	if (node == NULL)
		return -2;

	memcpy(NODE_DATA(node), data, dataSize);

	if (lList->size == 0) {
		node->next = NULL;
		lList->head = lList->tail = node;
	}  else {
		node->next = NULL;
		lList->tail->next = node;
		lList->tail = node;
	}

	lList->size++;

	return 1;
}

int linkedList_insert_head(LinkedList *lList, void *data, int dataSize) {
	if (lList == NULL || data == NULL)
		return -1;

	Node *node = (Node *)getMemNode();
	if (node == NULL)
		return -2;

	memcpy(NODE_DATA(node), data, dataSize);

	if (lList->head == NULL) {
		lList->head = lList->tail = node;
	}  else {
		node->next = lList->head;
		lList->head = node;
	}

	lList->size++;

	return 1;
}

void linkedList_clear(LinkedList *lList) {
	if (lList == NULL)
		return;
	
	Node *ptr, *t;
	
	for (ptr = lList->head; ptr != NULL;) {
		t = ptr->next;
		releaseMemNode((void *)ptr);
		ptr = t;
	}
	
	lList = NULL;
}
