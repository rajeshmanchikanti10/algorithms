/*Subset sum problem is to find subset of elements that are selected from 
a given set whose sum adds up to a given number K. We are considering the 
set contains non-negative values. It is assumed that the input set is unique 
(no duplicates are presented).*/


#include<stdio.h>
int issafe(int sum,int denomination,int k)
{
	if(sum+denomination<=k)
		return 1;
return 0;
}
void printsolution(int *arr,int outputlevel)
{
	int i;
	for(i=0;i<outputlevel;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int perfect_sum_problem(int *arr,int k,int *output,int sum,int output_level,int iterlevel)
{
if(sum==k)
{
	printsolution(output,output_level);
	output_level=0;
	return 1;
}
int res=0;
for(int i=iterlevel;i<6;i++)
{
if(issafe(sum,arr[i],k))
	{
		sum=sum+arr[i];
		output[output_level]=arr[i];
		res=perfect_sum_problem(arr,k,output,sum,output_level+1,iterlevel+1) || res;
		sum=sum-arr[i];
		output[output_level]=0;
		
		
	}
}
return res;
}
int main()
{
int arr[6]={5,10,12,13,15,18},k=30;
int output[6],i;
for(i=0;i<6;i++)
	output[i]=0;
perfect_sum_problem(arr,k,output,0,0,0);
}