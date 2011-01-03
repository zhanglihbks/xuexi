#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *f1,*f2;
    char c;
    char a[100];
    while(argc!=3)
        return 1;
    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"w");
    while(!feof(f1))
    {
        
        fread(a,1,1,f1);
        if(feof(f1))//if without the if sentence,it will read more than a byte
            break;
        fwrite(a,1,1,f2);
        //fgets(a,100,f1);
        //fputs(a,f2);
    }
    //fwrite(a,1,100,f2);//this is wrong
    //while((c=fgetc(f1))!=EOF)
        //fputc(c,f2);
        //fclose(f1);
        //fclose(f2);
    return 0;
}
