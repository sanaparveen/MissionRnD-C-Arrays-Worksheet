
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int search(int *Arr, int low, int high, int score, int val)
{
	int res = -1, mid,temp=-1;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (Arr[low]<score && Arr[high]) //if the value is exactly present
			temp = mid;
		if (Arr[mid] == score)
		{
			res = mid;
			if (val == 1) 
				high = mid - 1; //searches the least occurance in case of repetition
			else  
				low = mid + 1;  //searches the highest occurance in case of repetition
		}
		else if (score < Arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return (val == 1 && res == -1) ? temp + 1 : (val == 2 && res == -1) ? temp : res;
}
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	
	int low = 0, high = len - 1;
	if (len<1 ||Arr == NULL)
		return NULL;
	*lessCount = 0;
	*moreCount = 0;
	*lessCount = search(Arr, low, high, score, 1);
	*moreCount = (len - 1) - search(Arr, low, high, score, 2);
}
