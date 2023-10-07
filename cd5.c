/*
#include<stdio.h>

#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char* type(char[],int);
int main()
{
char a[10],b[10],mess[20],mess1[20];
int i,l;
printf("\n\n int a,b;\n\n int c=a+b\n");
printf("\n\n Enter a value for a\n");
scanf("%9s",a);
l=strlen(a);
printf("\n a is:");
strcpy(mess,type(a,l));
printf("%s",mess);
printf("\n\n Enter a value for b\n\n");
scanf("%9s",b);
l=strlen(b);
printf("\n b is:");
strcpy(mess1,type(b,l));
printf("%s",mess1);
if(strcmp(mess,"int")==0 && strcmp(mess1,"int")==0)
{
printf("\n\n No Type Error");
}
else
{
printf("\n\n Type Error");
}
return 0;
}
char* type(char x[],int m)
{

int i; char mes[20];
for(i=0;i<m;i++)
{
if(isalpha(x[i]))
{
strcpy(mes,"AlphaNumeric");
goto x; }
else if(x[i]=='.')
{ strcpy(mes,"float"); goto x; }
} strcpy(mes,"int");
x:return mes;
}
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int type(char[]);

int main()
{
    char a[10], b[10];
    int type_a, type_b;

    printf("\n\n int a,b;\n\n int c=a+b\n");
    printf("\n\n Enter a value for a\n");
    scanf("%9s", a); // Limit input to the size of the array
    type_a = type(a);
    
    printf("\n\n Enter a value for b\n\n");
    scanf("%9s", b); // Limit input to the size of the array
    type_b = type(b);

    printf("\n a is: %s", a);
    printf("\n b is: %s", b);

    if (type_a == type_b)
    {
        printf("\n\n No Type Error");
    }
    else
    {
        printf("\n\n Type Error");
    }

    return 0;
}

int type(char x[])
{
    char *endptr;
    strtod(x, &endptr); // Try to convert to double

    if (*endptr == '\0')
    {
        return 2; // It's a float
    }
    else if (isdigit(x[0]) || (x[0] == '-' && isdigit(x[1])))
    {
        return 1; // It's an int
    }
    else
    {
        return 0; // It's neither int nor float
    }
}

