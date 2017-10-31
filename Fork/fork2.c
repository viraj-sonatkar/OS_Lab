#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid=fork();
	if(pid>0)
	{
		int i,p;
		for(i=0;i<20;i++)
		{
			p=2i+1;
			printf("%d ",p);
		}		
	}
	if(pid==0)
	{
		int i=0,p;
		while(i<20)
		{
			p=2i;
			printf("%d ",p);
			i++;
		}
	}
	printf("\n\n");
}