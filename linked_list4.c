# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head, int data);
void display(struct node *head);

struct node *create_node(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if( p == NULL ){
        printf("Memory Allocation Failed!");
        exit(1);
    }

    p -> data = data;
    p -> next = NULL;

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
            temp = temp-> next;
        }
        temp -> next = p;
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d",p->data);
        p = p->next;
        printf("\t");
    }
}

int main(){
    struct node *head = NULL;
    
    int k;
    printf("1.Add Node\n2.Display");
    printf("\nEnter the Choice in 1 or 2 : ");
    scanf("%d",&k);

    while(k == 1){
        printf("Enter the value : ");
        scanf("%d",&k);
        add_node(&head,k);

        printf("\n1.Add Node Again\n2.Display");
        printf("\nEnter the Choice in 1 or 2 : ");
        scanf("%d",&k);
    }

    printf("\nThe Elements are : ");
    display(head);
    printf("\n");
    return 0;
}