#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

void print_list(struct node *head)
{
	struct node *ptr = head;

	printf("\n       The starting list        \n");
	while (ptr != NULL)
	{
		printf("\n [%d] \n", ptr->num);
		ptr = ptr->next;
	}
	printf("\n             The ending  list       \n");

	return;
}
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
struct node* merge(struct node *a, struct node *b)
{
	struct node *result = NULL;
	if (a == NULL)
	{
		return b;
	}
	if (a == NULL)
	{
		return b;

	}
	if (a->num<b->num)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else if (a->num>b->num)
	{
		result = b;
		result->next = merge(a, b->next);
	}
	else {
		result = b;
		result->next = merge(a->next, b->next);
	}
	return result;
}
int main(void) {
	struct node *a, *b, *r;
	int ll1;
	int ll2;
	printf("enter the linked list one values");
	scanf_s("%d", &ll1);
	printf("enter the linked list two values");
	scanf_s("%d", &ll2);

	a = createList(ll1); //  linked list a
	b = createList(ll2); // some linked list b
	r = merge(a, b); // merge a new LL
	print_list(r);
	_getch();
	return 0;
}