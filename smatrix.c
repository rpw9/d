#include <stdio.h>

int main() {
    int a[2][2], b[2][2], c[2][2];
    int p, q, r, s, t, u, v;

    
    printf("Enter the elements of the first matrix:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }


    printf("Enter the elements of the second matrix:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }


    printf("\n The first matrix is:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }


    printf("\n The second matrix is:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

  
    p = (a[1][1] + a[2][2]) * (b[1][1] + b[2][2]);
    q = (a[2][1] + a[2][2]) * b[1][1];
    r = a[1][1] * (b[1][2] - b[2][2]);
    s = a[2][2] * (b[2][1] - b[1][1]);
    t = (a[1][1] + a[1][2]) * b[2][2];
    u = (a[2][1] - a[1][1]) * (b[1][1] + b[1][2]);
    v = (a[1][2] - a[2][2]) * (b[2][1] + b[2][2]);


    c[1][1] = p + s - t + v;
    c[1][2] = r + t;
    c[2][1] = q + s;
    c[2][2] = p + r - q + u;

  
    printf("\n After multiplication, the resulting matrix is:\n");
    for (int i = 1 ; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

