#include <stdio.h>
#include <string.h>

#define maxlen 100

void implementlcs(int b[maxlen][maxlen], char x[], int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 0) {
        implementlcs(b, x, i-1, j-1);
        printf("%c", x[i-1]);
    } else if (b[i][j] == 1)
        implementlcs(b, x, i-1, j);
    else
        implementlcs(b, x, i, j-1);
}

void lcs(char x[], char y[]) {
    int m = strlen(x);
    int n = strlen(y);
    int c[maxlen][maxlen], b[maxlen][maxlen];
    for (int i = 0; i <= m; i++){
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++){
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
    
    printf("c table:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
    printf("\n b table:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\nlength of lcs: %d\n", c[m][n]);
    printf("lcs: ");
    implementlcs(b, x, m, n);
    printf("\n");
}

int main() {
    char x[maxlen], y[maxlen];
    
    printf("Enter the first string: ");
    scanf("%s", x);
    
    printf("Enter the second string: ");
    scanf("%s", y);
    
    printf("\n");
    lcs(x, y);
    
    return 0;
}
