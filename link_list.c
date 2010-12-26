#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
    int id;
    int Chinese;
    char name[10];
    struct stu *next;
};
struct stu  *creat(struct stu *pro,int id,int Chinese,char *name)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->id = id;
    p->Chinese = Chinese;
    strcpy(p->name,name);
    p->next = NULL;
    pro->next = p;
    return p;
}
void travel(struct stu *head)
{
    struct stu *p;
    p = head;
    while(p != NULL)
    {
        printf("%d %d %s\n",p->id,p->Chinese,p->name);
        p = p->next;
    }
}
struct stu *delete(struct stu *head,int id)
{
    struct stu *p2,*p3;
    p2 = head;
    if(p2->id == id)
    {
        p2 = p2->next;    
        free(head);
       head = NULL;
       while(p2!=NULL)
       {
     printf("%d %d %s\n",p2->id,p2->Chinese,p2->name);
       p2 = p2->next;
       }
        return p2;
    }
    while(p2->next != NULL)
    {
        if(p2->next->id==3)
        {
            p3 = p2->next;
            p2->next = p2->next->next;
            free(p3);
        }
        printf("%d %d %s\n",p2->id,p2->Chinese,p2->name);//it is wrong to writ 
        p2 = p2->next;          //the two sentence in opposite order
    }
    return head;
}

struct stu *insert_next(struct stu *head,int n,int id,int Chinese,char *name)
{
     struct stu *aa,*p,*p1;
     aa=(struct stu *)malloc(sizeof(struct stu));
     int i;
     p=p1= head;
     aa->id = id;
     aa->Chinese = Chinese;
     strcpy(aa->name,name);
     for(i=1;i<n;i++)
        p = p->next;
    aa->next = p->next->next;
    p->next = aa;
    while(p1!=NULL)
    {
        printf("%d %d %s\n",p1->id,p1->Chinese,p1->name);
        p1 = p1->next;
    }
}

int main(int argc, const char *argv[])
{
    struct stu *head,*p1,*p2,*p3;
    //int i,id,Chinese;
    char name[10];
    head = (struct stu *)malloc(sizeof(struct stu));
    head->id = 1;
    head->Chinese =97;
    strcpy(head->name,"wang");
    head->next = NULL;
    p1 = creat(head,2,87,"zhang");
    p1 = creat(p1,3,87,"zhang");
    p1 = creat(p1,4,87,"zhang");
    p1 = creat(p1,5,87,"zhang");
    p1 = creat(p1,6,87,"zhang");
    p1 = creat(p1,7,87,"zhang");
    p1 = creat(p1,8,87,"zhang");
    p1 = creat(p1,9,87,"zhang");
    p1 = creat(p1,14,87,"zhang");
    //travel(head);
    //p1 = head;
    //for(i = 0;i < 10;i++)
    //{
        //scanf("%d%s",&Chinese,name);
        //creat(p1,i+2,Chinese,name);
    //}
    travel(head);
 /*   p2 = head;
    while(p2->next != NULL)
    {
        if(p2->next->id==3)
        {
            p3 = p2->next;
            p2->next = p2->next->next;
            free(p3);
        }
    printf("%d %d %s\n",p2->id,p2->Chinese,p2->name);
        p2 = p2->next;
    }*/
    //head =  delete(head,1);
    insert_next(head,5,4,89,"lisi");
    return 0;
}
