#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu
{
    int id;
    int math;
    char name[10];
    struct stu *next;
}stu_t;
int n=0;

stu_t * creat(void)
{
    stu_t *head,*p1,*p2;
    p1=p2=(stu_t *)malloc(sizeof(stu_t));
    printf("Please input the student's information:\n");
    scanf("%d,%d,%s",&p1->id,&p1->math,p1->name);
    head=NULL;
    while(p1->id != 0)
    {
        n++;
        if(n==1)
        head=p1;
        else
            p2->next=p1;
        p2=p1;
        p1=(stu_t *)malloc(sizeof(stu_t));
        scanf("%d,%d,%s",&p1->id,&p1->math,p1->name);
    }
    p2->next=NULL;
    return(head);
}

void print(stu_t * head)
{
    stu_t *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d %d %s\n",p->id,p->math,p->name);
        p=p->next;
    }
}

stu_t *del(stu_t *head,int id)
{
    stu_t *p1,*p2;
    if(head==NULL)
    {
        puts("\nList null.\n");
        return NULL;
    }
    p1=head;
    while(p1->id!=id&&p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->id==id)//the last id can also be delet 
    {
        if(p1==head)
            head=p1->next;
        else
            p2->next=p1->next;//p2 is the previous point of p1
        printf("delete:%d\n",id);
        n=n-1;
        free(p1);
    }
    else//can't find  id,but p1->next is NULL
        printf("%d not been found!\n",id);
    return(head);
}

stu_t *insert(stu_t *head,int id,int math,char *name)
{
    stu_t *p1,*p2,*p3;
    p1=head;
    p2=(stu_t *)malloc(sizeof(stu_t));
    p2->id=id;
    p2->math=math;
    strcpy(p2->name,name);
    if(head==NULL)
    {
        head=p2;
        p2->next=NULL;
    }
    else
    {
        while(p1->id<id&&p1->next!=NULL)
        {
            p3=p1;
            p1=p1->next;
        }
        if(p1->id>=id)
        {
            if(head==p1)
                head=p2;
            else
                p3->next=p2;
            p2->next=p1;
        }
        else
        {
            p1->next=p2;
            p2->next=NULL;
        }
        n=n+1;
        return(head);
    }
}

int main(int argc, const char *argv[])
{
    stu_t *head,*p;
    int a;
    head=creat();
    p=head;
    print(head);
    //printf("Please input the id you want to del:\n");
    //scanf("%d",&a);
    //head=del(head,a);
    //print(head);
    head=insert(head,3,98,"wang");//Please notice the insert have a
    print(head);// return value,so write as insert(),is wrong
    return 0;
}
