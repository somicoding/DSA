#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a print job
typedef struct {
    int jobID;
    char documentTitle[50];
} Job;

// Structure to represent the queue
typedef struct {
    Job jobs[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    printf("Queue initialized successfully.\n");
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to add a print job (Enqueue)
void enqueue(Queue *q, int jobID, char title[]) {
    // Check for overflow
    if (isFull(q)) {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }
    
    // If queue is empty, set front to 0
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    // Increment rear and add the job
    q->rear++;
    q->jobs[q->rear].jobID = jobID;
    strcpy(q->jobs[q->rear].documentTitle, title);
    printf("Print job added successfully.\n");
}

// Function to remove a print job (Dequeue)
Job dequeue(Queue *q) {
    Job emptyJob = {0, ""};
    
    // Check for underflow
    if (isEmpty(q)) {
        printf("Queue Underflow! No print jobs available.\n");
        return emptyJob;
    }
    
    // Get the job at front
    Job removedJob = q->jobs[q->front];
    
    // If only one element was present, reset the queue
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    
    printf("The first inserted print job is processed and removed.\n");
    return removedJob;
}

// Function to display all pending print jobs
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("No Pending Print Jobs\n");
        return;
    }
    
    printf("\nPending Print Jobs \n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Job ID: %d | Document: %s\n", 
               q->jobs[i].jobID, q->jobs[i].documentTitle);
    }
    
}

// Main function
int main() {
    Queue printerQueue;
    int choice, jobID;
    char title[50];
    Job processedJob;
    
    // Initialize the queue
    initializeQueue(&printerQueue);
    
    do {
        printf("\nQUEUE MANAGER-\n");
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &jobID);
                printf("Enter Document Title: ");
                scanf(" %[^\n]", title);  // Read string with spaces
                enqueue(&printerQueue, jobID, title);
                break;
                
            case 2:
                processedJob = dequeue(&printerQueue);
                if (processedJob.jobID != 0) {
                    printf("Processed: Job ID: %d | Document: %s\n", 
                           processedJob.jobID, processedJob.documentTitle);
                }
                break;
                
            case 3:
                display(&printerQueue);
                break;
                
            case 4:
                printf("Program terminates successfully.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}