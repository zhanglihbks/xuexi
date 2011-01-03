#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *f1,*f2;   
    char *name="zhang";
    int chi=90,math=89,average=87;
    int a=0,b=0,c=0;
    char d[10];
    f1 = fopen("file1","w");
    fprintf(f1,"%s,%d,%d,%d",name,chi,math,average);
    fclose(f1);
    fflush(f1);
    f2=fopen("file1","r");
    fscanf(f2,"%s,%d,%d,%d",d,&a,&b,&c);
    printf("%s,%d,%d,%d\n",d,a,b,c);
    fclose(f2);
    return 0;
}
