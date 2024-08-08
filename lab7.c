#include<stdio.h>
#define max 50
int p[max],w[max],x[max],n,m,i,j;
double max_p=0.0;

void greedy_knap(int n,int w[],int p[],int m){
  double ratio[max];
  for(i=0;i<n;i++){
    ratio[i]=(double)p[i]/w[i];
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(ratio[i]<ratio[j]){
        double temp=ratio[i];
        ratio[i]=ratio[j];
        ratio[j]=temp;

        int temp2=w[i];
        w[i]=w[j];
        w[j]=temp2;

        temp2=p[i];
        p[i]=p[j];
        p[j]=temp2;
      }
    }
  }
  int cw=0;
  for(i=0;i<n;i++){
    if(cw+w[i]<=m){
      x[i]=1;
      cw+=w[i];
      max_p+=p[i];
    }
    else{
      x[i]=(m-cw)/(double)w[i];
      max_p+=x[i]*p[i];
      break;
    }
  }
  printf("\nOptimal solution for greedy approach is:%0.1f",max_p);
  printf("\nSolution vector for this is:\n");
  for(i=0;i<n;i++)
   printf("%d\t",x[i]);
}

int main(){
  printf("\nEnter the number of objects:");
  scanf("%d",&n);
  printf("\nEnter the weight of each object:\n");
  for(i=0;i<n;i++)
   scanf("%d",&w[i]);
  printf("\nEnter the profit of each object:\n");
  for(i=0;i<n;i++)
   scanf("%d",&p[i]);
  printf("\nEnter the maximum capacity:");
  scanf("%d",&m);
  greedy_knap(n,w,p,m);
  return 0;  
}
 