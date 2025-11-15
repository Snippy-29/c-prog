# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head, int data);
void display(struct node *head);

struct node *create_node(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    
    if(p == NULL){
        printf("Memory Allocation will not happen.");
        exit(1);
    }

    p -> data = data;
    p -> next = NULL;

    return p;
}

void add_node(struct node **head, int data){
    struct node *f = create_node(data);
    if(*head == NULL){
        *head = f;
    }
    else{
        struct node *temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = f;
    }
}

void display(struct node *head){
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }
    
}

int main(){
    struct node *head = NULL;
    int n,y;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i ++){
        printf("Enter the Value : ");
        scanf("%d",&y);
        add_node(&head,y);
    }
    display(head);
    return 0;
}