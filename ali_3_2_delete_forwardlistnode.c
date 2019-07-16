
/*
 *题目：给定一个链表，删除链表的倒数第 N 个节点，并且返回链表的头结点。
 ◼ 示例： 给定一个链表: 1->2->3->4->5, 和 n = 2. 当删除了倒数第二个节点后，链表变为 1->2->3->5. 说明： 给定的 n 保证是有效的。 要求： 只允许对链表进行一次遍历。
 * */
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

Node* reverse_delete_node(Node* root, int n)
{
	Node* pa = root;
	Node* pb = root;
	Node* ptmp = NULL;
	int size = 0;
	int count = 0;
	while(pa->pnext)
	{
		if (count == n)
		{
			pa = pa->pnext;
			pb = pb->pnext;
		}
		else
		{
			count++;
			pa = pa->pnext;
		}
		size++;
	}
	size++;

	if (size < n)
	{
		return root;
	}
	else if (size == n)
	{
		return root->pnext;
	}
	else
	{
		if (pb->pnext == pa)
		{
			pb->pnext = NULL;
			return root;
		}
		else
		{
			ptmp = (pb->pnext)->pnext;
			pb->pnext = ptmp;
			return root;
		}
	}
	return NULL;
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
	Node e;
	Node* p;

	a.val = 'A';
	a.pnext = &b;
	b.val = 'B';
	b.pnext = &c;
	c.val = 'C';
	c.pnext = &d;
	d.val = 'D';
	d.pnext = &e;
	e.val = 'E';
	e.pnext = NULL;

	slist_print(&a);
	p = reverse_delete_node(&a,1);
	slist_print(p);
	
	return 0;
}
