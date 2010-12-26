#include <stdio.h>

    struct stu_t{
    char name[10];
    int id;
    int score;
    void (* fun_t)(void);
    };
void print1(void)
{
    putchar('*');
}

void print2(void)
{
    putchar('#');
}
int main(int argc, const char *argv[])
{
    int i;
    struct stu_t stu[5];
    //={
        //{"num1",1,87},
        //{"num2",2,90},
        //{"num3",3,79},
        //{"num4",4,97},
        //{"num5",5,84}};
    for(i = 0;i < 5;i++)
    {
        scanf("%s %d %d",stu[i].name,&stu[i].id,&stu[i].score);
    }
    for(i=0;i<5;i++)
    {
        printf("%s %d %d ",stu[i].name,stu[i].id,stu[i].score);
        if(i%2==0)
        {
            stu[i].fun_t=print1;
            stu[i].fun_t();
            putchar('\n');
        }   
        else
        {
            stu[i].fun_t=print2;
            stu[i].fun_t();
            putchar('\n');
        }   
        
    }
    return 0;
}
