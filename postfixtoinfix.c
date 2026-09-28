#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX][MAX];
int top = -1;

void push(char str[]) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    }
}

void pop(char str[]) {
    if (top != -1) {
        strcpy(str, stack[top--]);
    } else {
        str[0] = '\0';
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

void PostfixToInfix(char postfix[], char infix[]) {
    char op1[MAX], op2[MAX];
    char temp[MAX];

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            char operand[2] = {symbol, '\0'};
            push(operand);
        } else if (isOperator(symbol)) {
            pop(op2);
            pop(op1);
            temp[0] = '(';
            temp[1] = '\0';
            strcat(temp, op1);

            int currentLen = strlen(temp);
            temp[currentLen] = symbol;
            temp[currentLen + 1] = '\0';

            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(infix);
}

int main() {
    char postfix[MAX], infix[MAX];

    printf("Enter postfix expression: ");
    scanf("%49s", postfix);

    PostfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
