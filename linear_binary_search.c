#include<stdio.h>
int linear(int a[],int n,int key);
int binary(int a[],int n,int key);
int main(){
int a[50],i=0,j=0,n,choice=0,key=0,mid=-1,high,low=0,temp=0,flag=0;
printf("Enter the number of elements in the array : ");
scanf("%d",&n);
printf("Enter the elements in the array :\n");
for(i=0;i<n;i++){
printf("Enter the element %d :",i+1);
scanf("%d",&a[i]);
}
printf("Enter : \n 1 for Linear search \n 2 for Binary search \n");
printf("Enter your choice 1 or 2 : ");
scanf("%d",&choice);
switch(choice){
case 1: linear(a,n,key);
break;
case 2: binary(a,n,key);
break;
}
return 0;
}
int linear(int a[],int n,int key){
int flag=0,i=0;
printf("Enter the element to be searched : ");
scanf("%d",&key);
for(i=0;i<n;i++){
if(a[i]==key){
flag=1;
printf("Element found at position %d \n ",i);
break;
}
}
if(flag==0){
printf("Element not found");
}
return 0;
}
int binary(int a[],int n,int key)
{int j=0,i=0,low=0,mid=-1,high=n-1,temp=0,flag=0;
for(i=0;i<n;i++){
for(j=0;j<n-1;j++){
if(a[j]>a[j+1]){
a[j]=temp;
a[j+1]=a[j];
temp=a[j];
}
}
}
printf("Enter the element to be searched : ");
scanf("%d",&key);
while(low<=high){
mid=(low+high)/2;
if(a[mid]==key){
printf("Element found at position %d \n ", mid);
break;
}
else if(a[mid]<key){
low=mid+1;
}
else {
high = mid-1;
}
}
if(mid==-1){
printf("Element not found");
}
else{
printf("Element found at position %d", mid-1);
}
return 0;
}
