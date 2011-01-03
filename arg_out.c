#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void m(char **x)
{
    char *p=(char *)malloc(4);
    strcpy(p,"cde");
    *x=p;
    printf("%s\n",*x);
}

int main(int argc, const char *argv[])
{
    char *q="abc";
    m(&q);
    printf("%s\n",q);
}
