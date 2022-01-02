#include<stdio.h>
int arr[100],max=-99999,min=99999;
void maxmin(int,int);
int main(){
    int i,s;
    printf("Enter the size of the list \n");
    scanf("%d",&s);
    printf("Enter array elements\n");
    for(i=1;i<=s;i++)
        scanf("%d",&arr[i]);
    maxmin(1,s);
    printf("The maximum element is %d \n",max);
    printf("The minimum element is %d",min);
}
void maxmin(int i,int j){
    if ( i == j){
        max = min = arr[i];
    }
    else if (i == j-1){
        if (arr[i] <arr[j]){
            max = arr[j];
            min = arr[i];
        }
        else{
            max = arr[i];
            min = arr[j];
        }
    }
    else{
        int mid = (i+j)/2;
        maxmin(i,mid);
        int max1 = max;
        int min1 = min;
        maxmin(mid+1,j);
        if (max1 > max)
            max = max1;
        if (min1 < min)
            min = min1;
    }
}