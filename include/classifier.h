#ifndef _CLASSIFIER_H

#include "linkedlist.h"
#include "include.h"
#include "decisionTree.h"

#define _CLASSIFIER_H

short classifyMoreThanFifty(DecisionTree *tree, void *data, LinkedList *list, unsigned short i);
//classifies the entry using the arguments as the values for the decision tree. Argument i can be thought as the depth of the tree when the method is called.
unsigned short differentValues(struct LinkedList_ *list);
unsigned short getFirstValue(struct LinkedList_ *list);
unsigned short isGreater(struct LinkedList_ *list);
void getList(struct LinkedList_ *tempList, struct LinkedList_ *list, short number, short selection);
void getLessEqualList(struct LinkedList_ *tempList, struct LinkedList_ *list, long double value, short selection);
void getGreaterList(struct LinkedList_ *tempList, struct LinkedList_ *list, long double value, short selection);
unsigned short compareValues(void *data1, void *data2);


#endif
