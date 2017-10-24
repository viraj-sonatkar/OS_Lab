#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define RD_END 0
#define WR_END 1 

int main(void)
{
        int     fd[2];
        char    *readbuffer= calloc(1,1024);
        pid_t childpid; 

        pipe(fd);

        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[RD_END]);
                dup2(fd[WR_END],1);          
                system("ls");
                exit(0);
        }
 
        else
        {                  
                wait(NULL);
                int i=0,j=0;
                int wordcount=0,charcount=0,linecount=0;
                close(fd[WR_END]);                 
                while((j=read(fd[RD_END], readbuffer, sizeof(readbuffer))) > 0)
                {       
                        i=0;
                        while(i<j)
                        {
                            printf("%c", readbuffer[i]);
                                if(readbuffer[i]== ' ')
                                {
                                    ++wordcount;
                                }                                
                                if(readbuffer[i]== '\n')
                                {
                                    readbuffer[i]=' ';
                                    ++wordcount;
                                    ++linecount;
                                }
                                if(readbuffer[i] != '\n')
                                    ++charcount;
                                ++i;
                        }                               
                }
                printf("charcount=%d\nwordcount=%d\nlinecount=%d\n",charcount,wordcount,linecount);
                close(fd[RD_END]);      
        }
        return(0);
}