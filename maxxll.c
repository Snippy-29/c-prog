# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head, int data);
void display(struct node *head);
void max(struct node *head);

struct node *create_node(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if( p == NULL ){
        printf("Memory Allocation Failed!");
        exit(1);
    }

    p->data = data;
    p->next = NULL;

    return p;
}

void add_node(struct node **head, int data){
    struct node *p = create_node(data);
    if( *head == NULL ){
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
    while (p != NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    
}

void max(struct node *head){
    struct node *temp = head;
    int max = temp->data;
    while(temp!= NULL){
        if(temp->data > max){
            max = temp->data;
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }

    printf("The max value of the linked list is : %d",max);
}

void count(struct node *head){
    struct node *temp = head;
    int t =0;
    while(temp != NULL){
        t++;
        temp = temp->next;
    }

    printf("%d",t);
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the limit : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter the data : ");
        scanf("%d",&x);

        add_node(&head,x);
    }

    printf("The elements of the Linked-List are : \n");
    display(head);

    printf("\n");
    max(head);

    printf("\n");
    printf("The total number of elements are : ");
    count(head);

    return 0;
}