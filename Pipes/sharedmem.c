#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

void palindrome(char* string) {
    
    char reversal[strlen(string)];

    int length = strlen(string);

    for (int i=0; i<length;i++) {
        reversal[i] = string[length-i-1];
    }

    printf("%s\n", reversal);

    if(strcmp(reversal, string) == 0) {
        printf("\n It is a palindrome\n");
    } else {
        printf("It is not a palindrome\n");
    }
}

int main(void) {
    int fd[2], nbytes;

    pid_t child;

    char string[] = "abbab";
    char readbuffer[80];

    pipe(fd);

    if((child = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if(child==0) {
	close(fd[0]);
    	printf("Sending string: ' %s '\n", string);
	write(fd[1], string, strlen(string) + 1);
	exit(0);	
    } else {
    	close(fd[1]);
	nbytes = read(fd[0], readbuffer, sizeof(readbuffer));

	palindrome(readbuffer);
	printf("\nReceived String: %s\n", readbuffer);
    }

    return 0;
}


