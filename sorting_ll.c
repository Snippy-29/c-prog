# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data);
void add(struct node **head,int data);
void display(struct node *head);

struct node *create(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if( p == NULL ){
        printf("Memory Allocation Failes!");
        exit(1);
    }

    p ->data = data;
    p->next = NULL;

    return p;
}

void add(struct node **head, int data){
    struct node *p = create(data);
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
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp ->data);
        temp = temp->next;
    }
}

void asc(struct node *head){
    struct node *p, *q;
    int temp;
    for(p=head;p!=NULL;p=p->next){
        for(q=p->next;q!=NULL;q=q->next){
            if(p->data > q->data){
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
        }
    }

    display(head);
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i =0; i<n; i++){
        printf("Enter the Number : ");
        scanf("%d",&x);
        add(&head,x);
    }

    asc(head);
    return 0;
}