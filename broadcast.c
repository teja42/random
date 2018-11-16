#include<stdio.h>

void findMST(int);
void broadcast(int);

/*
cost matrix :
0 1 2
1 0 5
2 5 0 
*/

int cm[3][3],am[3][3],mst[3][3],visited[3] = {0,0,0};
int isBroadcasted[3] = {0,0,0};

void main(){
   printf("Enter adjacency matrix : \n");
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
         scanf("%d",&am[i][j]);
   }
   printf("Enter cost matrix : \n");
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
         scanf("%d",&cm[i][j]);
   }

   findMST(0);
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         mst[j][j] = 1;
      }
   }

   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         printf("%d  ",mst[i][j]);
      }
      printf("\n");
   }

   broadcast(0);

}

void findMST(int node){
   int nodeToVisit=0;
   if(visited[node]) return;
   visited[node] = 1;
   for(int i=0;i<3;i++){
      if(am[node][i] && !visited[i]){
         if(cm[node][i] < cm[node][nodeToVisit]) nodeToVisit = i;
         mst[node][i] = 1;
         mst[i][node] = 1;
         findMST(nodeToVisit);
      }
   }
}

void broadcast(int node){
   for(int i=0;i<3 && !isBroadcasted[i];i++){
      if(mst[node][i]==1){
         printf("%d sends msg to %d\n",node,i);
         isBroadcasted[i] = 1;
         broadcast(i);
      }
   }
}