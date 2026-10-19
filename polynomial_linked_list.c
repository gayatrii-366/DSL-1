#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* insertTerm(struct Node* head, int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (head == NULL || pow > head->pow) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->pow >= pow) {
            temp = temp->next;
        }
        if (temp->pow == pow) {
            temp->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

struct Node* createPolynomial() {
    struct Node* head = NULL;
    int n, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        head = insertTerm(head, coeff, pow);
    }
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        } else if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            result = insertTerm(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            result = insertTerm(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* polySum = NULL;
    int choice;

    while (1) {
        printf("\nPolynomial Operations Menu \n");
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating Polynomial 1:\n");
                poly1 = createPolynomial();
                break;
            case 2:
                printf("Creating Polynomial 2:\n");
                poly2 = createPolynomial();
                break;
            case 3:
                printf("Polynomial 1: ");
                display(poly1);
                printf("Polynomial 2: ");
                display(poly2);
                break;
            case 4:
                polySum = addPolynomials(poly1, poly2);
                printf("Sum of Polynomials: ");
                display(polySum);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
