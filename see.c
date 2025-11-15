#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *createnode(int data);
void addnode(struct node **head,int data);
void display(struct node *head);

struct node *createnode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));

    if( newnode == NULL ){
        printf("memory allocation failed");
        exit(1);
    }
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void addnode(struct node **head,int data){
	struct node *newnode=createnode(data);
	if(*head==NULL){
		*head=newnode;
	}
	else{
		struct node *temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void display(struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

int main(){
    struct node *head = NULL;
    
	int data,ch;
	printf("\n1.addnote 2.display 3.exit");
	printf("\nenter your choice(1,2,3): ");
	scanf("%d",&ch);
	
	while(ch==1 || ch==2){
    
	switch(ch){
		case 1:
			printf("\nenter data:");
			scanf("%d",&data);
			addnode(&head,data);

            printf("\n1.addnote again \n2.display \n3.exit");
	        printf("\nenter your choice(1,2,3): ");
	        scanf("%d",&ch);
            break;
		case 2:
			display(head);
            printf("\n");
            printf("\n1.addnote again \n2.display again\n3.exit");
	        printf("\nenter your choice(1,2,3): ");
	        scanf("%d",&ch);
			break;
		case 3:
			exit(1);
			break;
        }
	}
return 0;	
}