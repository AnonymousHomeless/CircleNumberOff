#include <stdio.h>
#include <malloc.h>

/////////////////////////
struct node
{
	int data;
	struct node *pp;
	struct node *lp;
}*head;
////////////////////////

struct node *create(int n);
int retrieve(struct node *p);
void print(int *people, int *n);

/////////////////////////////////
int main()
{
	int i;
	int people,n;
	int count = 0;
	struct node *p;
	
	print(&people, &n);
	head = create(people);
	p = head;
	
	while(people > 1)
	{
		count += p->data;
		/*if (count == n)
		{
			p->pp->lp = p->lp;
			p->lp->pp = p->pp;
			free(p);
		}*/
		if(count == n)
		{
			p->data = 0;
			count = 0;
			people--;
		}
		p = p->lp;
	}

	n = retrieve(head);
	printf("最后一个是%d号",n);
	scanf("%d",&i);
	return 0;
}


struct node *create(int n)
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *tail = NULL;
	int i = 1;
	for (i; i <= n; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->pp = NULL;
		temp->lp = NULL;
		temp->data = 1;
		if (i == 1)
			head = temp;
		else
		{
			tail->lp = temp;
			temp->pp = tail;
		}
		tail = temp;
	}
	head->pp = tail;
	tail->lp = head;
	return head;
}

int retrieve(struct node *p)
{
	int i = 1;
	while(p->data == 0)
	{
		i++;
		p = p->lp;
	}
	return i;
}
void print(int *people, int *n)
{
	printf("有几个小盆友要玩啊？\n请输入数:");
	scanf("%d",people);
	printf("请输入报的最大的数：");
	scanf("%d",n);
}
