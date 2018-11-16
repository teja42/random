#include<stdio.h>

/*

0 2 3
2 0 1
3 1 0
*/

int cm[3][3],cost[3][3],via[3][3];

void calculate(int,int*);

void main(){
   int i,j;

   printf("Enter cost matrix : \n");
   for(i=0;i<3;i++){
      for(j=0;j<3;j++) scanf("%d",&cm[i][j]);
   }

   calculate(0,cost[0]);
   calculate(1,cost[1]);
   calculate(2,cost[2]);

}

void calculate(int node,int* _cost){
   int via[3];
   // mark known edges first
   for(int i=0;i<3;i++){
      _cost[i] = cm[node][i];
      via[i] = i;
   }
   // Loop for other nodes
   for(int i=0;i<3 && i!=node ;i++){
      if(cm[i][node] < _cost[i]){
         _cost[i] = cm[i][node];
         via[i] = i;
      }
   }

   printf("Costs For Router %d : \n\n",node);
   for(int i=0;i<3;i++){
      printf("node %d via %d : %d\n",i,via[i],_cost[i]);
   }

}