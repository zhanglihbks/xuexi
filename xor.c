#include <stdio.h>

void get_bit(int a,int bn)
{
    int i;
    char c;
    for(i = 0;i<bn;i++)
    {
        c = a&1;
        putchar(c);
        putchar(' ');
        a=a<<1;
    }
}

int main(int argc, const char *argv[])
{
    int a = -9;
    //int c,i;
    //for(i = 0;i<32;i++)
    //{
        //c = a&0x80000000;
        //if(c==0)
            //putchar('0');
        //else
            //putchar('1');
        //putchar(' ');
        //a=a<<1;
    //}
    get_bit(a,16);
    putchar('\n');
    return 0;
}
