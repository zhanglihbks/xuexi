#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    if((fp=fopen("textfile","r+")) == NULL)
    {
        perror("Open file textfile");
        exit(1);
    }
    if(fseek(fp,10,SEEK_SET) != 0)
    {
        perror("Seek file textfile");
        exit(1);
    }
    fputc('K',fp);
    fclose(fp);
    return 0;
}

