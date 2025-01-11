#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
int mem;
char p[3];
struct node *next;
} *fhead, *ahead, *newNode;
void insert(struct node *, struct node *);
void fit();
void firstfit(char id[3], int mem);
void worstfit(char id[3], int mem);
void bestfit(char id[3], int mem);
void display(struct node *);
void main() {
int ch;
struct node *ptr;
fhead = (struct node *) malloc(sizeof(struct node));
fhead->next = NULL;
ahead = (struct node *) malloc(sizeof(struct node));
ahead->next = NULL;
while (1) {
newNode = (struct node *) malloc(sizeof(struct node));
printf("\nEnter free memory size: ");
scanf("%d", &newNode->mem);
strcpy(newNode->p, "f");
newNode->next = NULL;
insert(fhead, newNode);
display(fhead);
printf("\nEnter 1 to insert more memory blocks, 0 to stop: ");
scanf("%d", &ch);
if (ch == 0) {
break;
}
}
printf("\nFree List\n_____________\n");
display(fhead);
fit();}
void insert(struct node *head, struct node *newNode) {
struct node *ptr;
if (head->next == NULL) {
head->next = newNode;
} else {
ptr = head->next;
while (ptr->next != NULL) {
ptr = ptr->next;
}
ptr->next = newNode;
}
}
void display(struct node *head) {
struct node *ptr;
ptr = head->next;
while (ptr != NULL) {
printf("(%s : %d)\t", ptr->p, ptr->mem);
ptr = ptr->next;
}
printf("\n");
}
void fit() {
int ch, mem;
char pid[3];
printf(" \n1. First Fit\n2. Worst Fit\n3. Best Fit\n4. Exit");
printf("\nYour Choice: ");
scanf("%d", &ch);
while (ch != 4) {
printf("\nEnter Process ID: ");
scanf("%s", pid);
printf("Memory size required: ");
scanf("%d", &mem);
switch (ch) {
case 1:
firstfit(pid, mem);
break;
case 2:
worstfit(pid, mem);
break;
case 3:
bestfit(pid, mem);break;
default:
printf("Invalid choice! Please select a valid option.\n");
break;
}
printf("\nAllocated List\n_____________\n");
display(ahead);
printf("\nFree List\n_____________\n");
display(fhead);
printf("\n1. First Fit\n2. Worst Fit\n3. Best Fit\n4. Exit");
printf("\nYour Choice: ");
scanf("%d", &ch);
}
}
void firstfit(char id[3], int mem) {
struct node *ptr = fhead->next, *prev = fhead;
while (ptr != NULL) {
if (ptr->mem >= mem) {
struct node *newNode = (struct node *) malloc(sizeof(struct node));
strcpy(newNode->p, id);
newNode->mem = mem;
newNode->next = NULL;
insert(ahead, newNode);
ptr->mem -= mem;
if (ptr->mem == 0) {
prev->next = ptr->next;
free(ptr);
}
return;
}
prev = ptr;
ptr = ptr->next;
}
printf("\nSpace not available for first fit.\n");
}
void worstfit(char id[3], int mem) {
struct node *ptr = fhead->next, *prev = fhead;
struct node *worst = NULL, *worstPrev = NULL;
while (ptr != NULL) {
if (ptr->mem >= mem && (worst == NULL || ptr->mem > worst->mem)) {
worst = ptr;
worstPrev = prev;
}
prev = ptr;
ptr = ptr->next;}
if (worst != NULL) {
struct node *newNode = (struct node *) malloc(sizeof(struct node));
strcpy(newNode->p, id);
newNode->mem = mem;
newNode->next = NULL;
insert(ahead, newNode);
worst->mem -= mem;
if (worst->mem == 0) {
worstPrev->next = worst->next;
free(worst);
}
} else {
printf("\nSpace not available for worst fit.\n");
}
}
void bestfit(char id[3], int mem) {
struct node *ptr = fhead->next, *prev = fhead;
struct node *best = NULL, *bestPrev = NULL;
while (ptr != NULL) {
if (ptr->mem >= mem && (best == NULL || ptr->mem < best->mem)) {
best = ptr;
bestPrev = prev;
}
prev = ptr;
ptr = ptr->next;
}
if (best != NULL) {
struct node *newNode = (struct node *) malloc(sizeof(struct node));
strcpy(newNode->p, id);
newNode->mem = mem;
newNode->next = NULL;
insert(ahead, newNode);
best->mem -= mem;
if (best->mem == 0) {
bestPrev->next = best->next;
free(best);
}
} else {
printf("\nSpace not available for best fit.\n");
}
}
