# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if( p == NULL ){
        printf("Memory Allocation Failed!");
        exit(0);
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void add(struct node **head, int data){
    struct node *p = create(data);
    if(*head == NULL){
        *head = p;
        p->next = *head;
    }
    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->next = *head;
    }
}

void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i ++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        add(&head,x);
    }

    display(head);
    return 0;
}