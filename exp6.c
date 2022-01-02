#include<math.h>
#include<stdio.h>
int count=0;
int x[10]; 
//////////////////////
void queen(int);
void printBoard(int);
int place(int);
//////////////////////

void main(){
    printf("Enter the no.of queens \n");
    int n;
    scanf("%d",&n);
    queen(n);
    printf("Possible solutions %d",count);
}
int place(int pos){
    int i;
    for(i=1;i<pos;i++){
        if(x[i] == x[pos] || (abs(x[i]-x[pos]) == abs(i-pos)))
            return 0;
    }
    return 1;
}
void printBoard(int n){
    int i,j;
    count++;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(x[i] == j)
                printf("Q%d ",i);
            else
                printf("* ");
        }
        printf("\n");
    }
}
void queen(int n){
    int k =1;
    x[k] = 0;
    while(k!=0){
        x[k] = x[k] + 1;
        while(x[k]<=n && !place(k)){
            x[k]++;
        }
        if(x[k]<=n){
            if(k==n)
                printBoard(n);
            else{
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
}