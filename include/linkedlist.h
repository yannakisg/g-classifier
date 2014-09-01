#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct Node_{
	struct Node_ *next;
}Node;

typedef struct LinkedList_ {
	unsigned int size;
	void ( *destroy) (void *ptr);
	Node *head;
	Node *tail;
}LinkedList;


int linkedList_insert_tail(LinkedList *lList, void *data, int dataSize);
int linkedList_insert_head(LinkedList *lList, void *data, int dataSize);
void linkedList_clear(LinkedList *lList);

#define LLIST_SIZE (list) ((list)->size)
#define NODE_DATA(node) ( ((unsigned char *) node) + sizeof(void *) )
#define LLIST_IS_HEAD (list, node) ( (list)->head == (node) ? 1 : 0 )
#define LLIST_IS_TAIL (list, node) ( (list)->tail == (node) ? 1 : 0 )
#define LLIST_HEAD (list) ((list)->head)
#define LLIST_TAIL (list) ((list)->tail)

#endif
