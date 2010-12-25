#include <stdio.h>
#include <string.h>
struct cmd
{
    char *command[8];
    char *in;
    char *out;
};
struct cmd g_cmd;
int parse(char *a)
{
    char *p = a;
    int n=0;
    g_cmd.in = g_cmd.out = NULL;
    while(*p != '\0')
    {
        if(*p == ' ')
        {
            *p = '\0';
            p++;
            continue;
        }
        if(*p == '>')
        {
           p++;
           while(*p++ == ' ');
           g_cmd.out = --p;
        }
        if(*p=='<')
        {
            p++;
            while(*p++ == ' ');
            g_cmd.in = --p;
        }
        if(*(p-1)=='\0'||p==a)//the program run here,the *p can't b
        {                     //e ' '
            g_cmd.command[n++]=p;//in command[],the first is comman
            p++;                //d,and others is arguments
            continue;
        }
        p++;//why?---such ls -all .. when p is pointed to s
    }
    g_cmd.command[n] = NULL;
    return 0;
}
void show(void)
{
    int i;
    char *p;
    for(i=0;i<8;i++)
    {
        p=g_cmd.command[i];
        if(p==NULL)
            break;
        if(i==0)
            printf("Command: %s\n",p);
        else
            printf("argument: %s\n",p);
    }
    //printf("%s","\n");
    if(g_cmd.in||g_cmd.out)
        printf("in-files:%s,out-files:%s\n",g_cmd.in,g_cmd.out);
}
int main(int argc, const char *argv[])
{
    char a[256]; /* "   la -all > aa.txt";*/
    while(1)
    {
        fgets(a,256,stdin);
        a[strlen(a)-1]='\0';//the fgets will change the '\0' at the
        parse(a);           //end of the string to '\n',we do so to
        show();             //change it back
    }
    return 0;
}
