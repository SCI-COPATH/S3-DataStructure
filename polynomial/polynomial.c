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
int polymul(node polyA[],int n1,node polyB[],int n2,node mul[]){
    node *pA,*pB;
    int na,nb;
    if(n1>n2){
        pA=polyB;
        pB=polyA;
        na=n2;
        nb=n1;
    }else{
        pA=polyA;
        pB=polyB;
        na=n1;
        nb=n2;
    }
    
    //mul[0].coef=pA[0].coef*pB[0].coef;
    //mul[0].exp=pA[0].exp+pB[0].exp;
    int coef,exp,k=0;
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            coef=pA[i].coef*pB[j].coef;
            exp=pA[i].exp+pB[j].exp;
            if(exp==mul[k-1].exp&&k>=0){
                mul[k-1].coef=mul[k-1].coef+coef;
            }else{
                mul[k].coef=coef;
                mul[k].exp=exp;
                k++;
            }
        }
        
    }
    return k++;
}
node polynomial1[5],polynomial2[5],MUL[10],SUM[10];
void main(){
    polynomial1[0].coef=3;
    polynomial1[0].exp=3;
    polynomial1[1].coef=2;
    polynomial1[1].exp=0;

    polynomial2[0].coef=6;
    polynomial2[0].exp=3;
    polynomial2[1].coef=6;
    polynomial2[1].exp=1;
    polynomial2[2].coef=1;
    polynomial2[2].exp=0;
    int data=polymul(polynomial1,2,polynomial2,3,MUL);
    printf("Multiple is \n");
    for(int i=0;i<data;i++){
        printf("%dX^%d + ",MUL[i].coef,MUL[i].exp);
    }
    printf("\n");
    printf("Sum is \n");
    data=polyAdd(polynomial1,2,polynomial2,3,SUM);
    for(int i=0;i<data;i++){
        printf("%dX^%d + ",SUM[i].coef,SUM[i].exp);
    }
    printf("\n");
}
