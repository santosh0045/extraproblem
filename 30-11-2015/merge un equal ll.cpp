#include <stdio.h>
#include<malloc.h>
#include<conio.h>
struct node {
	int num;
	struct node *next;
};

void print_list(struct node *head)
{
	struct node *ptr = head;

	printf("\n          Printing list Start            \n");
	while (ptr != NULL)
	{
		printf("\n [%d] \n", ptr->num);
		ptr = ptr->next;
	}
	printf("\n         Printing list End        \n");

	return;
}
struct node * createNode(int num)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num)
{
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
struct node* head;
void rev(struct node *p)
{
	struct node *q;
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	rev(p->next);
	q = p->next;
	q->next = p;
	p->next = NULL;

}
struct node* add(struct node*p, struct node*q)
{
	int carry = 0;
	int z[100];    // dynamically assuming some size
	int i = 0, j = 0;
	int temp = 0;
	while (p != NULL && q != NULL)
	{
		z[i] = (p->num) + (q->num) + carry;   // storing sum in array

		if (z[i]>9)
		{
			carry = 1;
			z[i] = z[i] % 10;          // if sum is 2 digits making it 1 digit 
		}
		else
		{
			carry = 0;
		}

		p = p->next;
		q = q->next;
		i++;

	}
	while (p != NULL && q == NULL)
	{
		z[i] = p->num;
		p = p->next;
		i++;
	}
	while (q != NULL && p == NULL)
	{
		z[i] = q->num;
		q = q->next;
		i++;
	}

	if (carry == 1)
		z[i] = carry;
	else i = i - 1;

	struct node *head1 = NULL;       // making new linked list with the sum array
		j = 0;
	while (j <= i)
	{
		struct node *newNode = createNode(z[j]);
		newNode->next = head1;
		head1 = newNode;
		j++;
	}

	return head1;


}

int main(void) {
	struct node *p, *q, *r;
	printf("enter the list1");
	int list1, list2;
	scanf_s("%d", &list1);
	printf("enter the random list2");
	int list1, list2;
	scanf_s("%d", &list1);
	p = createList(52345);     // random list 
	q = createList(52345);     //  random list 
	rev(p);                   // reversing both to add
	p = head;
	head = NULL;               // head is global
	rev(q);
	q = head;
	head = NULL;
	r = add(p, q);                // add function  
	print_list(r);
	return 0;
}
