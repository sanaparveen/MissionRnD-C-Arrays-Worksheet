/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};


void quicksort(struct student*st, int first, int last);
void * scoresDescendingSort(struct student *students, int len) {

	if (len<1 || students==NULL)
		return NULL;

	quicksort(students, 0, len - 1);
}
void quicksort(struct student*st, int first, int last) {
	int pivot, j, i;
	struct student temp;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (st[i].score >= st[pivot].score && i < last)
				i++;
			while (st[j].score<st[pivot].score)
				j--;
			if (i<j){
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}

		temp = st[pivot];
		st[pivot] = st[j];
		st[j] = temp;

		quicksort(st, first, j - 1);
		quicksort(st, j + 1, last);

	}
}
	