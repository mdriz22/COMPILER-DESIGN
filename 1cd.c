#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct sym_tab
{
char symbol[20];
char type[20];
int length;
};
struct sym_tab s[10];
int n=0;
int main()
{

int ch;
void insert();
void del();
void disp();
void search();
void modify();
do
{
printf("\n1.insert\n2.delete\n3.display\n4.search\n5.modify\n6.exit\n");
printf("\n enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: del();
break;
case 3: disp();
break;
case 4: search();
 break;
case 5: modify();
break;
default: break;
}
}while(ch<6);
}
void insert()
{
char name[20],data[20];
int leng,i,k,length;
printf("enter newsymbol,datatype,length\n");
scanf("%s%s%d",name,data,&leng);
for(i=0;i<n;i++)
if(strcmp(name,s[i].symbol)==0)
{
printf("duplicate entry\n");
return;
}
strcpy(s[n].symbol,name);
strcpy(s[n].type,data);
s[n].length=leng;
n++;
}
/*void del()
{
int i,k;
char sym[20];
printf("Enter the symbol to be deleted\n");
scanf("%s",sym);
if(n==0)
{
printf("empty table\n");
return;
}
for(i=0;i<n;i++)
if(strcmp(sym,s[i].symbol)==0)
{
for(k=i;k<n-1;k++)
{
strcpy(s[k].type,s[k+1].type);
s[k].length=s[k+1].length;
}
n--;
printf("the symbol is deleted\n");
}
}*/

void del()
{
    int i, k;
    char sym[20];
    printf("Enter the symbol to be deleted\n");
    scanf("%s", sym);
    
    if (n == 0)
    {
        printf("Empty table\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (strcmp(sym, s[i].symbol) == 0)
        {
            for (k = i; k < n - 1; k++)
            {
                strcpy(s[k].symbol, s[k + 1].symbol);
                strcpy(s[k].type, s[k + 1].type);
                s[k].length = s[k + 1].length;
            }
            n--;
            printf("The symbol is deleted\n");
            return;
        }
    }

    printf("Symbol not found\n");
}


void modify()
{
char name[20],data[20],old[20];
int len,i;
if(n==0)
{
printf("empty tables\n");
return;
}
printf("Enter the symbol to be modified\n");
scanf("%s",old);
for(i=0;i<n;i++)
{
if(strcmp(old,s[i].symbol)==0)
{
printf("symbol is found %s \t%s \t\t%d",s[i].symbol,s[i].type,s[i].length);
printf("\nEnter new values for datatypes,length\n");
scanf("%s%d",data,&len);
strcpy(s[i].type,data);
s[i].length=len;
printf("symbol entries modified\n");
return;
}
}
}
void search()
{
int i;
char name[20];
if(n==0)
{
printf("empty table\n");
return;
}
printf("enter the symbol to be searched\n");
scanf("%s",name);
for(i=0;i<n;i++)
{
if(strcmp(name,s[i].symbol)==0)
{
printf("symbol found\n%s \t%s\t\t%d",s[i].symbol,s[i].type,s[i].length);
return;
}
}
}
void disp()
{
int i;
if(n==0)
{
printf("empty table\n");
return;
}
printf("symbol\tdatatype\tlength\n");
for(i=0;i<n;i++)
printf("%s\t%s\t\t%d\n",s[i].symbol,s[i].type,s[i].length);
}
