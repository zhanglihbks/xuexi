#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *in,*out;
    char ch,infile[10],outfile[10];
    printf("Enter the infile name:\n");
    scanf("%s",infile);
    printf("Enter the outfile name:\n");
    scanf("%s",outfile);
    if((in = fopen(infile,"r")) == NULL)
    {
        printf("Can't open infile\n");
        exit(0);
    }
    if((out = fopen(outfile,"w")) == NULL)
    {
        printf("Can't open outfile\n");
        exit(0);
    }
    while(1)
    {
        ch = fgetc(in);
        if(feof(in))
            break;
        fputc(ch,out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
