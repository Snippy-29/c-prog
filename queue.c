#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *create(int data) {
    struct node *p = malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->data = data;
    p->next = NULL;
    return p;
}

void enqueue(int data) {
    struct node *new = create(data);

    if (rear == NULL) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
    printf("%d is inserted into the queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow! Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("%d is removed from the queue\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, v;

    while (true) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &v);
                enqueue(v);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input!\n");
        }
    }
}