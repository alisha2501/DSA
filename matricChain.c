#include <stdio.h>
#include <limits.h>
int N;
int m[100][100];
int s[100][100]; 

void matrixChainOrder(int p[], int n) {
  
  for (int i = 1; i < n; i++)
    m[i][i] = 0;

  for (int L=2; L<n; L++) {
    for (int i=1; i<n-L+1; i++) {
      int j = i+L-1;
      m[i][j] = 999999;
      for (int k=i; k<=j-1; k++) {
        int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
  printf("The M Table is: \n");
  for(int i=1; i<=n-1; i++) {
    for(int j=1; j<=n-1; j++) {
        printf("%d\t ", m[i][j]);
    }
    printf("\n");
  }
  printf("The S table is: \n");
  for(int i=1; i<=n-1; i++) {
    for(int j=1; j<=n-1; j++) {
        printf("%d\t ", s[i][j]);
    }
    printf("\n");
  }
}

void printOptimalParens(int s[100][100], int i, int j) {
    s[100][100]=s[N][N];
  if (i == j) {
    printf("A%d", i);
  }
  else {
    printf("(");
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j]+1, j);
    printf(")");
  }
}

int main() {
  printf("Enter number of matrices: ");
  scanf("%d", &N);
  int p[N];
  printf("Enter dimensions: \n");
  for(int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }
  
  matrixChainOrder(p, N);
  printf("Optimal parentheses placement is: ");
  printOptimalParens(s, 1, N-1);
  
  return 0;
}
