#include <stdio.h>
#define MAX 5
typedef struct {
    int data[MAX];
    int praority[MAX];
    int count;
}QUEUE;
int isFull(QUEUE *Queue){
    if(Queue->count==MAX-1)
        return 1;
    return 0;
}
int isNull(QUEUE *Queue){
    if(Queue->count==-1)
        return 1;
    return 0;
}
void enQueue(QUEUE * Queue,int data,int priority){
    if(isFull(Queue)==1){
        printf("Overflow\n");
    }else{
        int p,d;
        Queue->data[Queue->count]=data;
        Queue->praority[Queue->count]=priority;
        Queue->count+=1;
        for(int i=0;i<Queue->count;i++){
            for(int j=i+1;j<Queue->count;j++){
                if(Queue->praority[i]<Queue->praority[j]){
                    p=Queue->praority[i];
                    d=Queue->data[i];
                    Queue->praority[i]=Queue->praority[j];
                    Queue->data[i]=Queue->data[j];
                    Queue->praority[j]=p;
                    Queue->data[j]=d;
                }
            }
        }
    }
}
int deQueue(QUEUE * Queue,int data,int priority){
    if(isNull(Queue)==1){
        printf("Underflow\n");
    }else{
        Queue->count--;
       return Queue->data[(Queue->count)+1];

    }
}

void mian(){
    
}