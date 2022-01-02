#include<stdio.h>

int n;
int x[10];
int graph[10][10];
int c=0;

void hamiltonian(int);
void nextValue(int);

void displaycycle(){
    int i;
    for(int i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("%d",x[1]);
    printf("\n");
}

void main(){
    printf("Enter the no.of vertices in the graph \n");
    scanf("%d",&n);
    printf("Enter the graph info \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
        x[i] = 0;
    x[1] = 1;
    printf("Hamiltonian cycles possible are \n");
    hamiltonian(2);
    printf("Total %d solutions \n",c);
    if(c==0)
        printf("No solutions possible \n");
    return;
}

void hamiltonian(int k){
    while(1){
        nextValue(k);
        if(x[k] == 0)
            return;
        if(k==n){
            c++;
            displaycycle();
        }
        else
            hamiltonian(k+1);
    }
}

void nextValue(int k){
    int j;
    while(1){
        x[k] = (x[k]+1)%(n+1);
        if(x[k] == 0)
            return;
        if(graph[x[k-1]][x[k]]!=0){
            for(j=1;j<=k-1;j++){
                if(x[j] == x[k])
                    break;
            }
            
            if(j==k){
                if((k<n) || ((k==n)&& (graph[x[n]][x[1]]!=0)))
                    return;       
            }
        }
    }
}
