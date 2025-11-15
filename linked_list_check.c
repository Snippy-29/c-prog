#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *createnode(int data);
void addnode(struct node **head, int data);
void display(struct node *head);

struct node *createnode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node ));
    if(newnode == NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void addnode(struct node **head, int data){
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
	
void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL){
		printf("value is %d", temp->data);
		temp=temp->next;
        printf("\n");
    }
	// printf("");	
}
int main()
{
	struct node *head=NULL;
	int c,data;
	printf("1.addnode 2.display 3.exit\n");
	printf("enter choice:");
	scanf("%d",&c);
	switch(c){
		case 1:
			printf("enter data:");
			scanf("%d", &data);
			addnode(&head,data);
			break;
		case 2:
			display(head);
			break;
		case 3:
			exit(1);
			break;
		default:
			printf("invalid entry");
			break;
    }
    return 0;
}