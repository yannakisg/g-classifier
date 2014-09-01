#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/include.h"
#include "../include/linkedlist.h"
#include "../include/decisionTree.h"
#include "../include/mempool.h"

#define TRAINFILE "data/train.data"
#define TESTFILE "data/test.data"
#define DESTFILE "data/results.txt"

int main(int argc, char *argv[])
{
	int fd;
	int result;
	int counter = 0;
	Node *iter;
	LinkedList _trainList = {0};
	LinkedList *trainList = &_trainList;
	LinkedList _testList = {0};
	LinkedList *testList = &_testList;
	DecisionTree decTree;
		
	allocMem(50000, sizeof(Demographic) + sizeof(void *));
	
	printf("Reading train.data\n");
	fd = open(TRAINFILE, O_RDONLY);
	getDemographicTrainEntries(fd, trainList);
	
	printf("Reading test.data\n");
	fd = open(TESTFILE, O_RDONLY);
	getDemographicTestEntries(fd, testList);
	
	fd = open(DESTFILE, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
	
	createTree(trainList, &decTree);
	
	for (iter = testList->head; iter != NULL; iter = iter->next )
	{
		result = classifyMoreThanFifty(&decTree, NODE_DATA(iter), trainList, 0);
		writeEntry(fd, result, counter);
		counter++;
	}
	
	flushEntries(fd);
	linkedList_clear(trainList);
	linkedList_clear(testList);
	freeMemory();
	
	printf("Process Complete!");
	return 0;
}
