#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t pid=fork();
	if(pid>0)
	{
		wait(0);
		printf("parent in process\n\n");		
	}
	if(pid==0)
	{
		printf("child in process\n\n");
	}
	printf("\n\n");
}