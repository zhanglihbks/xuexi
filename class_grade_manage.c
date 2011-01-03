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

stu_t stu[50];

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
int cre_stu_info(int n)
{
    FILE *fp;
    int i;
    if((fp = fopen("stu_info.txt","w")) == NULL)
    {
        printf("Can't open the file\n");
        return 0;
    }
    printf("Please inpu students' information\n");
    for(i = 0;i < 6;i++)
    {
        scanf("%d%s%f%f%f",&stu[i].id,stu[i].name,&stu[i].chi,&stu[i].math,&stu[i].average);
        if(fwrite(&stu[i],sizeof(stu_t),1,fp) != 1)
            printf("File write error\n");
    }
    fclose(fp);
}

int main(int argc, const char *argv[])
{
    menu_display();
    cre_stu_info(6);
    return 0;
}
