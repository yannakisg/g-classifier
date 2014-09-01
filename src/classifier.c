#include "../include/classifier.h"

/*
 * -6 == Hpw
 * -5 == capitalL
 * -4 == capitalG
 * -3 == years of edu
 * -2 == age
 * -1 == sampleW
 *  2 == gender
 *  5 == race
 *  6 == rship
 *  7 == MarStatus
 *  9 == JobC
 * 14 == occ
 * 16 == education
 * 41 == country
 */
short classifyMoreThanFifty(DecisionTree *tree, void *data, LinkedList *list,
		unsigned short i)
{

	//printf("Size -> %d -> %d\n", list->size, tree->sorted[i][1]);
	if (list->size == 0)
	{
		////linkedList_clear(list);
		return -1;
	}

	if (differentValues(list) == 0)
	{
		//printf("diff -> %d\n", i);
		return getFirstValue(list);
	}

	if (i == 14)//end of the sorted array ergo no more branches
	{
		if (isGreater(list) > 0)
		{
			////linkedList_clear(list);
			//printf("end -> %d\n", i);
			return 1;
		}
		else
		{
			//printf("end -> %d\n", i);
			return 0;
		}
	}

	//nothing of the above exists, ergo create branches.
	Demographic *d = (Demographic *) data;
	LinkedList tempList = {0};
	//printf("Create List\n");
	//linkedList_create(&tempList, free);
//	printf("List created\n");
	//huge if-else if unfolds:P
	
//	printf("Psit => %d\n", tree->sorted[i][1]);
	
	if (tree->sorted[i][1] == -1)
	{ //sampleW
		if (d->sampleW <= tree->continuousValues[(short) (-tree->sorted[i][1])
				- 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-1);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-1);

		////linkedList_clear(list);
		//printf("-1 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == -2)
	{ //age
	//	printf("-2 -> %d\n", i);
		if (d->age <= tree->continuousValues[(short) (-tree->sorted[i][1]) - 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-2);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-2);

		//////linkedList_clear(list);
//		printf("-2 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == -3)
	{ //years of education
		if (d->yearsOfEdu
				<= tree->continuousValues[(short) (-tree->sorted[i][1]) - 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-3);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-3);

		//////linkedList_clear(list);
		//printf("-3 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == -4)
	{ //CapitalG
		if (d->capitalG <= tree->continuousValues[(short) (-tree->sorted[i][1])
				- 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-4);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-4);

		//////linkedList_clear(list);
		//	printf("-4 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == -5)
	{ //capitalL
		if (d->capitalL <= tree->continuousValues[(short) (-tree->sorted[i][1])
				- 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-5);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-5);

		//////linkedList_clear(list);
		//	printf("-5 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == -6)
	{ //Hpw
		if (d->hpw <= tree->continuousValues[(short) (-tree->sorted[i][1]) - 1])
			getLessEqualList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-6);
		else
			getGreaterList(&tempList, list,
					tree->continuousValues[(short) (-tree->sorted[i][1]) - 1],
					-6);

		//////linkedList_clear(list);
		//printf("-6 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	//end of continuous
	else if (tree->sorted[i][1] == 2)
	{
		getList(&tempList, list, d->gender, 2);

		//////linkedList_clear(list);
		//printf("2 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 5)
	{
	//	printf("Heeeeeeeeeeeeeeey\n");
		getList(&tempList, list, d->race, 5);

		//////linkedList_clear(list);
		//printf("5 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 6)
	{
		getList(&tempList, list, d->rship, 6);

		//////linkedList_clear(list);
	//	printf("6 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 7)
	{
		getList(&tempList, list, d->marStatus, 7);

		//////linkedList_clear(list);
		//printf("7 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
		return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);
			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 9)
	{
		getList(&tempList, list, d->jobC, 9);

		//////linkedList_clear(list);
		//printf("9 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 14)
	{
		getList(&tempList, list, d->occ, 14);

		//////linkedList_clear(list);
		//printf("14 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 16)
	{
		getList(&tempList, list, d->edu, 16);

		//printf("16 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
			return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else if (tree->sorted[i][1] == 41)
	{
		getList(&tempList, list, d->country, 41);

		////linkedList_clear(list);
		//printf("41 -> %d\n", i);
		if (tempList.size == 0)
		{
			linkedList_clear(&tempList);
		return classifyMoreThanFifty(tree, data, list, ++i);
		}
		else
		{
			if (i > 0)
				linkedList_clear(list);

			return classifyMoreThanFifty(tree, data, &tempList, ++i);
		}
	}
	else
	{
		////linkedList_clear(list);
		////linkedList_clear(&tempList);
	//	printf("mpla -> %d\n", i);
		return -1;
	}
}

void getList(LinkedList *templist, LinkedList *list, short number,
		short selection)
{
	//printf("getList %d\n" , selection);
	//sleep(3);
	//temp solution???
	if (number < 0)
	{
		//printf("< 0\n");
		Node *temp = list->head;
		Demographic *d;
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			linkedList_insert_tail(templist, d,sizeof(Demographic));
			temp = temp->next;
		}

		//////linkedList_clear(list);
		return;
	}
	Node *temp = list->head;
	Demographic *d;// = (Demographic *)
	//huge if else-if
	if (selection == 2)
	{ //gender
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->gender == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 5)
	{ //race
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->race == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 6)
	{ //rship
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->rship == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			//printf("%p\n", temp);
			temp = temp->next;
		}
	}
	else if (selection == 7)
	{ //marStatus
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->marStatus == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 9)
	{ //jobC
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->jobC == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 14)
	{ //occ
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->occ == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 16)
	{ //education
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->edu == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == 41)
	{ //country
		//printf("here! %d\n", number);
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			//printf("%d\n", d->country);
			if (d->country == number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}

	//////linkedList_clear(list);
}

void getLessEqualList(LinkedList *templist, LinkedList *list,
		long double number, short selection)
{
	//temp solution???
	if (number < 0)
	{
		//printf("< 0\n");
		Node *temp = list->head;
		Demographic *d;
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			linkedList_insert_tail(templist, d,sizeof(Demographic));
			temp = temp->next;
		}

		////linkedList_clear(list);
		return;
	}

	Node *temp = list->head;
	Demographic *d;
	if (selection == -1)
	{//sampleW
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->sampleW <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -2)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->age <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -3)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->yearsOfEdu <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -4)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->capitalG <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -5)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->capitalL <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -6)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->hpw <= number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	//////linkedList_clear(list);

}
void getGreaterList(LinkedList *templist, LinkedList *list, long double number,
		short selection)
{
	//temp solution???
	if (number < 0)
	{
		//printf("< 0\n");
		Node *temp = list->head;
		Demographic *d;
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			linkedList_insert_tail(templist, d,sizeof(Demographic));
			temp = temp->next;
		}
		//////linkedList_clear(list);
		return;
	}

	Node *temp = list->head;
	Demographic *d;
	if (selection == -1)
	{//sampleW
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->sampleW > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -2)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->age > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -3)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->yearsOfEdu > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -4)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->capitalG > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -5)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->capitalL > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}
	else if (selection == -6)
	{//age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			if (d->hpw > number)
			{
				linkedList_insert_tail(templist, d,sizeof(Demographic));
			}
			temp = temp->next;
		}
	}

	//////linkedList_clear(list);
}

