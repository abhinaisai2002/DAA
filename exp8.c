#include<stdio.h>

int graph[10][10];
int sol=0;
int x[10];
int n;
int m=0;
int c=0;

void graphColoring(int);
void nextValue(int);

void main(){
    printf("Enter the vertices of the graph \n");
    scanf("%d",&n);
    printf("Enter graph edges \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);
    }
    printf("All possible solutions are \n");
    for(m=1;m<=n;m++){
        if ( c == 1)
            break;
        graphColoring(1);
    }
    printf("Chromatic number is %d \n",m-1);
    printf("Possible solutions are %d",sol);
}

void graphColoring(int k){
    int i;
    while(1){
        nextValue(k);
        if(x[k] == 0){
            return;
        }
        if(k==n){
            sol++;
            c=1;
            for(i=1;i<=n;i++)
                printf("%d",x[i]);
            printf("\n");
        }
        else
            graphColoring(k+1);
    }
}

void nextValue(int k){
    int i;
    while(1){
        x[k] = (x[k]+1)%(m+1);
        if(x[k] == 0)
            return ;
        for(i=1;i<=n;i++){
            if(graph[k][i] == 1 && x[k] == x[i])
                break;
        }
        if(i==n+1)
            return;
    }
}