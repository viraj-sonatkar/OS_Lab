#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<wait.h>
#include<stdlib.h>


int main() {
    int pipedes[2];        // for pipes. One is used [0] is used to read and [1] for write

    int child;
    char string[100], buffer[200];

    pipe(pipedes);

    if((child = fork()) < 0) {
        perror("Error in forking.");
        exit(1);
    }

    FILE *fp;

    int bytesread;

    char var[100];          // take string from file and put it in var

    if (child != 0) {
        printf("Parent is pid number : %d\n", getpid());

        // Child process closes input side
        close(pipedes[0]);

        fp = fopen("string.txt", "r");

        // take input from file

        while(fscanf(fp, "%s\n", string) != EOF) {
            strcat(var, string);
            strcat(var," ");
        }

        // Now send string through the output side of the pipe which is [1]
        write(pipedes[1], var, (strlen(var) + 1));
        close(pipedes[1]);

        waitpid(child, NULL, 0);

    } else {
        printf("This is the child with pid: %d\n", getpid());

        // parent process blocks the output side of the pipe
        close(pipedes[1]);

        bytesread = read(pipedes[0], buffer, sizeof(buffer));
        printf("Received string from parent is : %s\n", buffer);

        // close all the ends after the required task is done.
        close(pipedes[0]);

    }

    return 0;
}
