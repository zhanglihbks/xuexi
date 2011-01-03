#include <stdio.h>
#include <stdarg.h>
int sum(char *format,...)
{
    int *p;
    int sum;
    va_list ap;
    va_start(ap,format);
    p=va_arg(ap,int);
    sum+=p;
    p=va_arg(ap,int);
    sum+=p;
    p=va_arg(ap,int);
    sum+=p;
    va_end(ap);
    return sum;
}

int main(int argc, const char *argv[])
{
    int sum1;
    sum1 = sum(" ",1,2,3);
    return 0;
}
