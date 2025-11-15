# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

struct node *create(int data){
    struct node *p = malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    p->data = data;
    p->next = NULL;

    return p;
}

void push(int data){
    struct node *new = create(data);
    new->next = top;
    top = new;
    printf("%d will insert\n",data);
}

void pop(){
    if(top == NULL){
        printf("UnderFlow!\n");
        return;
    }
    else{
        struct node *temp = top;
        printf("%d will be poped\n",temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("Stack is Empty\n");
        return;
    }
    else{
        printf("%d \n",top->data);
    }
}

void display(){
    if(top == NULL){
        printf("Stack is Empty\n");
        return;
    }
    else{
        struct node *temp = top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int ch,v;
    while(true){
        printf("1.Push\n2.Pop\n3.Peak\n4.Display\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&v);
                push(v);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invaalid Input");
        }
    }
}