#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *f1;
    char ch;
    f1=fopen("fil1","w");
    fputc('c',f1);//c point to the end of the file
    fclose(f1);
    f1=fopen("fil1","r");
    while((ch=fgetc(f1))!=EOF)
    {
        putchar(ch);
    }
    fclose(f1);
    return 0;
}
