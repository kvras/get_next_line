#include "get_next_line.h"

int main()
{
    // int i = 3;
    char *str;
    int fd = open("multiple_nlx5.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("%s",str);
        free(str);
    }
    str = get_next_line(fd);
    printf("%s\n",str);
    close(fd);
    while (1);
    
}