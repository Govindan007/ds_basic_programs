#include<stdio.h>
void Sparse(int A[10][10], int m, int n, int S[20][3]);
void PrintSparse(int S[20][3]);
void AddSparse(int S[20][3], int T[20][3], int U[20][3]);
void SparseToMatrix(int S[20][3], int C[10][10]);
int main() {
int i, j, A[10][10], B[10][10], C[10][10], m1, n1, m2, n2;
int S[20][3], T[20][3], U[20][3];
printf("Enter the number of rows and columns of the first matrix: ");
scanf("%d%d", &m1, &n1);
printf("Enter the first matrix:\n");
for (i = 0; i < m1; i++)
for (j = 0; j < n1; j++)
scanf("%d", &A[i][j]);
printf("Matrix1:\n");
for (i = 0; i < m1; i++) {
for (j = 0; j < n1; j++) {
printf("%d\t", A[i][j]);
}
printf("\n");
}
Sparse(A, m1, n1, S);
printf("Enter the number of rows and columns of the second matrix: ");
scanf("%d%d", &m2, &n2);
if (m1 != m2 || n1 != n2) {
printf("Error: Matrices must have the same dimensions for addition.\n");
return 1;
}
printf("Enter the second matrix:\n");
for (i = 0; i < m2; i++)
for (j = 0; j < n2; j++)
scanf("%d", &B[i][j]);
printf("Matrix2:\n");
for (i = 0; i < m2; i++) {
for (j = 0; j < n2; j++) {
printf("%d\t", B[i][j]);
}
printf("\n");
}
Sparse(B, m2, n2, T);
AddSparse(S, T, U);
printf("Sum of the Sparse Matrices in Tuple Form:\n");
PrintSparse(U);
SparseToMatrix(U, C);
printf("Sum of the Sparse Matrices in Matrix Form:\n");
for (i = 0; i < m1; i++) {for (j = 0; j < n1; j++) {
printf("%d\t", C[i][j]);
}
printf("\n");
}
return 0;
}
void Sparse(int A[10][10], int m, int n, int S[20][3]) {
int i, j, k = 1;
S[0][0] = m;
S[0][1] = n;
for (i = 0; i < m; i++) {
for (j = 0; j < n; j++) {
if (A[i][j] != 0) {
S[k][0] = i;
S[k][1] = j;
S[k][2] = A[i][j];
k++;
}
}
}
S[0][2] = k- 1;
PrintSparse(S);
}
void PrintSparse(int S[20][3]) {
int i, j;
printf("Tuple form:\n");
for (i = 0; i <= S[0][2]; i++) {
for (j = 0; j < 3; j++) {
printf("%d\t", S[i][j]);
}
printf("\n");
}
}
void AddSparse(int S[20][3], int T[20][3], int U[20][3]) {
int i = 1, j = 1, k = 1;
if (S[0][0] != T[0][0] || S[0][1] != T[0][1]) {
printf("Incompatible Matrix size\n");
return;
}
U[0][0] = S[0][0];
U[0][1] = S[0][1];
while (i <= S[0][2] && j <= T[0][2]) {
if (S[i][0] < T[j][0] || (S[i][0] == T[j][0] && S[i][1] < T[j][1])) {
U[k][0] = S[i][0];
U[k][1] = S[i][1];
U[k][2] = S[i][2];
i++;} else if (S[i][0] > T[j][0] || (S[i][0] == T[j][0] && S[i][1] > T[j][1])) {
U[k][0] = T[j][0];
U[k][1] = T[j][1];
U[k][2] = T[j][2];
j++;
} else {
U[k][0] = S[i][0];
U[k][1] = S[i][1];
U[k][2] = S[i][2] + T[j][2];
i++;
j++;
}
k++;
}
while (i <= S[0][2]) {
U[k][0] = S[i][0];
U[k][1] = S[i][1];
U[k][2] = S[i][2];
i++;
k++;
}
while (j <= T[0][2]) {
U[k][0] = T[j][0];
U[k][1] = T[j][1];
U[k][2] = T[j][2];
j++;
k++;
}
U[0][2] = k- 1;
}
void SparseToMatrix(int S[20][3], int C[10][10]) {
int i, j,rows,cols;
rows = S[0][0];
cols = S[0][1];
for (i = 0; i <rows; i++) {
for (j = 0; j <cols; j++) {
C[i][j] = 0;
}
}
for (i = 1; i <= S[0][2]; i++) {
int row = S[i][0];
int col = S[i][1];
int value = S[i][2];
C[row][col] = value;
}
}
