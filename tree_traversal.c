#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct Node* insert(struct Node* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else {
root->right = insert(root->right, data);
}
return root;
}
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
void main() {
struct Node* root = NULL;
int choice, data;
printf("\nMenu:\n");
printf("1. Insert Node\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
do {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
printf("In-order Traversal: ");
inorder(root);
printf("\n");
break;
case 3:
printf("Pre-order Traversal: ");
preorder(root);
printf("\n");
break;
case 4:
printf("Post-order Traversal: ");
postorder(root);
printf("\n");
break;
case 5:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 5);

}
