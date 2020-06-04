
/*Given an undirected graph and a number m, determine if the graph can be
 coloured with at most m colours such that no two adjacent vertices of the
 graph are colored with the same color.  Here coloring of a graph means the
 assignment of colors to all vertices.*/


#include<stdio.h>
#define V 4
int issafe(int graph[][V],int *color,int presentcolor,int vertex)
{
	for(int i=0;i<V;i++)
	{
		if(graph[vertex][i] && color[i]==presentcolor)
			return 0;
	}
return 1;
}
void printsolution(int *color)
{
for(int i=0;i<V;i++)
	printf("%d\t",color[i]);
printf("\n");
}
int graphColoring(int graph[][V],int noofcolors,int vertex,int *color)
{
if(vertex==V)
	{	
		printsolution(color);
		return 1;
	}
	for(int c=1;c<=noofcolors;c++)
	{
	if(issafe(graph,color,c,vertex))
	{	color[vertex]=c;
		if(graphColoring(graph,noofcolors,vertex+1,color))
			return 1;
		color[vertex]=0;
	}
	}
  return 0;
}
int main()
{
int graph[V][V]={{ 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 },};
int m=3;//Number of colors
int color[V];
for(int i=0;i<V;i++)
	color[i]=0;
if(!graphColoring(graph,m,0,color))
printf("Solution does not exist");
return 0;
}