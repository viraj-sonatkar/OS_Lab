#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include  <string.h>
int main(int argc, char *argv[]){
    int i = atoi(argv[1]);
    int a[i];
    a[0]=1;
    a[1]=1;
    for(int j=2;j<i;j++){
        a[j]=a[j-1]+a[j-2];
    }
    for(int j=0;j<i;j++){
        printf("%d ",a[j]);
    }
    printf("\nChild done\n\n");
    return 0;
}
