# include <stdio.h>
# include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
// struct node *h1 = NULL;
// struct node *h2 = NULL;

struct node1{
    struct node1 *left;
    int data;
    struct node1 *right;
};
struct node1 *root = NULL;

struct node *create(int data){
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Allocation Failed");
        exit(0);
    }
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    return new;
}

struct node1 *crete(int data){
    struct node1 *p = malloc(sizeof(struct node1));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(0);
    }
    p->left = NULL;
    p->data = data;
    p->right = NULL;

    return p;
}

void add(struct node **head, int data){
    struct node *new = create(data);
    if(*head == NULL){
        *head = new;
    }
    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void display(struct node *head){
    struct node *p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void TM(struct node1 *root,struct node *h1, struct node *h2){
    if(root == NULL){
        while(h1->next != NULL){
            h1 = h1->next;
        }

        while(h1->data != h2->data){
            h2 = h2->next;
        }
        root = h1;
        TM(root,h1,h2);
    }
    else{
        struct node *p = h2; h1 = h1->prev;
        while(p->next != NULL){
            if(p->data == h1->data){
                TM(root->right,h1,h2);
            }
            p = p->next;
        }

        while(p->prev != NULL){
            if(p->data == h1->data){
                TM(root->left,h1,h2);
            }
        }
    }
}

int main(){
    struct node *h1 = NULL;
    struct node *h2 = NULL;

    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    printf("Enter the Values for Post-Order : \n");
    for(int i = 0; i < n; i ++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        add(&h1,x);
    }
    printf("\nPost-Order : \n");
    display(h1);
    printf("\nEnter the Value for Inorder : \n");
    for(int i = 0; i < n; i ++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        add(&h2,x);
    }
    printf("\nIn-Order : \n");
    display(h2);


}