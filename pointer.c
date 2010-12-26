//This is a example about function and pointer
#include <stdio.h>
int mul(int a,int b)
{
    return a*b;
}   
int main(int argc, const char *argv[])
{
    int (* fun)(int,int);//apply a space in memory
    fun = mul;
    int c,d;
    c = (* fun)(2,4);
    printf("%d\n",mul(2,4));
    d=mul(2,4);
    printf("c=%d\n",c);
    printf("d=%d\n",d);
    return 0;
}
