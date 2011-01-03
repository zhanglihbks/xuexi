#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu
{
    int id;
    char name[10];
    struct stu *next;
}stu_t;

stu_t *creat(stu_t *p,int id,char *name)
{
    stu_t *p1;
    p1 = (stu_t *)malloc(sizeof(stu_t));
    p1->id = id;
    strcpy(p1->name,name);
    p1->next = p;
    return p1;
}

/*stu_t *insert(stu_t *p,stu_t *p1)
{
    p->next=p1;
    if(p1->next!=NULL)
        p1->next = NULL;
}*/

stu_t *link_sort(stu_t *head,int n)
{
    stu_t *p1,*p2,*min,*head1;
    head1 = NULL;
    while(1)
    {
        min = p2 = p1 = head;
        while(p1->next!=NULL)
        {
            if(min->id > p1->next->id)
            {
                p2 = p1;
                min = p1->next;
            }
            p1 = p1->next;
        }
        if(min==head)//if n=3,when n=
            head=head->next;

        head1 = creat(head1,min->id,min->name);
        p2->next=p2->next->next;
        n--;
        if(n==1)
        {
            head1 = creat(head1,head->id,head->name);
            break;
        }
    }
    return head1;
}

void travel(stu_t *head)
{
    stu_t *p1;
    p1=head;
    while(p1!=NULL)
    {
        printf("%d,%s\n",p1->id,p1->name);
        p1 = p1->next;
    }
}

int main(int argc, const char *argv[])
{
    stu_t *head,*head1;
    head = creat(NULL,6,"zhang");
    head = creat(head,2,"li");
    head = creat(head,4,"wang");
    head = creat(head,3,"xiao");
    head = creat(head,5,"jin");
    head = creat(head,8,"liang");
    head = creat(head,7,"chen");
    head = creat(head,1,"dong");
    head1 = link_sort(head,8);
    travel(head1);
//    travel(head);
    return 0;
}
