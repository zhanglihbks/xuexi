#include <stdio.h>
#include <string.h>
int parse(char *a)
{
    char *p=a;
    int n=strlen(a);
    int i,k=0,z=0;
    char c[10][8];
    for(i=0;i<n;i++)
    {
       if(*(p+i)==' ')
            break;
        if(*(p+i)==' '&&*p!=' ')
            k++;
       if(*(p+i-1) == ' '||p = a)
       {
            c[k][i-z]='\0';
            z=i;
        }
    }
    puts("show the command:\n");
    printf("command:%s\n",c[0]);
    for(i=1;i<k;i++)
    {
        if(c[i][0]!='>'&&c[i][0]!='<')
        {
            printf("argument %s \n",c[i]);
        }
        else
        {
            if(c[i][0]=='>')
                printf("out-file:%s\n",c[i+2]);
            else
                printf("in-file :NULL\n");
        }
    }
    //while(*p!='\0')
    //{
       //if(*p!=' ')
        //p++;
       //else
       //{
           //*p='\0';
           //p++;
       //}
    
}
int main(int argc, const char *argv[])
{
    char *a="ls -all > out";
    parse(a);
    return 0;
}
