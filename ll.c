#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(int data);
void add(struct node **head, int data);
void display(struct node *head);
void insert_for(struct node **head, int data);

struct node *create(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }
    p->prev = NULL;
    p->data = data;
    p->next = NULL;
    return p;
}

void add(struct node **head, int data) {
    struct node *p = create(data);
    if (*head == NULL) {
        *head = p;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_for(struct node **head, int data) {
    struct node *temp = *head;
    struct node *newNode = create(data);

    if (temp == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = NULL;
    *head = newNode;
}

int main() {
    struct node *head = NULL;
    int n, x;

    printf("Enter the Limit : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value : ");
        scanf("%d", &x);
        add(&head, x);
    }

    while (true) {
        printf("Enter the choice :\n1. Insert Value at front\n2. Display\n3. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                int data;
                printf("Enter the new value : ");
                scanf("%d", &data);
                insert_for(&head, data);
                break;
            }
            case 2:
                display(head);
                break;
            case 3:
                printf("Exitted!\n");
                exit(0);
            default:
                printf("Invalid Input!\n");
        }
    }

    return 0;
}
