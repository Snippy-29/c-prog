# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

struct node{
    struct node *prev;
    char data[50];
    struct node *next;
};

struct node *create(char *data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory Allocation Failed!");
        exit(0);
    }

    new->prev = NULL;
    strcpy(new->data,data);
    new ->next = NULL;

    return new;
}

void add(struct node **head,char *data){
    struct node *p = create(data);
    if(*head == NULL){
        *head = p;
    }
    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void player(struct node *head){
    struct node *p = head;
    printf("\nPlaying '%s'...\n",p->data);
    int ch;
    
    while(true){
        printf("\nEnter Choice: \n1.Next Song\n2.Previous Song\n3.Return\n:::: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                p=p->next;
                printf("Now playing next song '%s'",p->data);
                break;
            case 2:
                p=p->prev;
                printf("Now playing previous song '%s'",p->data);
                break;
            case 3:
                return;
            default:
                printf("Invalid Choice for Player!");
        }
    }
}


int main(){
    struct node *head = NULL;
    int n,ch; char str[50];

    while(true){
        printf("\nEnter your choice : \n1.Add Song\n2.Play Song\n3.Exit\n::: ");
        scanf("%d",&ch);
        getchar();
        switch(ch){
            case 1:
                printf("Enter the Value : ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                add(&head,str);
                break;
            case 2:
                printf("\nEntered in Music Player : \n");
                player(head);
                break;
            case 3:
                printf("Program Ended!");
                exit(0);
            default:
                printf("Invalid Input! Enter Again...");
                break;
        }
    }
}