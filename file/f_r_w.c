#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[10];
    int num;
    int age;
    char addr[15];
}stu_t;

stu_t std[4];

int save(void)
{
    FILE *fp;
    int i;
    if((fp = fopen("stu_list","w")) == NULL)
    {
        printf("Can't open file.\n");
        return 0;
    }
    for(i = 0;i < 4;i++)
    {
        if(fwrite(&std[i],sizeof(stu_t),1,fp) != 1)
            printf("File write error\n");
    }
    fclose(fp);
    return 0;
}

void f_read(void)
{
    int i;
    FILE *fp;
    fp = fopen("stu_list","r");
    for(i = 0;i < 4;i++)
    {
        fread(&std[i],sizeof(stu_t),1,fp);
        printf("%-10s %4d %4d %-15s\n",std[i].name,std[i].num,std[i].age,std[i].addr);
    }
    fclose(fp);
}

int main(void)
{
    int i;
    for(i = 0;i < 4;i++)
        scanf("%s%d%d%s",std[i].name,&std[i].num,&std[i].age,std[i].addr);
    save();
    f_read();
    return 0;
}
