#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int marks;
};

// Function to accept student data
void accept(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: "); scanf("%s", s[i].name);
        printf("Roll: "); scanf("%d", &s[i].roll);
        printf("Marks: "); scanf("%d", &s[i].marks);
    }
}

// Function to display students
void display(struct Student s[], int n) {
    printf("\n%s\n%d\n%d\n", "Name", "Roll", "Marks");
    for (int i = 0; i < n; i++)
        printf("\n%s\n%d\n%d\n", s[i].name, s[i].roll, s[i].marks);
}
// LINEAR SEARCH
void linearSearch(struct Student s[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            printf("\nFound: %s | Roll: %d | Marks: %d\n", s[i].name, s[i].roll, s[i].marks);
            return;
        }
    }
    printf("\n Student not found!\n");
}
// BINARY SEARCH 
void binarySearch(struct Student s[], int n, int key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll == key) {
            printf("\n Found: %s | Roll: %d | Marks: %d\n", s[mid].name, s[mid].roll, s[mid].marks);
            return;
        }
        else if 
            (key < s[mid].roll) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    printf("\n Student not found!\n");
}
// SELECTION SORT 
void selectionSort(struct Student s[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (s[j].marks < s[min].marks) min = j;
        if (min != i) {
            struct Student temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }
}
// INSERTION SORT 
void insertionSort(struct Student s[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].marks > key.marks) {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}
// SHELL SORT
void shellSort(struct Student s[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Student temp = s[i];
            int j;
            for (j = i; j >= gap && s[j-gap].marks > temp.marks; j -= gap)
                s[j] = s[j-gap];
            s[j] = temp;
        }
    }
}
int main() {
    struct Student s[10];
    int n, choice, key;
    char cont;

    printf("Enter number of students: ");
    scanf("%d", &n);
    
    accept(s, n);
    display(s, n);

    do {
        printf("1. Linear Search\n2. Binary Search\n3. Selection Sort\n4. Insertion Sort\n5. Shell Sort\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter roll to search: ");
                scanf("%d", &key);
                linearSearch(s, n, key);
                break;
            case 2:
                printf("Enter roll to search: ");
                scanf("%d", &key);
                binarySearch(s, n, key);
                break;
            case 3:
                selectionSort(s, n);
                display(s, n);
                break;
            case 4:
                insertionSort(s, n);
                display(s, n);
                break;
            case 5:
                shellSort(s, n);
                display(s, n);
                break;
            default:
                printf("Invalid choice!\n");
        }
        
        printf("\nContinue? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    return 0;
}