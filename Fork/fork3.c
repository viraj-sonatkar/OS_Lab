#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int a=-1;
	pid_t pid=fork();
	if(pid>0)
	{
		sleep(10);
		if(a<=0)
		{
			printf("Error\n");
		}
		else 
		{
			int q[a];
			int i;
			for(i=0;i<a;i++)
			{
				printf("%d\n",q[i] );
			}
		}
	}
	if(pid==0)
	{
		int a;
		printf("enter a number\n");
		scanf("%d",&a);
	}
	printf("\n\n");
}