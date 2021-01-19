#include <stdio.h>
#define MAX 10
typedef struct{
    float coef;
    int exp;
}polynomial;

int polyRead(polynomial poly[]){
    int num,i;
    printf("Enter number of Terms\n");
    scanf("%d",&num);
    printf("Enter exponet in Dessanting order\n");
    for(i=0;i<num;i++){
        printf("Enter coefficient : ");
        scanf("%f",&poly[i].coef);
        printf("Enter Exponent : ");
        scanf("%d",&poly[i].exp);
    }
    return num;
}
void polyPrint(polynomial poly[],int num){
    int i;
    for(i=0;i<num;i++){
        printf("%2.1f X^ %d+",poly[i].coef,poly[i].exp);
    }
    printf("\n");
}
int polynomialAddition(polynomial polyA[],int numA ,polynomial polyB[], int numB,polynomial add[]){
    int i=0,j=0,k=0;
    while (i<numA&&j<numB)
    {
        if(polyA[i].exp==polyB[j].exp){
            add[k].exp=polyA[i].exp;
            add[k].coef=polyA[i].coef+polyB[j].coef;
            i++;
            j++;
        }
        else if(polyA[i].exp>polyB[j].exp){
            add[k].exp=polyA[i].exp;
            add[k].coef=polyA[i].coef;
            i++;
        }
        else{
            add[k].exp=polyB[j].exp;
            add[k].coef=polyB[j].coef;
            j++;
        }
        k++;
    }
    while(numA>i){
        add[k].exp=polyA[i].exp;
        add[k].coef=polyA[i].coef;
        i++;
        k++;
    }
    while (numB>j){
        add[k].exp=polyB[j].exp;
        add[k].coef=polyB[j].coef;
        j++;
        k++;
    }
  return k;  
}
void main(){
    polynomial poly1[MAX];
    polynomial poly2[MAX];
    polynomial add[MAX];
    int numA,numB,numSum;
    printf("Enter polynomial One \n");
    numA=polyRead(poly1);
    printf("Enter polynomial TWo \n");
    numB=polyRead(poly2);
    numSum=polynomialAddition(poly1,numA,poly2,numB,add);
    polyPrint(poly1,numA);
    polyPrint(poly2,numB);
    printf("Sum is : ");
    polyPrint(add,numSum);
}