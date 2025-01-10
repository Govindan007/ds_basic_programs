#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *blink;
struct node *flink;
}*head,*ptr,*ptr1,*tail;
void insert(int val)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=val;
temp->blink=NULL;
temp->flink=NULL;
if(head==NULL)
{
head=temp;
tail=temp;
}
else
{
tail->flink=temp;
temp->blink=tail;
tail=temp;
}
}
void delete(int key)
{
ptr=head;
ptr1=head;
while(ptr!=NULL){
if(ptr->data==key){
ptr1->flink=ptr->flink;
free(ptr);
ptr=ptr1->flink;
ptr->blink=ptr1;
break;
}
ptr1=ptr;
ptr=ptr->flink;
}
}
void traverse(){
ptr=head;
while(ptr!=NULL)
{
printf("%d ",ptr->data);
ptr=ptr->flink;
}
printf("\n");
}
void main()
{
int val,ch;
do
{
printf("1.insert\t2.delete\t3.traverse\t4.exit\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("INSERTION\n");
printf("Enter number to be inserted\n");
scanf("%d",&val);
insert(val);
break;
case 2:printf("DELETION\n");
printf("Enter number to deleted\n");
scanf("%d",&val);
delete(val);
break;
case 3:printf("TRAVERSAL\n");
traverse();
break;
case 4:printf("EXITING PROGRAM!!!\n");
break;
default:printf("Invalid choice\n");
}
}while(ch!=4);
}
