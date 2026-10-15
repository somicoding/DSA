#include <stdio.h>
#include <string.h>

#define MAX 5

struct PrintJob {
    int jobID;
    char title[50];
};

struct PrintJob queue[MAX];
int front = -1, rear = -1;


void enqueue(int id, char title[]) {
    /* Overflow check */
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    if (front == -1) {          // First insertion
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; // Circular increment
    }

    queue[rear].jobID = id;
    strcpy(queue[rear].title, title);
    printf("Print job added successfully: ID=%d, Title=%s\n", id, title);
}

void dequeue() {
    /* Underflow check */
    if (front == -1) {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("Processed: ID=%d, Title=%s\n", queue[front].jobID, queue[front].title);

    if (front == rear) {        // Only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Circular increment
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty. No pending print jobs.\n");
        return;
    }

    printf("\nPending Print Jobs (FIFO order):\n");
    int i = front;
    while (1) {
        printf("  Job ID: %d | Title: %s\n", queue[i].jobID, queue[i].title);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {
    int choice, id;
    char title[50];

    while (1) {
        printf("\nPrinter Queue Manager-\n");
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &id);
                printf("Enter Document Title: ");
                scanf("%s", title);
                enqueue(id, title);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}