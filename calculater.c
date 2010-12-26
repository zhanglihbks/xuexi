#include <stdio.h>
double add(double a,double b)
{
    return a+b;   
}
double minus(double a,double b)
{
    return a-b;
}
double mul(double a,double b)
{
    return a*b;
}
double devide(double a,double b)
{
    return a/b;
}

int main(int argc, const char *argv[])
{
    char c;
    double num1,num2,num3;
    double (* fun1)(double ,double);
    while((c = getchar()) != '#')
    {
       switch(c)
       {
            case '+':
                {
                    fun1=add;
                    printf("Please input the two number:");
                    scanf("%lf %lf",&num1,&num2);//lf is different from f there
                    printf("The sum of num1 and num2 is %f .\n",(*fun1)(num1,num2));
                }break;
            case '-'://notice the ' '
                {
                    fun1=minus;
                    printf("Please input the two number:");
                    scanf("%lf %lf",&num1,&num2);
                    printf("The diff of num1 and num2 is %f .\n",(*fun1)(num1,num2));
                }break;
                

            case '*':
                {
                    fun1=mul;
                    printf("Please input the two number:");
                    scanf("%lf %lf",&num1,&num2);
                    printf("The accumulate of num1 and num2 is %f .\n",(*fun1)(num1,num2));
                }break;


            case '/':
                {
                    fun1=devide;
                    printf("Please input the two number:");
                    scanf("%lf %lf",&num1,&num2);
                    printf("The division of num1 and num2 is %f .\n",(*fun1)(num1,num2));
                }break;
       }
    }
    return 0;
}
