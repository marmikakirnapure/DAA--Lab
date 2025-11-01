#include <stdio.h>
#include <float.h>
#define MAX 100

int main() {
    int n;
    printf("Enter number of book IDs: ");
    scanf("%d", &n);

    double keys[MAX], p[MAX], q[MAX];

    printf("Enter %d sorted book IDs: ", n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &keys[i]);

    printf("Enter %d successful search probabilities (p[i]): ", n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &p[i]);

    printf("Enter %d unsuccessful search probabilities (q[i]): ", n + 1);
    for (int i = 0; i <= n; i++)
        scanf("%lf", &q[i]);

    double e[MAX + 1][MAX + 1], w[MAX + 1][MAX + 1];
    int root[MAX + 1][MAX + 1];

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum expected cost of OBST = %f\n", e[1][n]);
    return 0;
}
