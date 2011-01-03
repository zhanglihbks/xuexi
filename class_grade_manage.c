#include <stdio.h>

typedef struct stu
{
    unsigned id;
    char name[20];
    float chi;
    float math;
    float average;
    struct stu *next;
}stu_t;

//typedef struct stu1
//{
    //unsigned id;
    //char name[20];
    //float chi;
    //float math;
    //float average;
    //struct stu *next;
//}stu1_t;

stu_t stu[50];
//stu1_t stu1[50];

void menu_display(void)
{
    char *a[8],**p;
    int i;
    a[1]="1.Create student information file";
    a[2]="2.Display all student's info";
    a[3]="3.Sort by average";
    a[4]="4.Insert a new info";
    a[5]="5.Delete a record";
    a[6]="6.Quit";
    a[7]="Please input your choice:";
    a[0]="Please select the option:";
    p=a;
    for(i=0;i<8;i++)
    {
        puts(*p++);
    }
   *p= *p-1;
}

/*create a file with student's infomation*/
int cre_stu_info()
{
    FILE *fp;
    int i,n = 0;
    printf("Please input the amount of students: ");
    scanf("%d",&n);
    getchar();
    if((fp = fopen("stu_info.txt","w")) == NULL)
    {
        printf("Can't open the file\n");
        return 0;
    }
    printf("Please input students' information:\n");
    for(i = 0;i < n;i++)
    {
        scanf("%d%s%f%f%f",&stu[i].id,stu[i].name,&stu[i].chi,
                            &stu[i].math,&stu[i].average);
        fprintf(fp,"%d %s %.1f %.1f %.1f\n",stu[i].id,stu[i].name
                        ,stu[i].chi,stu[i].math,stu[i].average);
    }
    for(i = 0;i < n;i++)
    {
        printf("%d %s %f %f %f\n",stu[i].id,stu[i].name,stu[i].chi,stu[i].math,stu[i].average);
    }
    fclose(fp);
}

stu_t * creat_l_list()
{
    FILE *fp;
    stu_t *head = NULL,*p1,*p2;
    p1 = stu;
    int i = 0;
    fp = fopen("stu_info.txt","r");
    while(1) 
    {
        fscanf(fp,"%d %s %f %f %f",
            &(p1->id),p1->name,&(p1->chi),
            &(p1->math),&(p1->average));
        i++;
        if(i == 1)
        {
            head = p1;    
            p2 = p1;
            head->next = NULL;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
            p1->next = NULL;
        }
        if(feof(fp))
            return head;
        else
            p1++;
    }
}

void travel(stu_t *head)
{
    stu_t *p;
    p = head;
    while(p != NULL)
    {
        printf("%d %s %f %f %f\n",p->id,p->name,
            p->chi,p->math,p->average);
        p = p->next;
    }
}

int main(int argc, const char *argv[])
{
    stu_t *head;
    //menu_display();
    cre_stu_info();
    //head = creat_l_list();
    //travel(head);
    return 0;
}
