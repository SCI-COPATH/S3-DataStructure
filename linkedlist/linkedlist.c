#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void insertionAtBegining(struct node **head,int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    if(*head==NULL)
        *head=newNode; 
    else{
        newNode->link=*head;
        *head=newNode;
    } 
}
void insertionAtEnd(struct node **head,int data){
    struct node *newNode,*ptr=*head;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    if(*head==NULL)
        *head=newNode; 
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=newNode;
    }
}
void view(struct node *head){
    if(head==NULL){
        printf("Empty list\n");
    }
    else{
        printf("LIST\n");
        while(head!=NULL){
            printf("%d\n",head->data);
            head=head->link;
        }
        printf("\n");
    }
}
void main(){
    struct node *head=NULL;
    insertionAtBegining(&head,10);
    insertionAtBegining(&head,20);
    insertionAtBegining(&head,30);
    insertionAtEnd(&head,40);
    insertionAtEnd(&head,50);
    view(head);
}