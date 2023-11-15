#include "get_next_line.h"

int main()
{
    int i = 3;
    char *str;
    int fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    str = get_next_line(fd);
    printf("%s",str);
    free(str);
    close(fd);
}
