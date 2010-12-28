#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
    int id;
    struct stu *next;
}stu_t;

stu_t *creat(int id,stu_t *p)
{
    stu_t *p1;
    p1 = (stu_t *)malloc(sizeof(stu_t));
    p1->id = id;
    p1->next = p;
    return p1;
}

void travel_loop(stu_t *p,int n)
{
    int i=0;
    while(1)
    {
        printf("%d\n",p->id);
        p = p->next;
        i++;
        if(i==n)
        break;
    }
}
void josephus(stu_t *head,int n)
{
    stu_t *p;
    int m=1,k=0;;
    p = head;
    while(p!=p->next)
    {
        m++;
        if(m==n)
        {
            k++;
            printf("%d: %dout  ",k,p->next->id);
            if(k%5==0)
                putchar('\n');
            p->next=p->next->next;
            m = 1;
        }
        p = p->next;
    }
    printf("%d: %dout  \n",k+1,p->id);
    putchar('\n');
}
int main(int argc, const char *argv[])
{
    stu_t *head,*p;
    int i=1;
    head = p = creat(1,NULL);
    for(i=100;i>1;i--)
    {
        p = creat(i,p);
    }
    //p = creat(3,p);
    //p = creat(4,p);
    //p = creat(5,p);
    //p = creat(6,p);
    head->next = p;
    //travel_loop(head,100);
    josephus(head,3);
    return 0;
}
