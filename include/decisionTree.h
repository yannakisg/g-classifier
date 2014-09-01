#ifndef _DECISIONTREE_H

#include "linkedlist.h"
#include "include.h"
#include <stdlib.h>

#define _DECISIONTREE_H

typedef struct DecisionTree_
{
	unsigned short empty;
	/*0 means empty, 1 means with data */
	long double gainSampleW, gainAge, gainJobC, gainEducation, gainYearsOfEdu, gainMarStatus, gainOcc, gainGender, gainRace, gainRship,
		   gainCountry, gainIncome, gainCapitalG, gainCapitalL, gainHpw, sorted[14][2], continuousValues[6];


} DecisionTree;

void initializeTree(DecisionTree *tree); /* initializes the tree, setting empty to 0 */

void createTree(LinkedList *lList, DecisionTree *tree);//creates the decision tree and sorts the gain values that are calculated, in order to be used for classification
void sortList(long double sorted[][2]);//sorts the argument array.
long double computeInfo(unsigned int values[][2], unsigned short length, unsigned int total);
long double computeI(unsigned int greater, unsigned int less, unsigned int total);
void getContinuousValues(LinkedList *lList, DecisionTree *tree, short selection, long double totalInfo);

#endif
