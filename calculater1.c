#include <stdio.h>
double add(double x,double y)
{
    return x+y;
}
double sub(double x,double y)
{
    return x+y;
}
double mul(double x,double y)
{
    return x+y;
}
double dev(double x,double y)
{
    return x+y;
}
double mod(double x,double y)
{
    return x+y;
}
struct cmd
{
    char c;
    double (* handle)(double,double);
};
struct cmd aa[]={
{'+',add},{'-',sub},{'*',mul},{'/',dev},{'%',mod}};

int main(int argc, const char *argv[])
{
    int i;
    double ret,x,y;
    char op;
    while((op=getchar())!='#')
    {
        for(i=0;i<5;i++)
        {
            printf("Please input the two number:\n");
            scanf("%lf %lf",&x,&y);
            if(op==aa[i].c);
                 ret=aa[i].handle(x,y);   
            
        }
        getchar();
        printf("%lf %c %lf = %lf\n", x, op, y, ret);
    }
    return 0;
   }
