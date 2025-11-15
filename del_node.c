#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head, int data);
void display(struct node *head);

struct node *create_node(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void add_node(struct node **head, int data){
    struct node *p = create_node(data);
    if(*head == NULL){
        *head = p;
    }
    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

void del(struct node *head, int val){
    struct node *temp = malloc(sizeof(struct node));
    struct node *p= head;
    while(p->next->next!=NULL){
        if(p->data == val){
            temp = p->next;
            p->next = temp->next;
            break;
        }
        p = p->next;
    }
    free(temp);

    display(head);
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i ++){
        printf("Enter the Number : ");
        scanf("%d",&x);
        add_node(&head,x);
    }

    int val;
    printf("Enter the Value to be deleted : ");
    scanf("%d",&val);

    del(head,val);

    return 0;
}