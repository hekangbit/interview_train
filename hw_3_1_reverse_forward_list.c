
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//forward list is A,B,C,D
//reverse this list, should travesal once,
//forward list became D,C,B,A



typedef struct Node{
	struct Node* pnext;
	char val;
}Node;

void reverse(Node* root)
{
	Node* pcur = root;
	Node* ptmp = NULL;
	Node* pnext = NULL;
	while(pcur)
	{
		pnext = pcur->pnext;
		pcur->pnext = ptmp;
		ptmp = pcur;
		pcur = pnext;
	}
}

void slist_print(Node* root)
{
	Node *pcur = root;
	while(pcur)
	{
		printf("%c-", pcur->val);
		pcur = pcur->pnext;
	
	}
	printf("\n");
}

int main()
{
	Node a;
	Node b;
	Node c;
	Node d;

	a.val = 'A';
	a.pnext = &b;
	b.val = 'B';
	b.pnext = &c;
	c.val = 'C';
	c.pnext = &d;
	d.val = 'D';
	d.pnext = NULL;

	slist_print(&a);
	reverse(&a);
	
	slist_print(&d);
	slist_print(&a);
	return 0;
}
