#ifndef _IO_H
#define _IO_H

struct LinkedList_;

void getDemographicTrainEntries(int fd, struct LinkedList_ *llist);

void getDemographicTestEntries(int fd, struct LinkedList_ *llist);

void writeEntry(int fd, int result, int counter);

void flushEntries(int fd);
#endif
