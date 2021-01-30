#include <stdio.h>

int index;

void array_printer(int array[], int length)
{
	for (index = 0; index < length; index ++)
	{
		printf("%d ", array[index]);
	}

	printf("\n");
}

void merge(int list[], int left_index, int mid, int right_index)
{
	int index2 = 0;

	int index3 = 0;

	int length = (mid - left_index) + 1;

	int length2 = right_index - mid;

	int left_list[length];

	int right_list[length2];

	for (index = 0; index < length; index ++)
	{
		left_list[index] = list[left_index + index];
	}
	
	for (index = 0; index < length2; index ++)
	{
		right_list[index] = list[mid + 1+ index ];
	}

	index = 0;
	
	index2 = 0;
	
	index3 = left_index;

	while (index < length && index2 < length2)
	{
		if (left_list[index] < right_list[index2])
		{
			list[index3] = left_list[index];

			index ++;
		}
		else
		{
			list[index3] = right_list[index2];

			index2 ++;
		}

		index3 ++;
	}

	while (index < length)
	{
		list[index3] = left_list[index];
		
		index ++;
		
		index3 ++;
	}
	
	while (index2 < length2)
	{
		list[index3] = right_list[index2];
		
		index2 ++;
		
		index3 ++;
	}
}

void merge_sort(int list[], int left_index, int right_index)
{
	if (left_index < right_index)
	{
		int mid = left_index + (right_index - left_index) / 2;

		merge_sort(list, left_index, mid);

		merge_sort(list, mid + 1, right_index);

		merge(list, left_index, mid, right_index);
	}
}

int main(int argc, char *argv[])
{
	int size;

	printf("Please enter the size of list:\n");

	scanf("%d", &size);

	int list[size];

	printf("Please enter the items of list:\n");

	for (index = 0; index < size; index++)
	{
		scanf("%d", &list[index]);
	}

	merge_sort(list, 0, size - 1);

	array_printer(list, size);

	return 0;
}