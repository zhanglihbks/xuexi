#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 123456;
    char b = 127;
    a = (char)a;
    printf("%d,%d\n",a,b);
    return 0;
}
