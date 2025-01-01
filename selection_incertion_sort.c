#include <stdio.h>
#include <string.h>
void selection_sort(int b[], int size);
void insertion_sort(int b[], int size);
void print_array(int b[], int size);
int main() {
int n, i, choice;
int a[20], original_array[20];
printf("Enter size of the array: ");
scanf("%d", &n);
printf("Enter elements into the array: \n");
for(i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
memcpy(original_array, a, n * sizeof(int));
while (1) {
printf("\nChoose sorting algorithm:\n");
printf("1. Selection Sort\n");
printf("2. Insertion Sort\n");
printf("3. Exit\n");
printf("Enter your choice (1, 2, or 3): ");
scanf("%d", &choice);
switch(choice) {
case 1:
memcpy(a, original_array, n * sizeof(int));
printf("\nElements before sorting: ");
print_array(a, n);
selection_sort(a, n);
printf("Elements after sorting with Selection Sort: ");
print_array(a, n);break;
case 2:
memcpy(a, original_array, n * sizeof(int));
printf("\nElements before sorting: ");
print_array(a, n);
insertion_sort(a, n);
printf("Elements after sorting with Insertion Sort: ");
print_array(a, n);
break;
case 3:
printf("Exiting the program.\n");
return 0;
default:
printf("Invalid choice! Please try again.\n");
break;
}
printf("\n");
}
return 0;
}
void selection_sort(int b[], int size) {
int i, j, min, temp;
for(i = 0; i < size - 1; i++) {
min = i;
for(j = i + 1; j < size; j++) {
if(b[j] < b[min]) {
min = j;
}
}
if(min != i) {
temp = b[i];
b[i] = b[min];
b[min] = temp;
}
}
}
void insertion_sort(int b[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) { 
        key = b[i]; 
        j = i - 1;
        while (j >= 0 && b[j] > key) { 
            b[j + 1] = b[j]; 
            j = j - 1;
        }
        b[j + 1] = key; 
    }
}
void print_array(int b[], int size) {
for(int i = 0; i < size; i++) {
printf("%d ", b[i]);
}
printf("\n");
}
