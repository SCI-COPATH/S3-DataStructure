#include <stdio.h>
#define MAX 5
int frond =-1,rear=-1;
int queue[MAX];

int isEmpty(){
    if(frond==-1&&rear==-1)
        return 1;
    return 0;
}
int isFull(){
    if((rear+1)%MAX==frond)
        return 1;
    return 0;
}
void enQueue(int value){
    if(isFull()){
        printf("OVERFLOW\n");
        return ;
    }
    else{
        if(isEmpty())
            frond=0;
        rear=(rear+1)%MAX;
        queue[rear]=value;
    }
}
void deQueue(){
    if(isEmpty())
        printf("UNDER FLOW");
    else{
        if(frond==rear){
            frond=-1;
            rear=-1;
        }
        printf("%d is successfully Removed \n",queue[frond]);
        frond=(frond+1)%MAX;
    }
}
void view(){
    int i;
    if(isEmpty()==0){
         printf("\nQueue\n");
         i=frond;
        while(i!=rear){
            printf("%d\n",queue[i]);
            i=(i+1)%MAX;
         }
         printf("%d\n",queue[i]);
    }
    printf("\n");
}
void main(){
     int dis;
    int val;
    printf("\nQueue Menu\n");
    printf("1- enQueue\n2- deQueue\n3- Exit\n");
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