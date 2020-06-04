#include<stdio.h>
#include<string.h>
void swap(char *ch1,char *ch2)
{
char temp;
temp=(*ch1);
(*ch1)=(*ch2);
(*ch2)=temp;
}
void permute(char *ch,int l,int r)
{int i;
if(l==r)
	printf("%s\n",ch);

else
{
	for(i=l;i<=r;i++)
	{
	swap((ch+l),(ch+i));
	permute(ch,l+1,r);
	swap((ch+l),(ch+i));
	}
}
}
int main()
{
char ch[3]="ABC";
permute(ch,0,2);
return 0;
}