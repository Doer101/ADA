#include<stdio.h>
#define inf 999
#define max 100

int p[max],c[max][max],t[max][2];
int find(int v){
  while(p[v])
   v=p[v];
  return v; 
}

int union1(int i,int j){
  p[j]=i;
}

int kruskal(int n){
  int i,j,k,u,v,min,r1,r2,sum=0;
  for(k=1;k<n;k++){
    min=inf;
    for(i=1;i<n-1;i++){
      for(j=1;j<=n;j++){
        if(i==j) continue;
        if(c[i][j]<min){
          u=find(i);
          v=find(j);
        if(u!=v){
          r1=i;
          r2=j;
          min=c[i][j];
         }
       }
     }
   }
   union1(r1,find(r2));
   t[k][1]=r1;
   t[k][2]=r2;
   sum=sum+min;
 }
   printf("\nCost of spanning tree is:%d",sum);
   printf("\nEdges are:\n");
   for(i=1;i<n;i++)
    printf("\n %d -> %d\n",t[i][1],t[i][2]);
}

int main(){
  int i,j,n;
  printf("\nEnter the n value:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   p[i]=0;
  printf("\nEnter the graph data:\n"); 
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&c[i][j]);
  kruskal(n); 
  return 0;  
}