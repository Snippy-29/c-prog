# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head,int data);
void display(struct node *head);
void facto(struct node *head);

struct node *create_node(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));

    if(p == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    p->data=data;
    p->next=NULL;

    return p;
}

void add_node(struct node **head,int data){
    struct node *p=create_node(data);
    if(*head == NULL){
        *head = p;
    }
    else{
        struct node *temp = *head;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }
}

void facto(struct node *head){
    struct node *p = head;
    int t,x;

    while(p != NULL){
        x = p->data;
        t = 1;
        for(int i = 1; i <= x; i ++){
            t = t * i;
        }
        p->data = t;
        p = p->next;
    }

    display(head);
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i ++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        add_node(&head,x);
    }

    facto(head);
    return 0;
}