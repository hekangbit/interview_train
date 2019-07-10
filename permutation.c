#include <stdio.h>

char test_buf[5] = {'a','b','c','d',0};


void myprint(char* p, int n)
{
	for (int i = 0; i < n; i++)
		printf("%c ", *(p+i));
	printf("\n");
}

void swap(char* p1, char* p2)
{
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void permute(char* p, int index, int n)
{
	for (int i = index; i < n; i++)
	{
		swap(p+index, p+i);

		if (index != i)
		{
			myprint(test_buf, 4);
		}

		permute(p, index+1, n);

		swap(p+index, p+i);
	}

}

int main()
{
	myprint(test_buf, 4);
	permute(test_buf, 0, 4);
	return 0;
}
