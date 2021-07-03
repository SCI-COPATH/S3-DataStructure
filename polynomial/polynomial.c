#include <stdio.h>
typedef struct{
    int coef;
    int exp;
}node;
int polyAdd(node polyA[],int na,node polyB[],int nb,node sum[]){
int i=0,j=0,k=0;
    while(i<na&&j<nb){
        if(polyA[i].exp>polyB[j].exp){
            sum[k]=polyA[i];
            i++;k++;
        }else if(polyA[i].exp<polyB[j].exp){
            sum[k]=polyB[j]; 
            j++;k++;
        }else{
            sum[k].coef=polyA[i].coef+polyB[j].coef;
            sum[k].exp=polyA[i].exp;
            i++;j++;k++;
        }
    }
    while(i<na){
            sum[k]=polyA[i];
            i++;k++;
        }
        while(j<nb){
            sum[k]=polyB[j];
            j++;k++;
        }
    return k;
}
int polymul(polyA[],int na,node polyB[],int nb,node sum[]){
    for(int i=0;i<na;i++){
        
    }
}
node polynomial1[5],polynomial2[5],result[10];
void main(){
    polynomial1[0].coef=10;
    polynomial1[0].exp=3;
    polynomial1[1].coef=4;
    polynomial1[1].exp=1;

    polynomial2[0].coef=11;
    polynomial2[0].exp=4;
    polynomial2[1].coef=10;
    polynomial2[1].exp=3;
    polynomial2[2].coef=9;
    polynomial2[2].exp=0;
    int data=polyAdd(polynomial1,2,polynomial2,3,result);
    for(int i=0;i<data;i++){
        printf("%dX^%d + ",result[i].coef,result[i].exp);
    }
    printf("\n");
}