unsigned short differentValues(LinkedList *list)
{
	Node *temp = list->head;
	Demographic *d = (Demographic *) NODE_DATA(temp);
	while (temp != NULL)
	{
		if (compareValues(d, NODE_DATA(temp)) == 1)
			return 1;

		temp = temp->next;
	}

	return 0;
}

unsigned short compareValues(void *data1, void *data2)
{
	Demographic *d1 = (Demographic *) data1, *d2 = (Demographic *) data2;

	if (d1->sampleW == d2->sampleW && d1->age == d2->age && d1->jobC
			== d2->jobC && d1->edu == d2->edu && d1->yearsOfEdu
			== d2->yearsOfEdu && d1->marStatus == d2->marStatus && d1->occ
			== d2->occ && d1->gender == d2->gender && d1->race == d2->race
			&& d1->rship == d2->rship && d1->country == d2->country
			&& d1->capitalG == d2->capitalG && d1->capitalL == d2->capitalL
			&& d1->hpw == d2->hpw)
		return 0;
	else
		return 1;
}

unsigned short getFirstValue(LinkedList *list)
{
	Demographic *d = (Demographic *) NODE_DATA(list->head);
	unsigned short result = d->income;
	////linkedList_clear(list);
	return result;
}

unsigned short isGreater(LinkedList *list)
{
	unsigned int totalGreater = 0, totalLess = 0;
	Demographic *d;
	Node *temp = list->head;
	while (temp != NULL)
	{
		d = (Demographic *) NODE_DATA(temp);
		if (d->income == 0)
			totalLess++;
		else
			totalGreater++;

		temp = temp->next;
	}
	if (totalGreater > totalLess)
	{
		////linkedList_clear(list);
		return 1;
	}
	else
	{
		////////linkedList_clear(list);
		return 0;
	}
}

/*
 * -6 == Hpw
 * -5 == capitalL
 * -4 == capitalG
 * -3 == years of edu
 * -2 == age
 * -1 == sampleW
 */
