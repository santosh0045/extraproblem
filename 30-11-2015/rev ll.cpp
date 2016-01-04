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

	printf("\n            starting linked list         \n");
	while (ptr != NULL)
	{
		printf("\n [%d] \n", ptr->num);
		ptr = ptr->next;
	}
	printf("\n      end linked list       \n");

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
int main(void) {
	struct node *p;
	int no;
	printf("enter the linked to insert");
	scanf_s("%d",&no);
	p = createList(no);
	rev(p);
	p = head;                  
	print_list(p);
	getch();
	return 0;
}