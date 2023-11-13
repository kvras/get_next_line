#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    FILE *ptr;
    ptr = fopen("hhhh.txt","w");  //ila derti gha smiya ghaysawbo fnfss directory labghiti blassa khra dir lpath
    fd = fileno(ptr);
    printf("%d\n",fd);
    //fclose(ptr);
    fd = open("hhh.txt",O_WRONLY);
    printf("%d\n",fd);
    close(fd);
}