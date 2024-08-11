#include <stdio.h>

int push(int[], int, int);
int pop(int[], int, int);
void peek(int[], int);
void isFull(int, int);
void isEmpty(int, int);

int main()
{
	int n, choice;
	printf("Enter the max size of stack ");
	scanf("%d", &n);
	int stack[n];
	int top = -1;
	printf("Enter choice\n"
		   "1)Insert(push) element\n"
		   "2)Delete(pop) element\n"
		   "3)Display Top element of stack(peeK)\n"
		   "4)Check stack full\n"
		   "5)Check stack empty\n"
		   "6)Exit\n");
	while (1)
	{
		printf("Enter choice ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			top = push(stack, n, top);
			break;
		case 2:
			top = pop(stack, n, top);
			break;
		case 3:
			peek(stack, top);
			break;
		case 4:
			isFull(n, top);
			break;
		case 5:
			isEmpty(n, top);
			break;
		case 6:
			printf("Terminating Program....");
			exit(0);
		default:
			printf("Wrong choice try again\n");
		}
	}
	return 0;
}

void isFull(int n, int top)
{
	if (top == n - 1)
	{
		printf("Overflow...Stack is Full\n");
		return;
	}
}

void isEmpty(int n, int top)
{
	if (top == -1)
	{
		printf("Underflow...Stack is Empty\n");
		return;
	}
}

int push(int stack[], int n, int top)
{
	if (top == n - 1)
	{
		printf("Overflow...Stack is Full\n");
		return top;
	}
	int data;
	printf("Enter element to insert ");
	scanf("%d", &data);
	stack[++top] = data;
	printf("Data inserted successfully\n");
	return top;
}

int pop(int stack[], int n, int top)
{
	if (top == -1)
	{
		printf("Underflow...Stack is Empty\n");
		return -1;
	}
	int data = stack[top--];
	printf("%d Element popped\n", data);
	return top;
}

void peek(int stack[], int top)
{
	printf("Topmost Element of stack is %d\n", stack[top]);
}
