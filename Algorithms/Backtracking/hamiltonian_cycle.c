/*Hamiltonian Path in an undirected graph is a path that visits each vertex
exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian 
Path such that there is an edge (in the graph) from the last vertex to the 
first vertex of the Hamiltonian Path. Determine whether a given graph contains 
Hamiltonian Cycle or not. If it contains, then prints the path. Following are 
the input and output of the required function*/


#include<stdio.h>
#define V 5
int issafe(int checkvertex,int graph[][V],int *hamiltonian,int iterator)
{
	if(graph[hamiltonian[iterator-1]][checkvertex]==0)
		return 0;
	for (int i = 0; i <iterator; i++)  
        if (hamiltonian[i] == checkvertex)  
            return 0; 
return 1;
}
void printsolution(int *hamiltonian)
{
for(int i=0;i<V;i++)
	printf("%d\t",hamiltonian[i]);
printf("\n");
}


int hamCycle(int graph[][V],int iterator,int *hamiltonian)
{   if(iterator==V)
	{
		if(graph[hamiltonian[iterator-1]][1]==1)
		{
			printsolution(hamiltonian);
			return 1;
		}
		else
		{
		printf("solution doesn't exist");
		return 0;
		}
	}

	for(int i=0;i<V;i++)
	{
	if(issafe(i,graph,hamiltonian,iterator))
	{
		hamiltonian[iterator]=i;
		if(hamCycle(graph,iterator+1,hamiltonian))
			return 1;
		hamiltonian[iterator]=-1;
	}
	}
return 0;		

}

int main()
{

    /* Let us create the following graph  
        (0)--(1)--(2)  
        | / \ |  
        | / \ |  
        | / \ |  
        (3)-------(4) */
   int graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
      
    // Print the solution 
   int hamiltonian[V];
   for(int i=1;i<V;i++)
	hamiltonian[i]=-1;
/* Let us put vertex 0 as the first vertex in the path. 
    If there is a Hamiltonian Cycle, then the path can be  
    started from any point of the cycle as the graph is undirected */

hamiltonian[0]=1;
hamCycle(graph1,1,hamiltonian); 
}









