#include<stdio.h>
int main(){
int ptr1,ptr2,rptr=0,i,j;
printf("Enter the number of terms in the first polynomial:");
scanf("%d",&ptr1);
printf("\nEnter the number of terms of the second polynomial:");
scanf("%d",&ptr2);
int p1[ptr1][2],p2[ptr2][2];
rptr = ptr1+ptr2;
int res[rptr][2];
printf("\nEnter the first polynomial:");
for(i=0;i<ptr1;i++){
printf("\nCoefficient %d:",i+1);
scanf("%d",&p1[i][0]);
printf("\nExponent %d:",i+1);
scanf("%d",&p1[i][1]);
}
printf("\nEnter the second polynomial:");
for(j=0;j<ptr2;j++){
printf("\nCoefficient %d:",j+1);
scanf("%d",&p2[j][0]);
printf("\nExponent %d:",j+1);
scanf("%d",&p2[j][1]);
}
i=0;
j=0;
rptr=0;
while(i<ptr1 && j<ptr2){
if(p1[i][1] == p2[j][1]){
res[rptr][0] = p1[i][0] + p2[j][0];
res[rptr][1] = p1[i][1];
i++;
j++;
rptr++;
}
else if(p1[i][1]>p2[j][1])
{res[rptr][0] = p1[i][0];
res[rptr][1] = p1[i][1];
i++;
rptr++;
}else{
res[rptr][0] = p2[j][0];
res[rptr][1] = p2[j][1];
j++;
rptr++;
}
}
while(i<ptr1){
res[rptr][0] = p1[i][0];
res[rptr][1] = p1[i][1];
i++;
rptr++;
}
while(j<ptr2){
res[rptr][0] = p2[j][0];
res[rptr][1] = p2[j][1];
j++;
rptr++;
}
printf("\nThe result is:\n");
for(i=0;i<rptr;i++){
printf("\t%dx^%d",res[i][0],res[i][1]);
if(i<rptr-1){
printf("+");
}
}
return 0;
}
