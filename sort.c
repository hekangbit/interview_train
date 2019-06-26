#include <stdio.h>

void quick_sort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int flag = 0;
	int tmp = arr[i];

	if (i < j)
	{
		while (i < j)
		{
#if 0
			if (flag == 0)
			{
				if (arr[j] < tmp)
				{
					arr[i] = arr[j];
					flag = 1;
					continue;
				}
				else
				{
					j--;
				}
			}
			else
			{
				if (arr[i] > tmp)
				{
					arr[j] = arr[i];
					flag = 0;
					continue;
				}
				else
				{
					i++;
				}
			}
#else
			while (arr[j] > tmp && i < j)
				j--;
			arr[i] = arr[j];
			while (arr[i] < tmp && i < j)
				i++;
			arr[j] = arr[i];

#endif
		}

		arr[i] = tmp;

		quick_sort(arr, left, i - 1);
		quick_sort(arr, j + 1, right);
	}
	else
	{
		return;
	}
}

void print_buf(int buf[], int size)
{
	int i = 0;
	for (; i < size; i++)
		printf("%d, ", buf[i]);
	printf("\n");
}

int main()
{
	int test[10] = {11,100,5,4,78,1,23,14,2,45};
	print_buf(test, 10);
	quick_sort(test, 0, 9);
	print_buf(test, 10);
	
	return 0;
}
