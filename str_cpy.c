#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
   char a[256]="Hello";
   strcpy(a+1,a);
   puts(a);
    return 0;
}//A segment fault will be happen
