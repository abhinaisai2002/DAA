#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct edge{
    int u,v,w;
};

struct graph{
    int vertices;
    int edges;
    struct edge *edge;
};

void display(int arr[],int size);
void bellmanford(struct graph *g,int source);

void main(){
    int v,e,i;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    printf("Enter total vertices and edges");
    scanf("%d %d",&v,&e);
    g->vertices = v;
    g->edges = e;
    g->edge = (struct edge *)malloc(g->edges*sizeof(struct edge));
    printf("Enter edge u,v and weight w");
    for(int i=0;i<e;i++)
        scanf("%d%d%d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);
    bellmanford(g,0);
}

void display(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bellmanford(struct graph *g,int source){
    int vv = g->vertices;
    int ee = g->edges;
    int u,v,w;
    int d[vv];
    int p[vv];
    int i,j;
    for(i=0;i<vv;i++){
        d[i] = INF;
        p[i] = 0;
    }
    d[source] = 0;
    for(i=1;i<=vv-1;i++){
        for(j=0;j<ee;j++){
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            if(d[u]!=INF && d[v]>d[u]+w){
                d[v] = d[u]+w;
                p[v] = u;
            }
        }
    }

    for(j=0;j<ee;j++){
        u = g->edge[j].u;
        v = g->edge[j].v;
        w = g->edge[j].w;
        if(d[u]!=INF && d[v]>d[u]+w){
            printf("Negative cycle");
            return;
        }
    }
    printf("Distance array");
    display(d,vv);

    printf("Predecessor array");
    display(p,vv);
}