#include <stdio.h>

int main(void)
{
    FILE *ptr = fopen("file.txt","r");
    char buffer[10];
    fread(ptr, buffer,6);
}