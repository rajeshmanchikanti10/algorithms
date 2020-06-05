#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int mn=INT_MIN;
int max(int a,int b)
{
return (a>b)?a:b;
}
int issafe(int sum,int denomination,int finalsum,int n,int notes)
{
sum=sum+denomination;
if((notes+1)<=n && sum<=finalsum)
	return 1;
return 0;

}
void count_notes(int notes,int sum,int n,int finalsum,int *arr)
{

if(sum==finalsum){
	mn=max(mn,notes);
	return;
}
for(int denomination_level=0;denomination_level<4;denomination_level++)
{
if(issafe(sum,arr[denomination_level],finalsum,n,notes))
  {
	sum=sum+arr[denomination_level];
	
	count_notes(notes+1,sum,n,finalsum,arr);
		
	sum=sum-arr[denomination_level];
	
  }
	else


		return;
}

}
int main()
{
int n;
int arr[]={100,200,500,1000};
int notes;


notes=0;
count_notes(notes,0,5,1400,arr);
printf("no of notes is %d\n",mn);
int returnvalue=0;
return returnvalue;
}