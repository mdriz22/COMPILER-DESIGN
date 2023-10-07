#include<stdio.h>

#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Heap
{
int data;
struct Heap *next;
}node;
node *create();
int main()
{
int choice,val;
char ans;
node *head;
void display(node *);
node *search(node *,int);
node *insert(node *);
void dele(node **);
head=NULL;
do
{
printf("\n program to perform various operations on heap using dynamic memory management");
printf("\n1.create");
printf("\n2.display");
printf("\n3.insert an element in a list");
printf("\n4.delete an element from a list");
printf("\n5.quit");
printf("\n enter your choice(1-5) ");
scanf("%d",&choice);
switch(choice)
{
case 1:
head=create();
break;
case 2:
display(head);
break;
case 3:
head=insert(head);
break;
case 4:
dele(&head);
break;
case 5:
exit(0);
default:
printf("invalid choice,try again");
getchar();
}
}while(choice!=5);
}


node *create()
{
node *temp,*new,*head;
int val,flag;
char ans='y';
node *get_node();
temp=NULL;
flag=TRUE;
do
{
printf("\n enter the Element");
scanf("%d",&val);
getchar();
new=get_node();
if(new==NULL)
printf("\n memory is not allocated");
new->data=val;
if(flag==TRUE)
{
head=new;
temp=head;
flag=FALSE;
}
else
{
temp->next=new;
temp=new;
}
printf("\n do you want to enter more elements?(y/n)");
ans= getchar();
}while(ans=='y');
printf("\n the list is created");
getchar();
return head;
}


node *get_node()
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->next=NULL;
return temp;
}
void display(node *head)
{
node *temp;
temp=head;
if(temp==NULL)
{
printf("\n the list is empty\n");
getchar();
return;
}
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL");
getchar();
}
node *search(node *head,int key)
{
node *temp;
int found;
temp=head;
if(temp==NULL)
{
printf("\nthe linked list is empty\n");
getchar();
return NULL;
}
found=FALSE;
while(temp!=NULL&&found==FALSE)
{
if(temp->data!=key)
temp=temp->next;
else
found=TRUE;
}
if(found==TRUE)
{
printf("\n the elements is present in the list\n");
getchar();
return temp;
}
else
printf("\nthe element is not present in the list\n");
getchar();
return NULL;
}
node *insert(node *head)
{
int choice;
node *insert_head(node*);
void insert_after(node*);
void insert_last(node*);
printf("\n 1.insert a node as a head node");
printf("\n 2.insert a node as a last node");
printf("\n 3.insert a node as at the intermediate position in the list");
printf("\n enter your choice for insertion of a node");
scanf("%d",&choice);
switch(choice)
{
case 1:
head=insert_head(head);
break;
case 2:
insert_last(head);
break;
case 3:
insert_after(head);
break;
}
return head;
}
node *insert_head(node *head)
{
node *New,*temp;
New=get_node();
printf("\n enter the element which you want to insert");
scanf("%d",&New->data);
if(head==NULL)
head=New;
else
{
temp=head;
New->next=temp;
head=New;
}
return head;
}

void insert_last(node *head)
{
node *New,*temp;
New=get_node();
printf("\n enter the element which you want to insert");
scanf("%d",&New->data);
if(head==NULL)
head=New;
else
{
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=New;
New->next=NULL;
}
}

void insert_after(node *head)
{
int key;
node *New,*temp;
New=get_node();
printf("\n enter the element after which you want to insert");
scanf("%d",&key);
temp=head;
do
{
if(temp->data==key)
{
printf("enter the element which you want to insert");
scanf("%d",&New->data);
New->next=temp->next;
temp->next=New;
return;
}
else
temp=temp->next;
}while(temp!=NULL);
}
node *get_prev(node *head,int val)
{
node *temp,*prev;
int flag;
temp=head;
if(temp==NULL)
return NULL;
flag=FALSE;
prev=NULL;
while(temp!=NULL&&!flag)
{
if(temp->data!=val)
{
prev=temp;
temp=temp->next;
}
else
flag=TRUE;
}
if(flag)
return prev;
else
return NULL;
}


void dele(node **head)
{
int key;
node *New,*temp,*prev;
temp=*head;
if(temp==NULL)
{
printf("\n the list is empty\n");
getchar();
return;
}
printf("\n enter the element you want to delete:");
scanf("%d",&key);
temp=search(*head,key);
if(temp!=NULL)
{
prev=get_prev(*head,key);
if(prev!=NULL)
{
prev->next=temp->next;
free(temp);
}
else
{
*head=temp->next;
free(temp);
}
printf("\n element is deleted\n");
getchar();
}
}
