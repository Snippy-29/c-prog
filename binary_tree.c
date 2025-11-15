# include <stdio.h>
# include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create(int data){
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Allocation Failed");
        return NULL;
    }

    new->left = NULL;
    new->data = data;
    new->right = NULL;

    return new;
}

int c = 0;

void append(struct node *root, int data){
    if(root->data == data){
        c=c+1;
    }
    if(root->right == NULL && root->left == NULL){
        return;
    }
    append(root->left,data);
    append(root->right,data);
}

int main() {
    struct node *root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->left->left = create(5);
    root->left->right = create(10);

    append(root, 5);
    printf("Count of 5: %d\n", c);

    return 0;
}