void getContinuousValues(LinkedList *lList, DecisionTree *tree,
		short selection, long double totalInfo)
{
	//printf("getContinuous\n");
	//first get the values, then check all of them in order to get the max info value.
	//then set the tree values.

	short found = 0;
	LinkedList list = {0};
	//linkedList_create(&list, free);
	Node *temp = lList->head, *tempList;
	Demographic *d, *tempData;
	unsigned int values[2][2];
	long double maxInfo = -5.5;
	double long info;

	if (selection == -1)
	{ //sampleW
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL) {
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			}
			else
			{
				while (tempList != NULL)
				{
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->sampleW == tempData->sampleW)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0)
					linkedList_insert_tail(&list, d,sizeof(Demographic));
			}

			temp = temp->next;
		}

		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->sampleW > tempData->sampleW)
				{
					if (d->income == 1)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == 1)
						values[1][0]++;
					else
						values[1][1]++;
				}
				temp = temp->next;
			}

			info = computeInfo(values, 2, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainSampleW = totalInfo - info;
				tree->continuousValues[0] = d->sampleW;
			}

			tempList = tempList->next;
		}
	}
	else if (selection == -2)
	{ //age
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL)
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			else
			{
				while (tempList != NULL)
				{
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->age == tempData->age)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0)
					linkedList_insert_tail(&list, d,sizeof(Demographic));
			}

			temp = temp->next;
		}

		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->age > tempData->age)
				{
					if (d->income == 1)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == 1)
						values[1][0]++;
					else
						values[1][1]++;
				}

				temp = temp->next;
			}
			info = computeInfo(values, 2, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainAge = totalInfo - info;
				tree->continuousValues[1] = d->age;
			}
			tempList = tempList->next;
		}
	}
	else if (selection == -3)
	{ //years of edu
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL) {
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			}
			else
			{
				while (tempList != NULL)
				{
				//	printf("!=NULL\n");
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->yearsOfEdu == tempData->yearsOfEdu)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0) {
					linkedList_insert_tail(&list, d,sizeof(Demographic));
				}
			}
			temp = temp->next;
		}
		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->yearsOfEdu > tempData->yearsOfEdu)
				{
					if (d->income == 1)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == 1)
						values[1][0]++;
					else
						values[1][1]++;
				}

				temp = temp->next;
			}

			info = computeInfo(values, 1, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainYearsOfEdu = totalInfo - info;
				tree->continuousValues[2] = d->yearsOfEdu;
			}
			tempList = tempList->next;
		}
	}
	else if (selection == -4)
	{ //capitalG
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL)
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			else
			{
				while (tempList != NULL)
				{
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->capitalG == tempData->capitalG)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0)
					linkedList_insert_tail(&list, d,sizeof(Demographic));
			}

			temp = temp->next;
		}

		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->capitalG > tempData->capitalG)
				{
					if (d->income == 1)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == 1)
						values[1][0]++;
					else
						values[1][1]++;
				}

				temp = temp->next;
			}

			info = computeInfo(values, 2, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainCapitalG = totalInfo - info;
				tree->continuousValues[3] = d->capitalG;
			}
			tempList = tempList->next;
		}
	}
	else if (selection == -5)
	{ //capitalL
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL)
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			else
			{
				while (tempList != NULL)
				{
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->capitalL == tempData->capitalL)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0)
					linkedList_insert_tail(&list, d,sizeof(Demographic));
			}

			temp = temp->next;
		}

		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->capitalL > tempData->capitalL)
				{
					if (d->income == 1)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == 1)
						values[1][0]++;
					else
						values[1][1]++;
				}

				temp = temp->next;
			}

			info = computeInfo(values, 2, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainCapitalL = totalInfo - info;
				tree->continuousValues[4] = d->capitalL;
			}
			tempList = tempList->next;
		}
	}
	else if (selection == -6)
	{ //hpw
		while (temp != NULL)
		{
			d = (Demographic *) NODE_DATA(temp);
			tempList = list.head;
			//create a linkedList with all the different values that occur
			if (tempList == NULL)
				linkedList_insert_tail(&list, d,sizeof(Demographic));
			else
			{
				while (tempList != NULL)
				{
					tempData = (Demographic *) NODE_DATA(tempList);
					if (d->hpw == tempData->hpw)
					{
						found = 1;
						break;
					}

					tempList = tempList->next;
				}

				if (found == 0)
					linkedList_insert_tail(&list, d,sizeof(Demographic));
			}

			temp = temp->next;
		}

		//for every entry of the list, compute the info value
		tempList = list.head;
		while (tempList != NULL)
		{
			values[0][0] = 0;
			values[0][1] = 0;
			values[1][0] = 0;
			values[1][1] = 0;
			tempData = (Demographic *) NODE_DATA(tempList);
			temp = lList->head;
			while (temp != NULL)
			{
				d = (Demographic *) NODE_DATA(temp);
				if (d->hpw > tempData->hpw)
				{
					if (d->income == Greater)
						values[0][0]++;
					else
						values[0][1]++;
				}
				else
				{
					if (d->income == Greater)
						values[1][0]++;
					else
						values[1][1]++;
				}

				temp = temp->next;
			}

			info = computeInfo(values, 2, lList->size);
			if (info > maxInfo)
			{
				maxInfo = info;
				tree->gainHpw = totalInfo - info;
				tree->continuousValues[5] = d->hpw;
			}
			tempList = tempList->next;
		}
	}
	linkedList_clear(&list);
	//printf("info: %Lf, selection: %d, values: %d %d %d %d, sum: %d\n", maxInfo, selection, values[0][0], values[0][1], values[1][0], values[1][1], values[0][0] + values[0][1] + values[1][0] + values[1][1]);
}
