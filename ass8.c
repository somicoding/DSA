#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int regNo;
    char name[50];
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int regNo, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->regNo = regNo;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// a) Add a student at the end
void addStudent() {
    int regNo;
    char name[50];
    
    printf("Enter Registration Number: ");
    scanf("%d", &regNo);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    
    struct Node* newNode = createNode(regNo, name);
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Student is added successfully.\n");
}

// b) Remove a student by RegNo
void removeStudent() {
    int regNo;
    printf("Enter Registration Number to remove: ");
    scanf("%d", &regNo);
    
    if (head == NULL) {
        printf("Student not found.\n");
        return;
    }
    
    // If head node itself holds the regNo to be deleted
    if (head->regNo == regNo) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Student record is deleted successfully.\n");
        return;
    }
    
    // Search for the node to be deleted
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->regNo != regNo) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Student not found.\n");
    } else {
        struct Node* delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
        printf("Student record is deleted successfully.\n");
    }
}

// c) Display the list
void display() {
    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }
    
    printf("\n Registered Students -\n");
    printf("RegNo           Name\n");
    
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\t\t%s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
    
}

// d) Count total participants
void countParticipants() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of registered students: %d\n", count);
}

// e) Sort the list by RegNo (Bubble Sort)
void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one element. Nothing to sort.\n");
        return;
    }
    
    int swapped;
    struct Node* ptr;
    struct Node* last = NULL;
    
    do {
        swapped = 0;
        ptr = head;
        
        while (ptr->next != last) {
            if (ptr->regNo > ptr->next->regNo) {
                // Swap data
                int tempReg = ptr->regNo;
                ptr->regNo = ptr->next->regNo;
                ptr->next->regNo = tempReg;
                
                char tempName[50];
                strcpy(tempName, ptr->name);
                strcpy(ptr->name, ptr->next->name);
                strcpy(ptr->next->name, tempName);
                
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
    
    printf("List sorted successfully in ascending order of RegNo.\n");
}

// f) Reverse the list
void reverseList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    printf("List reversed successfully.\n");
}

// Free all nodes
void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main menu
int main() {
    int choice;
    
    
    printf("  WORKSHOP ENROLLMENT SYSTEM\n");
    printf("  Singly Linked List Operations-\n");
    
    
    while (1) {
        printf("\nMENU -\n");
        printf("1. Add a Student\n");
        printf("2. Remove a Student\n");
        printf("3. Display the List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                display();
                break;
            case 4:
                countParticipants();
                break;
            case 5:
                sortList();
                break;
            case 6:
                reverseList();
                break;
            case 7:
                freeList();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}