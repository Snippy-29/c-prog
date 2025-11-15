# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

struct node{
    int pid;
    char p_name[50];
    int price;
    int quantity;
    int buy_quantity;
    struct node *next;
};

struct node *create(int pid, char p_name, int price, int quantity, int buy_quantity){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed");
        exit(0);
    }

    p->pid = pid;
    p->p_name[50] = p_name;
    p->price = price;
    p->quantity = quantity;
    p->buy_quantity = buy_quantity;

    p->next = NULL;

    return p;
}

void add_node(struct node **head, int pid, char p_name, int price, int quantity, int buy_quantity){
    struct node *p = create(pid, p_name, price, quantity, buy_quantity);

    if(*head = NULL){
        *head = p;
        return;
    }
    else{
        struct node *temp = *head;
        while(temp ->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head){
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d %s %d %d %d ",temp->pid,temp->p_name, temp->price, temp->quantity, temp->buy_quantity);
        temp = temp->next;
    }
    printf("\n");
}

void growth(struct node *head){
    struct node *p, *q;
    struct node *temp = head;
    int temp;

    for(p=head; p!= NULL; p=p->next){
        for(q=p->next; q!= NULL; q=q->next){
            if(p->buy_quantity < q->buy_quantity){
                temp = q->buy_quantity;
                q->buy_quantity = p->buy_quantity;
                p->buy_quantity = temp;
            }
        }
    }

    int c = 0;
    while (temp->next != NULL && c < 3){
        printf("%s %d ",temp->p_name, temp->buy_quantity);
        temp = temp->next;
        c++;
    }
}

void stock(struct node *head){
    struct node *temp = head;
    int c = 0;

    while(temp -> next != NULL && c<5){
        if(temp->buy_quantity < temp->quantity){
            printf("%d %s ",temp->pid,temp->p_name);
            c++;
        }
        temp=temp->next;
    }
}

void ser(struct node *head,int pid, int quantity){
    struct node *temp = head;

    while(temp ->next!=NULL){
        if(temp->pid == pid && temp->quantity == quantity){
            printf("%d %s %d %d %d ",temp->pid, temp->p_name, temp->price, temp->quantity, temp->buy_quantity);
            printf("\n");
        }
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;
    int n,pid,p_name,price,quantity,buy_quantity;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i<n; i++){
        printf("Enter the pid : ");
        scanf("%d",&pid);
        printf("Enter the p_name : ");
        gets(p_name);
        printf("Enter the price : ");
        scanf("%d",&price);
        printf("Enter the quantity : ");
        scanf("%d",&quantity);
        printf("Enter the buy_quantity : ");
        scanf("%d",&buy_quantity);

        add_node(&head,pid,p_name,price,quantity,buy_quantity);
    }
    printf("Enter Your Choice : \n 1.Growing Products\n 2.Left Out Stock Products\n 3.Searching \n :::: ");
    scanf("%d",&n);
    while(true){
        switch(n){
            case 1:
                growth(head);
                break;
            case 2:
                stock(head);
                break;
            case 3:
                printf("Enter the required pid : ");
                scanf("%d",&pid);
                printf("Enter the required quantity : ");
                scanf("%d",&quantity);
                ser(head,pid,quantity);
                break;
            default:
                printf("Invalid Entry! \nEnter Again...");
        }
    }
}