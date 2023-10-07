#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pm();
void plus();
void my_div();
int i,ch,j,l;
char ex[10],ex1[10],exp1[10],ex2[10];
int main()
{
while(1)
{
printf("\n 1.Assignment\n 2.Arithmatic\n 3.exit\n ENTER THE CHOICE:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n enter the expression with assignment operator:");
scanf("%s",ex1);
l=strlen(ex1);
ex2[0]='\0';
i=0;
while(ex1[i]!='=')
{
i++;
}
strncat(ex2,ex1,i);
reverseString(ex1);
exp1[0]='\0';
strncat(exp1,ex1,l-(i+1));
reverseString(exp1);
printf("3 address code:\n temp=%s \n %s=temp\n",exp1,ex2);

break;

case 2:
printf("\n enter the expression with arithmatic operator:");
scanf("%s",ex);
strcpy(ex1,ex);
l=strlen(ex1);
exp1[0]='\0';
for(i=0;i<l;i++)
{
if(ex1[i]=='+'||ex1[i]=='-')
{
if(ex1[i+2]=='/'||ex1[i+2]=='*')
{
pm();
break;
}
else
{
plus();
break;
}
}
else if(ex1[i]=='/'||ex1[i]=='*')
{
my_div();
break;
}
}
break;

/*}
}
break;*/

case 3:

exit(0);
}
}
}

void reverseString(char str[]) {
    int length = strlen(str);
    int i, j;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void pm()
{
reverseString(exp1);
j=l-i-1;
strncat(exp1,ex1,j);
reverseString(exp1);
printf("3 address code:\n temp=%s\n temp1=%c%c temp\n",exp1,ex1[j+2],ex1[j]);
}
void my_div()
{
strncat(exp1,ex1,i+2);
printf("3 address code:\n temp=%s\n temp1=temp%c%c\n",exp1,ex1[l+2],ex1[i+3]);
}
void plus()
{
strncat(exp1,ex1,i+2);
printf("3 address code:\n temp=%s\n temp1=temp%c%c\n",exp1,ex1[l+2],ex1[i+3]);
}
