#include <stdio.h>
void my_printf(char *format,...)
{
   int *p,i; 
   p=(int *)(&format);
   for(i=0;i<3;i++)
   {
        p=p+1;
        printf("%s\n",(char *)(*p));
   }
}

int main(int argc, const char *argv[])
{
    my_printf(" ","how", "are","you");
    return 0;
}
