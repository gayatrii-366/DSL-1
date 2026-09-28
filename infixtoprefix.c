#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
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

void reverse(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void InfixToPrefix(char infix[], char prefix[]) {
    int i = 0;
    int k = 0;
    char symbol;
    char revInfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);
    for (int idx = 0; revInfix[idx] != '\0'; idx++) {
        if (revInfix[idx] == '(') {
            revInfix[idx] = ')';
        } else if (revInfix[idx] == ')') {
            revInfix[idx] = '(';
        }
    }

    while (revInfix[i] != '\0') {
        symbol = revInfix[i];

        if (isalnum(symbol)) {
            prefix[k++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                prefix[k++] = pop();
            }
            if (top != -1) {
                pop(); 
            }
        } else {
            while (top != -1 && stack[top] != '(' && ISP(stack[top]) > ICP(symbol)) {
                prefix[k++] = pop();
            }
            push(symbol);
        }
        i++;
    }

    while (top != -1) {
        prefix[k++] = pop();
    }
    prefix[k] = '\0';

    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%49s", infix);

    InfixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
