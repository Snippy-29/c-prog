# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *create(int data);
void add(struct node**head, int data);
void display(struct node*head);

struct node *create(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if( p == NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    p -> data = data;
    p -> next = NULL;
    return p;

}

void add(struct node **head, int data)
{
    struct node *f = create(data);
    if(*head == NULL)
    {
        *head =f;
    }
    else
    {
        struct node *temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=f;
    }
}

void display(struct node *head)
{
    struct node *p = head;
    while(p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n,y;
    printf("enter the no. of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the values : ");
        scanf("%d",&y);
        add(&head,y);
    }
    display(head);
    return 0;
}