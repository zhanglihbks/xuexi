#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *f1,*f2;
    char c;
    f1 = fopen("file1.txt","r");
    f2 = fopen("file2.txt","w");
    while(!feof(f1))
    {
        printf("%c",c);
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
