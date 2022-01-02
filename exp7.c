#include<stdio.h>

int arr[20];
int set[20];
int count = 0;
int flag = 0;
int target;
int n;

void subset(int,int);
void display(int n);

void main(){
    printf("Enter the no.of elements in the set \n");
    scanf("%d",&n);
    printf("Enter the values \n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the sum \n");
    scanf("%d",&target);
    printf("The program output is \n");
    subset(0,0);
    if(flag == 0)
        printf("There is no solution");
}

void display(int n){
    int i;
    printf("{");
    for(i=0;i<n;i++)
        printf("%d ",set[i]);
    printf("}");
}

void subset(int sum,int i){
    if(sum == target){
        flag = 1;
        display(count);
        return;
    }
    if(sum>target || i>=n)
        return ;
    else{
        set[count] = arr[i];
        count++;
        subset(sum+arr[i],i+1);
        count--;
        subset(sum,i+1);
    }
}