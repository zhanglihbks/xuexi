#include <stdio.h>
typedef struct stu
{
    char id;
    char math;
    char name[10];
    struct *next;
}stu_t;

stu_t *cread(void)
{
    int n=0;
    stu_t *head,*p1,*p2;
    p1=p2=(stu_t *)malloc(sizeof(stu_t));
    scanf("%d,%d,%s",&p1->id,&p1->math,name);
    head=NULL;
    while(p1->id != 0)
    {
        n++;
        if(n==1)
        head=p1;
        else
            p2->next=p1;
    }
}

int main(int argc, const char *argv[])
{
    mystruct_t 
    return 0;
}
