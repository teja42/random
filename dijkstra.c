#include<stdio.h>
#include<limits.h>
/* Example input
adjacency matrix
0 1 1 0 0
1 0 1 1 0
1 1 0 1 1
0 1 1 0 1
0 0 1 1 0

cost matrix
0   4  2  -1  -1
4   0  1   5  -1
2   1  0   8  10
-1  5  8   0  2
-1 -1 10   2  0
*/

int start,end;
int adjacencyMatrix[5][5], costMatrix[5][5];
int path[5], pathIndex = 1;
int totalCost = 0;

void find(int);
int isAlreadyInPath(int);

void main(){
   int i,j;
   printf("Enter adjacency matrix (5x5) :\n");
   for(i=0;i<5;i++){
      for(j=0;j<5;j++){
         scanf("%d",&adjacencyMatrix[i][j]);
      }
   }
   printf("Enter cost matrix : \n");
   for(i=0;i<5;i++){
      for(j=0;j<5;j++)
         scanf("%d",&costMatrix[i][j]);
   }
   printf("Select starting node : ");
   scanf("%d",&start);
   printf("\nSelect ending node : ");
   scanf("%d",&end);

   path[0] = start;
   find(start);
   printf("\nShortest path cost is %d and path is : \n",totalCost);
   for(i=0;i<pathIndex;i++){
      printf("%d ",path[i]);
   }
   printf("\n");

}

void find(int currentNode){
   int currentCost,updatedCost;
   int cost[5], nextNode = 0, nextNodeCost=INT_MAX;
   for(int i=0;i<5;i++){
      if(adjacencyMatrix[currentNode][i]==1){
         cost[i] = costMatrix[currentNode][i]; 
      } else {
         cost[i] = -1;
      }
   }
   for(int i=0; i<5;i++){
      if(cost[i]<nextNodeCost && !isAlreadyInPath(i)){
         nextNode = i;
         nextNodeCost = cost[i];
      }
   }
   totalCost += nextNodeCost;
   path[pathIndex] = nextNode;
   pathIndex++;
   //printf("nextNode : %d\n",nextNode);
   if(nextNode==end)  return;
   else  find(nextNode);
}

int isAlreadyInPath(int node){
   for(int i=0;i<5;i++){
      if(path[i]==node) return 1;
   }
   return 0;
}
