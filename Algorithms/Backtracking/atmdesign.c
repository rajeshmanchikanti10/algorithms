#include<stdio.h>
int issafe(int sum,int *arr,int denomination_level,int notes,int n,int finalsum)
{
sum=sum+arr[denomination_level];
if((notes+1)<=n && sum<=finalsum)
return 1;
return 0;

}
int count_notes(int notes,int sum,int n,int finalsum,int *arr)
{
printf("%d\t%d\n",(notes),sum); 
if((notes)<=n &&sum==finalsum)
	return 1;
for(int denomination_level=0;denomination_level<4;denomination_level++)
{
if(issafe(sum,arr,denomination_level,notes,n,finalsum))
  {
	sum=sum+arr[denomination_level];
	
	if(count_notes(notes+1,sum,n,finalsum,arr))
		return 1;
	sum=sum-arr[denomination_level];
	
  }
}
return 0;
}
int main()
{
int n;
int arr[]={100,200,500,1000};
int notes;
notes=0;
int i=count_notes(notes,0,10,1300,arr);
//printf("no of notes is %d\n",(*notes));
return 0;
}
