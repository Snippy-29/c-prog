# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

struct node *create(int data){
    struct node *p = malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed!\n");
        exit(0);
    }

    p->data = data;
    p->next = NULL;

    return p;
}

void push(int data){
    struct node *p = create(data);
    p->next = top;
    top = p;
    printf("\n%d will be inserted\n",data);
}

void pop(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    else{
        struct node *temp = top;
        printf("\n%d will be popped\n",temp->data);
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
        printf("\n%d \n",top->data);
    }
}

void display(){
    if(top == NULL){
        printf("Stack is Empty");
        return;
    }
    else{
        struct node *temp = top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

int main(){
    int ch,n;
    while(true){
        printf("1.Push\n2.Pop\n3.Peak\n4.Display\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&n);
                push(n);
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