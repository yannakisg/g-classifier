#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/io.h"
#include "../include/linkedlist.h"
#include "../include/include.h"


#define BUFSIZE 16384
#define CRLF "\r\n"
#define GREATER ">50Κ"
#define LESS	"<=50K"

static unsigned char buffer[BUFSIZE];
static unsigned char numberStr[11];
static short totalSize = 0;

static int compare(const void *key1, const void *key2)
{
	int k1 = *((unsigned int *) key1);
	int k2 = *((unsigned int *) key2);

	if (k1 > k2)
		return 1;
	else if (k1 == k2)
		return 0;
	else
		return -1;
}

static unsigned int elf_hash(void *key, size_t len)
{
	unsigned char *p = key;
	unsigned int h = 0, g;
	int i;

	for (i = 0; i < len; i++)
	{
		h = (h << 4) + p[i];
		g = h & 0xF0000000L;

		if (g != 0)
			h ^= g >> 24;

		h &= ~g;
	}

	return h;
}

static unsigned int binarySearch(void *sorted, void *target, unsigned int size,
		unsigned int dataSize,
		int(*compare)(const void *key1, const void *key2))
{
	if (sorted == NULL || target == NULL || size == 0 || dataSize == 0
			|| compare == NULL)
	{
		return -1;
	}

	int l, r, m, res;

	l = 0;
	r = size - 1;

	while (l <= r)
	{
		m = (l + r) / 2;

		if ((res = compare(((char *) sorted + (dataSize * m)), target)) > 0)
		{
			r = m - 1;
		}
		else if (res < 0)
		{
			l = m + 1;
		}
		else
		{
			return m;
		}
	}

	return -2;
}

void getDemographicTrainEntries(int fd, LinkedList *llist)
{
	int n;
	unsigned char entry = 0;
	char *sptr1, *sptr2, *str1, *str2;
	char *line, *subtoken;
	unsigned int h, l;
	Demographic _dmg= {0};
	Demographic *dmg = &_dmg;
	int i = 0;
	int totalBytes = 0;
	int ln = 0;
	char isEmpty = 0;
	
	while ((n = read(fd, buffer, BUFSIZE)) > 0)
	{
		totalBytes += n;
		if (buffer[n - 1] != '\n' && n >= BUFSIZE - 1)
		{
			for (i = n - 1; i >= 0; i--)
			{
				if (buffer[i] != '\n')
					buffer[i] = '\0';
				else
					break;
			}
			buffer[i] = '\0';
			totalBytes -= (n - i);
			lseek(fd, totalBytes, SEEK_SET);
		}

		for (str1 = buffer;; str1 = NULL)
		{
			line = strtok_r(str1, "\n", &sptr1);
			if (line == NULL)
				break;
				
			isEmpty = 0;
			ln++;
			for (str2 = line;; str2 = NULL, entry++)
			{
				subtoken = strtok_r(str2, ", ", &sptr2);
				
				if (subtoken == NULL)
				{
					if (entry < 15)
					{
						entry--;
						isEmpty = 1;
					}
					break;
				}

				switch (entry)
				{
					case 2:
						dmg->sampleW = (unsigned int) atoi(subtoken);
						break;
					case 0:
						dmg->age = (unsigned short) atoi(subtoken);
						break;
					case 1:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->jobC = binarySearch(hJob, (void *) &h, 9,
								sizeof(unsigned int), compare);
						break;
					case 3:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->edu = binarySearch(hEdu, (void *) &h, 16,
								sizeof(unsigned int), compare);
						break;
					case 4:
						dmg->yearsOfEdu = (unsigned char) atoi(subtoken);
						break;
					case 5:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->marStatus = binarySearch(hMarital, (void *) &h, 7,
								sizeof(unsigned int), compare);
						break;
					case 6:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->occ = binarySearch(hOcc, (void *) &h, 14,
								sizeof(unsigned int), compare);
						break;
					case 9:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->gender = binarySearch(hSex, (void *) &h, 2,
								sizeof(unsigned int), compare);
						break;
					case 8:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->race = binarySearch(hRace, (void *) &h, 5,
								sizeof(unsigned int), compare);
						break;
					case 7:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->rship = binarySearch(hRel, (void *) &h, 6,
								sizeof(unsigned int), compare);
						break;
					case 13:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->country = binarySearch(hCountry, (void *) &h, 41,
								sizeof(unsigned int), compare);
						break;
					case 14:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->income = binarySearch(hIncome, (void *) &h, 2,
								sizeof(unsigned int), compare);
						break;
					case 10:
						dmg->capitalG = (unsigned short) atoi(subtoken);
						break;
					case 11:
						dmg->capitalL = (unsigned short) atoi(subtoken);
						break;
					case 12:
						dmg->hpw = (unsigned char) atoi(subtoken);
						break;
				}
			}

			if (!isEmpty)
			{
				linkedList_insert_tail(llist, dmg, sizeof(Demographic));
			}
			entry = 0;
		}
		bzero(buffer, BUFSIZE);
	}
	
	bzero(buffer, BUFSIZE);
}

