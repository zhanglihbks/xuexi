#include <stdio.h>
#include <string.h>
void multi(void)
{
    int a,b;
    puts("Please input a b:");
    scanf("%d %d",&a,&b);
    int sum=0,n=32;
    printf("%d*%d=",a,b);
    while(n--)
    {
        if(b&1)
            sum+=a;
            a=a<<1;
            b=b>>1;
    }
    printf("%d\n",sum);
}

int dec_bin(void)
{
    int c=0,n=0,a,d;
    puts("Input a number:");
    scanf("%d",&a);
    d = a;
    while(1)
    {
        c+=(a&0x80000000);
        if(c!=0)
        break;
        a = a<<1;
        n++;
    }
    printf("Decimal %d change to binary is: ",d);
    putchar('1');
    a = a<<1; while(32-n-1)
    {
        c = a&0x80000000;
        if(c == 0)
            putchar('0');
        else
            putchar('1');
        a = a<<1;
        n++;
    }
    putchar('\n');
    return 0;
}

void low_up(void)
{
    char a[20],*p;
    int n=0;
    p=a;
    puts("Please input a string: ");
    scanf("%s",a);
    n=strlen(a);
    while(n--)
    {
        if(*p>='a'&&*p<='z')
            *p=*p-32;
        else
            *p=*p+32;
        p++;
    }
    puts(a);
}

void encryption(void)
{
    char ch,c='&',d;
    puts("Please input a char :");
    scanf("%c",&ch);
    d=ch;
    ch=ch^c;
    if((ch>=48&&ch<=57)||(ch>=65&&ch<=91)||(ch>=97&ch<=122))
        printf("After encryption ,%c\n",ch);
    else
        printf("The %c after encryption not a common char.\n",d);
    
}

void display_menu(void)
{
    int n=6;
    char *a[6],**p;
    p=a;
    a[0]="1.decimal to binary";
    a[1]="2.x*y";
    a[2]="3.low to binary";
    a[3]="4.encryption";
    a[4]="5.exit";
    a[5]="please choose [1-5]";
    while(n--)
        puts(*p++);
}

int main(int argc, const char *argv[])
{
    int n=0;
    //char *a[]={"1.decimal to binary","2.x*y","3.low to binary","4.encryption","5.exit","please choose [1-5]"};
    //dec_bin();
    //multi();
    //low_up();
    //encryption();
    while(1)
    {
        display_menu();
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1:
                dec_bin();
                break;
            case 2:
                multi();
                break;
            case 3:
                low_up();
                break;
            case 4:
                encryption();
                break;
            case 5:
                return 0;
        }
    }
    encryption();
    return 0;
}
