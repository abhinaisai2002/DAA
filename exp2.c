#include<stdio.h>
void knapsack(int ,float w[],float p[],int);
void display(float arr[],int n);
void main(){
    float weight[20],profit[20],capacity;
    float ratio[20];
    printf("Enter the capacity of knapsack \n");
    scanf("%f",&capacity);
    int n,temp;
    printf("Total Objects");
    scanf("%d",&n);
    printf("Enter profits and weights for each object");
    for(int i=0;i<n;i++){
        scanf("%f %f",&weight[i],&profit[i]);
    }
    for(int i=0;i<n;i++){
        ratio[i] = profit[i]/weight[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp; 
            }
        }
    }
    printf("%d",capacity);
    knapsack(n,weight,profit,capacity);
}
void knapsack(int n,float weight[],float profit[],int capacity){
    float x[20];
    for(int i=0;i<n;i++)
        x[i] = 0;
    // display(weight,n);
    // display(profit,n);
    int u = capacity;
    float p = 0;
    int i;
    for(i=0;i<n;i++){
        printf("%f %d",weight[i],u);
        if(weight[i] > u)
            break;
        else{
            x[i] = 1.0;
            u = u - weight[i];
            p = p + profit[i];
        }
    }
    if (i<n){
        x[i] = u/weight[i];
        p = p + profit[i]*x[i];
    }

    printf("The resultant array is ... \n");
    for(i=0;i<n;i++)
        printf("%f",x[i]);
    printf("\n Profit is %f",p);
}
void display(float arr[],int n){
    for (int i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
    printf("\n");
}