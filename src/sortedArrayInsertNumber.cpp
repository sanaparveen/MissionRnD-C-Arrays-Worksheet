/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int binarySearch(int *Arr, int len, int num);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int pos, i;

	if (len<1||Arr == NULL)
		return NULL;
	realloc(Arr, len*sizeof(int));

	pos = binarySearch(Arr, len, num);

	for (i = len - 1; i >= pos; i--)
		Arr[i + 1] = Arr[i];
	Arr[pos] = num;

	return Arr;
}
int binarySearch(int *Arr, int len, int num)
{
	int low = 0, high = len - 1, mid;

	if (num > Arr[len - 1])
		return len;

	while (low<high)
	{
		mid = (low + high) / 2;
		if (Arr[mid] > num)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}