void getDemographicTestEntries(int fd, LinkedList *llist)
{
	
	int n;
	unsigned char entry = 0;
	char *sptr1, *sptr2, *str1, *str2;
	char *line, *subtoken;
	unsigned int h, l;
	Demographic _dmg = {0};
	Demographic *dmg = &_dmg;
	int i = 0;
	int totalBytes = 0;
	int ln = 0;
	char isEmpty = 0;
	
	while ((n = read(fd, buffer, BUFSIZE)) > 0)
	{
		totalBytes += n;
		if (buffer[n - 1] != '\n' && n >= BUFSIZE - 1)
		{
			for (i = n - 1; i >= 0; i--)
			{
				if (buffer[i] != '\n')
					buffer[i] = '\0';
				else
					break;
			}
			buffer[i] = '\0';
			totalBytes -= (n - i);
			lseek(fd, totalBytes, SEEK_SET);
		}

		for (str1 = buffer;; str1 = NULL)
		{
			line = strtok_r(str1, "\r\n", &sptr1);
			if (line == NULL)
				break;
				
			isEmpty = 0;
			ln++;
			for (str2 = line;; str2 = NULL, entry++)
			{
				subtoken = strtok_r(str2, ", ", &sptr2);

				if (subtoken == NULL)
				{
					if (entry < 15)
					{
						entry--;
						isEmpty = 1;
					}
					break;
				}

				switch (entry)
				{
					case 0:
						dmg->pos = (unsigned short) atoi(subtoken);
						break;
					case 1:
						dmg->age = (unsigned short) atoi(subtoken);
						break;
					case 2:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->jobC = binarySearch(hJob, (void *) &h, 9,
								sizeof(unsigned int), compare);
						break;
					case 3:
						dmg->sampleW = (unsigned int) atoi(subtoken);
						break;
					case 4:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->edu = binarySearch(hEdu, (void *) &h, 16,
								sizeof(unsigned int), compare);
						break;
					case 5:
						dmg->yearsOfEdu = (unsigned char) atoi(subtoken);
						break;
					case 6:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->marStatus = binarySearch(hMarital, (void *) &h, 7,
								sizeof(unsigned int), compare);
						break;
					case 7:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->occ = binarySearch(hOcc, (void *) &h, 14,
								sizeof(unsigned int), compare);
						break;
					case 8:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->rship = binarySearch(hRel, (void *) &h, 6,
								sizeof(unsigned int), compare);
						break;
					case 9:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->race = binarySearch(hRace, (void *) &h, 5,
								sizeof(unsigned int), compare);
						break;
					case 10:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->gender = binarySearch(hSex, (void *) &h, 2,
								sizeof(unsigned int), compare);
						break;
					case 11:
						dmg->capitalG = (unsigned short) atoi(subtoken);
						break;
					case 12:
						dmg->capitalL = (unsigned short) atoi(subtoken);
						break;
					case 13:
						dmg->hpw = (unsigned char) atoi(subtoken);
						break;
					case 14:
						l = strlen(subtoken);
						h = elf_hash(subtoken, l);
						dmg->country = binarySearch(hCountry, (void *) &h, 41,
								sizeof(unsigned int), compare);
						break;
				}
			}

			if (!isEmpty)
			{
				linkedList_insert_tail(llist, dmg, sizeof(Demographic));
			}
			entry = 0;
		}
		bzero(buffer, BUFSIZE);
	}
	bzero(buffer, BUFSIZE);
}

void writeEntry(int fd, int result, int counter) {
	
	unsigned char res;
	
	if (totalSize > 16364) {
		write(fd, buffer, totalSize);
		sleep(2);
		bzero(buffer, BUFSIZE);
		totalSize = 0;
	}
	
	if (result == 0) {
		res = snprintf(buffer+totalSize, 20, "%d;%s%s", counter, GREATER, CRLF);
	} else {
		res = snprintf(buffer+totalSize, 19, "%d;%s%s", counter, LESS, CRLF);
	}

	totalSize += res;
}

void flushEntries(int fd) {
	if (totalSize > 0) {
		write(fd, buffer, totalSize);
		bzero(buffer, BUFSIZE);
		totalSize = 0;
	}
}
