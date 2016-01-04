/*median of a linked lisr*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

/*void print_list(struct node *head)
{
	struct node *ptr = head;

	printf("\n The starting list \n");
	while (ptr != NULL)
	{
		printf("\n [%d] \n", ptr->num);
		ptr = ptr->next;
	}
	printf("\n The  End List \n");

	return;
}*/
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
void median(struct node *head)
{
	struct node *ptr1 = head;
	struct node *ptr2 = head;

	int v = 0;
	while (ptr2 != NULL && ptr1 != NULL)
	{


		if (ptr2->next == NULL)
		{
			v = 2;
			break;
		}
		else if (ptr2->next->next == NULL && ptr2->next != NULL)
		{
			v = 1;
			break;
		}

		ptr1 = ptr1->next;

		ptr2 = ptr2->next->next;

	}
	if (v == 1)
	{
		float a;
		float b;
		float c;
		a = ptr1->num;
		b = ptr1->next->num;
		c = (a + b) / 2;
		printf("%f", c);   // prints the median of negative length
	}
	if (v == 2)
		printf("%d", ptr1->num); // prints the median of odd length


}

int main(void) {
	struct node *p;
	int num;
	printf("enter the numbers you want insert the node");
	scanf_s("%d",&num);
	p = createList(num);// type the number u want to create list .. doesnt work for -ve
	median(p);  // passing node p and median will b prnted in the function
	_getch();
	return 0;
}