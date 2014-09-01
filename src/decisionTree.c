#include <math.h>

#include "../include/decisionTree.h"


void createTree(LinkedList *lList, DecisionTree *tree)
{
	unsigned int sex[2][2], race[5][2], rel[6][2], mar[7][2], jobC[9][2],
			occ[14][2], edu[16][2], country[41][2];
	long double totalInfo = 0.0;
	unsigned int totalGreater = 0;
	unsigned short i, j;
	sex[0][0] = 0;
	sex[0][1] = 0;
	sex[1][0] = 0;
	sex[1][1] = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 2; j++)
		{
			race[i][j] = 0;
			rel[i][j] = 0;
			mar[i][j] = 0;
			jobC[i][j] = 0;
			occ[i][j] = 0;
			edu[i][j] = 0;
			country[i][j] = 0;
		}
	}

	rel[5][0] = 0;
	rel[5][1] = 0;
	mar[5][0] = 0;
	mar[5][1] = 0;
	mar[6][0] = 0;
	mar[6][1] = 0;
	jobC[5][0] = 0;
	jobC[5][1] = 0;
	jobC[6][0] = 0;
	jobC[6][1] = 0;
	jobC[7][0] = 0;
	jobC[7][1] = 0;
	jobC[8][0] = 0;
	jobC[8][1] = 0;

	for (i = 5; i < 14; i++)
	{
		for (j = 0; j < 2; j++)
		{
			occ[i][j] = 0;
			edu[i][j] = 0;
			country[i][j] = 0;
		}
	}

	edu[14][0] = 0;
	edu[14][1] = 0;
	edu[15][0] = 0;
	edu[15][1] = 0;

	for (i = 14; i < 41; i++)
		for (j = 0; j < 2; j++)
			country[i][j] = 0;

	//Node *start = lList->head;
	Node *temp = lList->head->next;
	Demographic *d = (Demographic *) NODE_DATA(lList->head);

	//income
	if (d->income == Greater)
		totalGreater++;

	for (i = 0; i < 5; i++)
	{
		if (d->race == i)
		{
			if (d->income == Greater)
				race[i][0]++;
			else
				race[i][1]++;
		}
	}

	if (d->gender == 0)
	{
		if (d->income == Greater)
			sex[0][0]++;
		else
			sex[0][1]++;
	}
	else if (d->gender == 1)
	{
		if (d->income == Greater)
			sex[1][0]++;
		else
			sex[1][1]++;
	}

	for (i = 0; i < 7; i++)
	{
		if (d->marStatus == i)
		{
			if (d->income == Greater)
				mar[i][0]++;
			else
				mar[i][1]++;
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (d->rship == i)
		{
			if (d->income == Greater)
				rel[i][0]++;
			else
				rel[i][1]++;
		}
	}

	for (i = 0; i < 9; i++)
	{
		if (d->jobC == i)
		{
			if (d->income == Greater)
				jobC[i][0]++;
			else
				jobC[i][1]++;
		}
	}

	for (i = 0; i < 14; i++)
	{
		if (d->occ == i)
		{
			if (d->income == Greater)
				occ[i][0]++;
			else
				occ[i][1]++;
		}
	}
	for (i = 0; i < 16; i++)
	{
		if (d->edu == i)
		{
			if (d->income == Greater)
				edu[i][0]++;
			else
				edu[i][1]++;
		}
	}

	//countrylinkedList_create(&list, free);
	for (i = 0; i < 41; i++)
	{
		if (d->country == i)
		{
			if (d->income == Greater)
				country[i][0]++;
			else
				country[i][1]++;
		}
	}

	int k = 0;
	while (temp != NULL)
	{
		k++;
		// printf("%i\n", k);
		d = (Demographic *) NODE_DATA(temp);

		//income
		if (d->income == Greater)
			totalGreater++;

		for (i = 0; i < 5; i++)
		{
			if (d->race == i)
			{
				if (d->income == Greater)
					race[i][0]++;
				else
					race[i][1]++;
			}
		}

		if (d->gender == 0)
		{
			if (d->income == Greater)
				sex[0][0]++;
			else
				sex[0][1]++;
		}
		else if (d->gender == 1)
		{
			if (d->income == Greater)
				sex[1][0]++;
			else
				sex[1][1]++;
		}

		for (i = 0; i < 7; i++)
		{
			if (d->marStatus == i)
			{
				if (d->income == Greater)
					mar[i][0]++;
				else
					mar[i][1]++;
			}
		}

		for (i = 0; i < 6; i++)
		{
			if (d->rship == i)
			{
				if (d->income == Greater)
					rel[i][0]++;
				else
					rel[i][1]++;
			}
		}

		for (i = 0; i < 9; i++)
		{
			if (d->jobC == i)
			{
				if (d->income == Greater)
					jobC[i][0]++;
				else
					jobC[i][1]++;
			}
		}

		for (i = 0; i < 14; i++)
		{
			if (d->occ == i)
			{
				if (d->income == Greater)
					occ[i][0]++;
				else
					occ[i][1]++;
			}
		}
		for (i = 0; i < 16; i++)
		{
			if (d->edu == i)
			{
				if (d->income == Greater)
					edu[i][0]++;
				else
					edu[i][1]++;
			}
		}

		//country
		for (i = 0; i < 41; i++)
		{
			if (d->country == i)
			{
				if (d->income == Greater)
					country[i][0]++;
				else
					country[i][1]++;
			}
		}

		temp = temp->next;
	}

	totalInfo = computeI(totalGreater, lList->size - totalGreater, lList->size);

	tree->gainGender = totalInfo - computeInfo(sex, 2, lList->size);
	tree->gainRace = totalInfo - computeInfo(race, 5, lList->size);
	tree->gainRship = totalInfo - computeInfo(rel, 6, lList->size);
	tree->gainMarStatus = totalInfo - computeInfo(mar, 7, lList->size);
	tree->gainJobC = totalInfo - computeInfo(jobC, 9, lList->size);
	tree->gainOcc = totalInfo - computeInfo(occ, 14, lList->size);
	tree->gainEducation = totalInfo - computeInfo(edu, 16, lList->size);
	tree->gainCountry = totalInfo - computeInfo(country, 41, lList->size);

	getContinuousValues(lList, tree, -1, totalInfo);
	getContinuousValues(lList, tree, -2, totalInfo);
	getContinuousValues(lList, tree, -3, totalInfo);
	getContinuousValues(lList, tree, -4, totalInfo);
	getContinuousValues(lList, tree, -5, totalInfo);
	getContinuousValues(lList, tree, -6, totalInfo);
	//to do continuous values gain.

	/*printf("total: %Lf\n", totalInfo);
	 printf(
	 "%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n",
	 tree->gainGender, tree->gainRace, tree->gainRship,
	 tree->gainMarStatus, tree->gainJobC, tree->gainOcc,
	 tree->gainEducation, tree->gainCountry, tree->gainSampleW,
	 tree->gainAge, tree->gainYearsOfEdu, tree->gainCapitalG,
	 tree->gainCapitalL, tree->gainHpw);
	 */
	//others needed!
	tree->empty = 1;

	tree->sorted[0][0] = tree->gainGender;
	tree->sorted[0][1] = 2;
	tree->sorted[1][0] = tree->gainRace;
	tree->sorted[1][1] = 5;
	tree->sorted[2][0] = tree->gainRship;
	tree->sorted[2][1] = 6;
	tree->sorted[3][0] = tree->gainMarStatus;
	tree->sorted[3][1] = 7;
	tree->sorted[4][0] = tree->gainJobC;
	tree->sorted[4][1] = 9;
	tree->sorted[5][0] = tree->gainOcc;
	tree->sorted[5][1] = 14;
	tree->sorted[6][0] = tree->gainEducation;
	tree->sorted[6][1] = 16;
	tree->sorted[7][0] = tree->gainCountry;
	tree->sorted[7][1] = 41;

	//to do...
	tree->sorted[8][0] = tree->gainSampleW;
	tree->sorted[8][1] = -1; // -1 == sampleW
	tree->sorted[9][0] = tree->gainAge;
	tree->sorted[9][1] = -2;// -2 == Age
	tree->sorted[10][0] = tree->gainYearsOfEdu;
	tree->sorted[10][1] = -3; // -3 == years of edu
	tree->sorted[11][0] = tree->gainCapitalG;
	tree->sorted[11][1] = -4; // -4 == capitalG
	tree->sorted[12][0] = tree->gainCapitalL;
	tree->sorted[12][1] = -5; // -5 == capitalL
	tree->sorted[13][0] = tree->gainHpw;
	tree->sorted[13][1] = -6; // -6 == Hpw

	//printf("here!");
	sortList(tree->sorted);
	/*for (i = 0; i < 14; i++)
	 printf(" i = %d, %Lf, %Lf\n", i, tree->sorted[i][0], tree->sorted[i][1]);*/

	//set values for continuous
	/* tree->continuousValues[0] = continuousValueForSampleW;
	 * tree->continuousValues[1] = continuousValueForAge;
	 * tree->continuousValues[2] = continuousValueForYearsOfEdu;
	 * tree->continuousValues[3] = continuousValueForCapitalG;
	 * tree->continuousValues[4] = continuousValueForCapitalL;
	 * tree->continuousValues[5] = continuousValueForHpw;
	 */
}

