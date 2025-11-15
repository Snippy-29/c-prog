# include <stdio.h>
# include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;

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

void Insert(struct node *root, int data){
    struct node *q; int f;
    if(root == NULL){
        if(f == 1){
            q->left = crete(data);
        }
        if(f == 2){
            q->right = crete(data);
        }
        else{
            root = crete(data);
        }
    }
    else{
        if(q->data > data){
            q = root;
            f = 1;
            Insert(q->left,data);
        }
        if(q->data < data){
            q = root;
            f = 2;
            Insert(q->right,data);
        }
    }
}

int main(){
    int p,x;
    printf("Enter the Limit : ");
    scanf("%d",&p);

    for(int i = 0; i < p; i ++){
        printf("Enter the Value : ");
        scanf("%d",&x);
        Insert(root,x);
    }
    
    return 0;
}