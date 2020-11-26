#include <stdio.h>
#define MAX_NUM 5
int top=-1;   
int stack[MAX_NUM];
int isFull(){
    if(top==MAX_NUM-1)
        return 1;
    return 0;
}
int isNull(){
     if(top==-1)
       return 1;
     return 0;
}
void push(int value){
    if(isFull()==1)
        printf("Over flow");
    else
      stack[++top]=value;
}
void pop(){
    if(isNull()==1)
        printf("Underflow");
    else
        top--;
}
void view(){
    int i;
    printf("\nStack \n");
    if(isNull()==1)
        printf("Stack Empty");
    else 
        for(i=0;i<=top;i++)
            printf("%d\n",stack[i]);
    printf("\n");
}
void main(){
    int dis;
    int val;
    printf("\nStack Menu\n");
    printf("1- PUSH\n2- POP\n3- Exis\n");
    do{
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter Value\n");
                    scanf("%d",&val);
                    push(val);
                    view();
                    break;
            case 2:pop();
                    view();
                    break;
            case 3:break;
            default:printf("Wrong input\n");
        }
    }while(dis!=3);
}