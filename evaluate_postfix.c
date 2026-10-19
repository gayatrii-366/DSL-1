#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int evaluatePostfix(char* exp) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] == ' ' || exp[i] == '\t')
            continue;

        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (exp[i]) {
                case '+': 
                    push(&s, val2 + val1); 
                    break;
                case '-': 
                    push(&s, val2 - val1); 
                    break;
                case '*': 
                    push(&s, val2 * val1); 
                    break;
                case '/': 
                    if (val1 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    push(&s, val2 / val1); 
                    break;
                default:
                    printf("Error: Invalid operator %c\n", exp[i]);
                    exit(1);
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX];
    
    printf("Enter postfix expression (e.g., 23*5+): ");
    if (fgets(exp, MAX, stdin) != NULL) {
        exp[strcspn(exp, "\n")] = 0;

        int result = evaluatePostfix(exp);
        printf("Evaluated Result: %d\n", result);
    }

    return 0;
}
