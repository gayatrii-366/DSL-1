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

void PrefixToInfix(char prefix[], char infix[]) {
    int len = strlen(prefix);
    char op1[MAX], op2[MAX];
    char temp[MAX];

    for (int i = len - 1; i >= 0; i--) {
        char symbol = prefix[i];

        if (isalnum(symbol)) {
            char operand[2] = {symbol, '\0'};
            push(operand);
        } else if (isOperator(symbol)) {
            pop(op1);
            pop(op2);

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
    char prefix[MAX], infix[MAX];

    printf("Enter prefix expression: ");
    scanf("%49s", prefix);

    PrefixToInfix(prefix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
