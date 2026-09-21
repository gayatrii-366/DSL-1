#include <stdio.h>
#define MAX 10
int top = -1;
int isEmpty(int top){
	if(top == -1)
		return 1;
	else
		return 0;
}
int isFull(int top){
	if(top == MAX-1)
		return 1;
	else
		return 0;
}
void push(int n, int arr[]){
	if(isFull(top) == 1)
		printf("Stack Overflow! Cannot Push %d\n", n);
	else{
		top++;
		arr[top] = n;
		printf("Element %d Entered Successfully!\n", n);
	}
}
int pop(int arr[]){
	if(isEmpty(top) == 1){
		printf("Stack Underflow! Empty\n");
		return -1;
	}
	else{
		int poppedVal = arr[top];
		top--;
		return poppedVal;
	}	
}
int main(){
	int stack[MAX];
	push(10, stack);
	push(20, stack);
	push(30, stack);
	int val = pop(stack);
	if(val != -1){
		printf("Popped Value: %d\n", val);
	}
	return 0;
}
