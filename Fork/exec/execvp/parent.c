#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
int main(){
	char a[10];
	printf("Enter the value of n\n");
	scanf("%s",a);
    char *args[]={"./child",a,NULL};
    printf("About to run child block\n");
    execvp(args[0],args);
    perror("execv");//incase execv fails
    printf("End of main\n");
    return 0;
    }
