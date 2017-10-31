#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int a[9];
	int n=9,c,i,j;
	for (i=0;i<9;++i)
	{
		printf("enter a number\n");
		scanf("%d",&a[i]);
	}
	pid_t pid=fork();
	if(pid>0)
	{
		int m=n/2;
		printf("\nParent:Ascending Order-\n");
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
				if(a[i]>a[j])
				{
					c=a[i];
					a[i]=a[j];
					a[j]=c;
				}
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	if(pid==0)
	{
		int m=n/2;
		printf("\nChild:Descending Order-\n");
		for(i=m;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				if(a[i]<a[j])
				{
					c=a[i];
					a[i]=a[j];
					a[j]=c;
				}
		}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	printf("\n\n");
}