# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data);
void add_node(struct node **head,int data);
void display(struct node *head);

struct node *create_node(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Allocation Failed!");
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
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p != NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

// void begin(struct node **head, int data){
//     struct node *newnode = create_node(data);
//     // struct node *temp = head;
//     // if( head == NULL ){
//     //     head = newnode;
//     // }
//     // else{
//         newnode->next = *head;
//         *head = newnode;
//     // }
// }

void specific(struct node **head, int data, int k){
    struct node *p = *head;
    struct node *nn = create_node(data);
    int flag = 0;

    while(flag < k-1){
        p = p->next;
        flag ++;
    }

    nn -> next = p->next;
    p->next = nn;
}

int main(){
    struct node *head = NULL;
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i<n; i++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        add_node(&head,x);
    }

    printf("Want to add more data : \n1.Yes\n2.No\n");
    scanf("%d",&x);
    if(x == 2){
        display(head);
        exit(1);
    }
    else{
        int data,k;
        printf("Enter the specific location : ");
        scanf("%d",&k);
        printf("Enter the Data : ");
        scanf("%d",&data);

        specific(&head,data,k);
    }
    display(head);
    return 0;
}