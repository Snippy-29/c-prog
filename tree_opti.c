# include <stdio.h>
# include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;


struct node1{
    int data;
    struct node1 *next;
};
struct node1 *head = NULL;

struct node *crete(int data){
    struct node *p = malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(0);
    }
    p->left = NULL;
    p->data = data;
    p->right = NULL;

    return p;
}

struct node1 *create(int data1){
    struct node1 *p = malloc(sizeof(struct node1));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(0);
    }
    p->data = data1;
    p->next = NULL;

    return p;
}

struct node *Insert(struct node *root, int data){
    if(root == NULL){
        root = crete(data);
    }
    if(data < root->data){
        root->left = Insert(root->left,data);
    }
    if(data > root->data){
        root->right = Insert(root->right,data);
    }

    return root;
}

void opti(struct node *root, int data, struct node1 **head){

    if (root == NULL){
        return;
    }

    if(data < root->data){
        struct node1 *p = create(root->data);
        if(*head == NULL){
            *head = p;
        }
        else{
            struct node1 *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = p;
        }
        opti(root->left,data,head);
    }

    if(data > root->data){
        struct node1 *p = create(root->data);
        if(*head == NULL){
            *head = p;
        }
        else{
            struct node1 *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = p;
        }
        opti(root->right,data,head);
    }

    else if(data == root->data){
        struct node1 *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = create(root->data);
    }
}

void display(struct node1 *head) {
    struct node1 *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 18);

    opti(root,12,&head);
    display(head);
    return 0;
}