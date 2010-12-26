#include <stdio.h>
void print_star(void)
{
    putchar('*');
}
void print_matrix(int width)
{
    int i,j;
    void (* fun)(void);
    fun = print_star;
    for(i=0;i<width;i++)
        {
            for(j=0;j<width;j++)
            (* fun)();//not write as (* fun)(void)),it's wrong
            putchar('\n');
        }
}
int main(int argc, const char *argv[])
{
    int n;
    void (* fun1)(int);
    fun1 = print_matrix;
    printf("Please input the number:");
    scanf("%d",&n);
    (* fun1)(n);
    return 0;
}
