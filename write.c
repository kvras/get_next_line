#include <stdio.h>

int main(void)
{
    FILE *ptr;
    ptr = fopen("file.txt","w");
    fprintf(ptr,"erreur");
    fclose(ptr);
    ptr = fopen("file.txt","a");
    fprintf(ptr,"awa3allah aykhdem");
    fclose(ptr);
}