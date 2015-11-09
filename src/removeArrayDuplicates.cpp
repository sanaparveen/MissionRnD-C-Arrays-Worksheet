/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<stdlib.h>

/*hashing*/
struct hash *hashTable = NULL;
int elementCount = 0;

struct node {
	int key;
	int array;
	struct node *next;
};

struct hash {
	struct node *head;
	int count;
};

struct node * listNode(int key, int array) {
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->array = array;
	newnode->next = NULL;
	return newnode;
}


void insertintoHash(int key, int array) {
	int hashIndex = key % elementCount;
	struct node *newnode = listNode(key, array);
	if (!hashTable[hashIndex].head) {
		hashTable[hashIndex].head = newnode;
		hashTable[hashIndex].count = 1;
		return;
	}
	newnode->next = (hashTable[hashIndex].head);//add new nodes
	hashTable[hashIndex].head = newnode;
	hashTable[hashIndex].count++;//updating no.of nodes
	return;
}

int searchElement(int key) {     //to check whethe the the key value pair exist or not
	int hashIndex = key % elementCount, flag = 0;
	struct node *myNode;
	myNode = hashTable[hashIndex].head;
	if (!myNode)
		return -1;

	while (myNode != NULL) {
		if (myNode->key == key) {
			flag = 1;
			return myNode->array;
			break;
		}
		myNode = myNode->next;
	}
	if (!flag)
		return -1;

}

void display(int Arr[],int* tlen)
{

	struct node *myNode;
	int i,j=0;
	for (i = 0; i < elementCount; i++) {
		if (hashTable[i].count == 0)
			continue;
		myNode = hashTable[i].head;
		if (!myNode)
			continue;
		while (myNode != NULL)
		{
			Arr[j++] = myNode->array;
			myNode = myNode->next;
		}
	}
	*tlen = j;
}

void * removeArrayDuplicates(int *Arr, int len)
{
	
	int i = 0, tlen = 0;

	if (len < 1 || Arr == NULL)
		return NULL;
	elementCount = len + 1;
	hashTable = (struct hash *)calloc(elementCount, sizeof (struct hash));

	
	Arr[len] = Arr[len - 1];
	for (i = 0; i < len + 1; i++)
	if (searchElement(Arr[i]) == -1 || Arr[i] != searchElement(Arr[i]))
	{
		insertintoHash(Arr[i], Arr[i]);
	}

	display(Arr, &tlen);
	
	
}