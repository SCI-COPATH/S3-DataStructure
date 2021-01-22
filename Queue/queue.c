//sci-copath
#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1,rear = -1;
int isNull(){
    if(front==-1&&rear==-1)
        return 1;
    return 0;
}
int isFull(){
    if(rear==MAX_SIZE-1)
        return 1;
    return 0;
}
void enQueue(int value){
    if(isFull()==0){
        if(front==-1)
            front++;
        queue[++rear]=value;
    }
    else
        printf("Overflow\n");
}
void deQueue(){
    if(isNull()==0){
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
            front++;
    }
    else
        printf("UnderFlow");
}
void view(){
    int i;
    if(isNull()==0){
         printf("\nQueue\n");
         for(i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
    printf("\n");
}
void main(){
    int dis;
    int val;
    printf("\nQueue Menu\n");
    printf("1- enQueue\n2- deQueue\n3- Exis\n");
    do{
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter Value\n");
                    scanf("%d",&val);
                    enQueue(val);
                    view();
                    break;
            case 2: deQueue();
                    view();
                    break;
            case 3:break;
            default:printf("Wrong input\n");
        }
    }while(dis!=3);
}