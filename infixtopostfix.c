#include <stdio.h>
#include <ctype.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char item) {
    top++;
    stack[top] = item;
}
char pop() {
    char item = stack[top];
    top--;
    return item;
}
int ISP(char op) {
    if (op == '(') return 0;
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}
int ICP(char op) {
    if (op == '(') return 5;
    if (op == '^') return 4;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}
void InfixPostfix(char infix[], char postfix[]){
	int i = 0;
	int k = 0;
	char symbol;
	
	while (infix[i] != '\0') {
        	symbol = infix[i];
        	if (isalnum(symbol)) {
            		postfix[k++] = symbol;
        	}
        	else if (symbol == '(') {
            		push(symbol);
        	}
        	else if (symbol == ')') {
            	while (top != -1 && stack[top] != '(') {
                	postfix[k++] = pop();
            	}	
            	if (top != -1)
                	pop();
        	}
        	else{
			while(top != -1 && stack[top] != '(' && ISP(stack[top]) >= ICP(symbol)){
				postfix[k++] = pop();
			}
			push(symbol);
        	}
        	i++;
        }
        
        while(top != -1){
        	postfix[k++] = pop();
        }	
        
        postfix[k] = '\0';
}
int main(){
	char infix[MAX], postfix[MAX];

	printf("Enter infix expression: ");
	scanf("%s", infix);

	InfixPostfix(infix, postfix);

	printf("Postfix expression: %s\n", postfix);

	return 0;
}
