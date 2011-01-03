#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *f1,*f2;
    int n;
    char a[100],c;
    f1 = fopen("file1.txt","r");
    f2 = fopen("file3.txt","w");
    n=fread(a,1,100,f1);
    fputs(a,f2);

    //printf("%s",a);
    //printf("%d\n",n);
    //fwrite(a,5,1,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}