/* bubble-sorts the argument list(since size <=15 no need for faster sorting algorithm) */
void sortList(long double sorted[][2]) 
{
	short i, j;
	long double temp, temp2;

	for (i = 13; i >= 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (sorted[j-1][0] < sorted[j][0])
			{
				temp = sorted[j][0];
				temp2 = sorted[j][1];

				sorted[j][0] = sorted[j-1][0];
				sorted[j][1] = sorted[j-1][1];
				sorted[j-1][0] = temp;
				sorted[j-1][1] = temp2;
			}
		}
	}
}

void initializeTree(DecisionTree *tree)
{
	int i, j;
	tree->empty = 0;

	for (i = 0; i < 15; i ++)
	{
		for (j = 0; j < 2; j++)
			tree->sorted[i][j] = 0;
	}
}

long double computeInfo(unsigned int values[][2], unsigned short length, unsigned int total)
{
	unsigned short i;
	unsigned int tempTotal;
	long double result = 0.0;
	for (i = 0; i < length; i++)
	{
		tempTotal = values[i][0] + values[i][1];
		result += computeI(values[i][0], values[i][1], tempTotal) * (long double)tempTotal/total;
	}

	return result;
}

long double computeI(unsigned int greater, unsigned int less,unsigned int total)
{
	if (greater == 0 || less == 0)
		return 0.0;
	else
	{
		long double doubleGreaterRatio = (long double) greater / total,	doubleLessRatio = (long double) less / total;

		return (long double) -(doubleGreaterRatio * (long double) log10(doubleGreaterRatio) / log10(2.0) + doubleLessRatio* (long double) log10(doubleLessRatio) / log10(2.0));
	}
}
