#include <stdio.h>
#include <string.h>

struct Data {
    char n[10];
    int r;
};

void input(struct Data a[10], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", a[i].n);
        printf("Enter roll number: ");
        scanf("%d", &a[i].r);
    }
}

void printData(struct Data a[10], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Student %d | Name: %s | Roll Number: %d\n", i + 1, a[i].n, a[i].r);
    }
}

int search1(struct Data a[10], int size, int k) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i].r == k) {
            return i;
        }
    }
    return -1;
}

void bubble(struct Data a[10], int size) {
    int i, j;
    struct Data t;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (a[j].r > a[j + 1].r) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void selectSort(struct Data a[10], int size) {
    int i, j, m;
    struct Data t;
    for (i = 0; i < size - 1; i++) {
        m = i;
        for (j = i + 1; j < size; j++) {
            if (a[j].r < a[m].r) {
                m = j;
            }
        }
        if (m != i) {
            t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }
}

void insertSort(struct Data a[10], int size) {
    int i, j;
    struct Data temp;
    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j].r > temp.r) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

int search2(struct Data a[10], int size, int k) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid].r == k) {
            return mid;
        }
        if (a[mid].r < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int count = 0, target, pos, ch;
    struct Data list[10];

    do {
        printf("1. Accept Student Data\n");
        printf("2. Display All Students\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search \n");
        printf("5. Selection Sort \n");
        printf("6. Insertion Sort \n");
        printf("7. Exit\n");
        printf("Enter your choice from above: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of students (max 10): ");
                scanf("%d", &count);
                if (count > 0 && count <= 10) {
                    input(list, count);
                } else {
                    printf("Invalid number of students. Please try again.\n");
                    count = 0;
                }
                break;
            case 2:
                if (count == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printData(list, count);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                printf("Enter the roll number to search for: ");
                scanf("%d", &target);
                pos = search1(list, count, target);
                if (pos != -1) {
                    printf("\n[Linear Search] Student Found at index %d!\n", pos);
                    printf("Name: %s | Roll Number: %d\n", list[pos].n, list[pos].r);
                } else {
                    printf("\nStudent with roll number %d not found.\n", target);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                bubble(list, count);
                printData(list, count);
                printf("Enter the roll number to search for: ");
                scanf("%d", &target);
                pos = search2(list, count, target);
                if (pos != -1) {
                    printf("\n[Binary Search] Student Found at index %d!\n", pos);
                    printf("Name: %s | Roll Number: %d\n", list[pos].n, list[pos].r);
                } else {
                    printf("\nStudent with roll number %d not found.\n", target);
                }
                break;
            case 5:
                if (count == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Selection Sort...\n");
                    selectSort(list, count);
                    printData(list, count);
                }
                break;
            case 6:
                if (count == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Insertion Sort\n");
                    insertSort(list, count);
                    printData(list, count);
                }
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
        }
    } while (ch != 7);

    return 0;
}
