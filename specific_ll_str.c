# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct node{
    char Name[50];
    int Roll;
    struct node *next;
};

struct node *create(char d1[50],int data);
void add_node(struct node **head,char d1[50],int data);
void display(struct node *head);
void specific(struct node **head,char d1[50], int Roll, char pos[50]);

struct node *create(char d1[50],int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    strcpy(p->Name,d1);
    p->Roll = data;
    p->next = NULL;

    return p;
}

void add_node(struct node **head,char d1[50],int data){
    struct node *p = create(d1,data);
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
    while(p!=NULL){
        printf("%s | %d\t",p->Name,p->Roll);
        p = p->next;
    }
}

void specific(struct node **head,char d1[50], int Roll, char pos[50]){
    struct node *new = create(d1,Roll);
    struct node *p = *head;
    while(p!=NULL && (strcmp(p->Name,pos)!=0)){
        p = p->next;
    }

    new->next = p->next;
    p->next = new;
}

int main(){
    struct node *head = NULL;
    char d1[50],d2[50];
    int n,x;
    printf("Enter the Limit : ");
    scanf("%d",&n);

    for(int i = 0; i<n; i++){
        printf("Enter the Name : ");
        scanf("%s",&d1);
        printf("Enter the Roll : ");
        scanf("%d",&x);
        add_node(&head,d1,x);
    }

    printf("Do you want to add more value : \n1.Yes\n2.No\n");
    scanf("%d",&n);
    if(n == 1){
        printf("Enter the Position : ");
        scanf("%s",&d2);
        printf("Enter the Name : ");
        scanf("%s",&d1);
        printf("Enter the Roll : ");
        scanf("%d",&x);
        specific(&head,d1,x,d2);
    }
    display(head);
    return 0;
}