/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>


struct student {
	char *name;
	int score;
};

void qsort(struct student *students, int left, int right)
{
	struct student pivot;
	int i, j, k = 0;
	if (left < right)
	{
		pivot = students[left];
		i = left;
		j = right;
		while (left < right){
			while ((students[right].score >= pivot.score) && (left < right))
				--right;
			if (left != right)
				students[left++] = students[right];
			while ((students[left].score <= pivot.score) && (left < right))
				++left;
			if (left != right)
				students[right--] = students[left];
		}
		students[left] = pivot;
		k = left;
		left = i;
		right = j;
		if (left<k)
			qsort(students, left, k - 1);
		if (right > k)
			qsort(students, k + 1, right);
	}

} 
#include <malloc.h>
struct student ** topKStudents(struct student *students, int len, int K) {

	int i=0,n=0;
	struct student **array = (struct student **)malloc(sizeof(struct student));
	
	if (len < 1 || K <= 0)
		return NULL;

	qsort(students, 0, len - 1);
	if (K>len)
		K = len;
	for (i = len - K; i<len ; i++)
		array[n++] = &students[i];

	return array;
}
