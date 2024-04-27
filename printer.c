#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a print job
struct PrintJob {
    int jobId;
    int length; // Length of the print job (priority)
};

// Define a node for the priority queue
struct Node {
    struct PrintJob job;
    struct Node* next;
};

// Initialize an empty priority queue
struct Node* front = NULL;

// Function to enqueue a print job
void enqueue(struct PrintJob job) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->job = job;
    newNode->next = NULL;

    if (front == NULL || job.length < front->job.length) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->job.length <= job.length) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to dequeue the highest priority print job
struct PrintJob dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }
    struct Node* temp = front;
    struct PrintJob job = temp->job;
    front = front->next;
    free(temp);
    return job;
}

// Function to display the print queue
void displayQueue() {
    struct Node* temp = front;
    printf("Print Queue:\n");
    while (temp != NULL) {
        printf("Job %d (Length: %d)\n", temp->job.jobId, temp->job.length);
        temp = temp->next;
    }
}

int main() {
    // Example usage
    struct PrintJob job1 = {1, 5}; // Job ID 1, length 5
    struct PrintJob job2 = {2, 3}; // Job ID 2, length 3
    struct PrintJob job3 = {3, 7}; // Job ID 3, length 7

    enqueue(job1);
    enqueue(job2);
    enqueue(job3);

    displayQueue();

    // Dequeue and process print jobs
    while (front != NULL) {
        struct PrintJob nextJob = dequeue();
        printf("Processing Job %d (Length: %d)\n", nextJob.jobId, nextJob.length);
    }

    return 0;
}


