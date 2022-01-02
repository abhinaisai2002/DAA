#include<stdio.h>
void floyds(int c[10][10],int n);
int min(int ,int);
void main(){
    printf("Enter the no.of vertices \n");
    int n;
    scanf("%d",&n);
    printf("Enter the no.of edges \n");
    int e;
    scanf("%d",&e);
    int c[10][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j] = 999;
        }
    }
    printf("Enter the edge weight for %d edges \n",e);
    int u,v,w;
    for(int i=1;i<=e;i++){
        scanf("%d %d %d",&u,&v,&w);
        c[u][v] = w;
    }
    printf("Matrix of input data \n");
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Cost matrix \n");
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    floyds(c,n);
    printf("The shortest paths are \n");
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(i!=j)
                printf("%d->%d =  %d \n",i,j, c[i][j]);
        }
    }
}
int min(int a,int b){
    return a>b?b:a;
}
void floyds(int c[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)
                    c[i][j] = 0;
                else
                    c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
}