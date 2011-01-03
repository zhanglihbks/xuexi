#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    char ch,filename[10];
    scanf("%s",filename);
    if((fp = fopen(filename,"w")) == NULL)
    {
        printf("Can't open file\n");
        exit(0);
    }
    ch = getchar();
    ch = getchar();
    while(ch != '#')
    {
        fputc(ch,fp);
        putchar(ch);
        ch = getchar();
    }
    fclose(fp);
    return 0;
}
