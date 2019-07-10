#include <stdio.h>
#include <string.h>

char* tar = "smart";
char* src = "hello world, this is a smart device!";

void myprint(char* p, int n)
{
	for (int i = 0; i < n; i++)
		printf("%c ", *(p+i));
	printf("\n");
}

char* mystrstr(char* str, char* target)
{
	char* pbegin = NULL;
	char* p1;
	char* p2;

	//for (int i = 0; i < strlen(str); i++)
	while (*str != 0)
	{
		pbegin = str++;
		p1 = pbegin;
		p2 = target;

		while (*p2 != 0)
		{
			if (*(p1++) != *(p2++))
			{
				break;
			}
		}
		if (p2 - target == strlen(target))
			return pbegin;

	}

}

int main()
{
	char* result = "";
	result = mystrstr(src, tar);
	printf("result is: %s\n", result);
	return 0;
}
