#include <stdio.h>
#include <string.h>

void smooth(double mat[101][101], int n, int m) {
    //m2 matrice auxiliara, reprezinta valorile intitiale ale lui mat
    double m2[101][101];
    double c = 1;
    double b = 9;
    double a = c / b;
    double smooth[3][3] = {
            {a, a, a},
            {a, a, a},
            {a, a, a}
    };
    int i = 0;
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++) {
            m2[i][j] = mat[i][j];
        }
    }
    //modificam m2 utilizand elementele din mat
    // tinem cont sa nu modificam elementele de pe margine
    i = 1;
    for (; i < n - 1; i++) {
        int j = 1;
        for (; j < m - 1; j++) {
            m2[i][j] =
                    smooth[0][0] * mat[i - 1][j - 1] + smooth[0][1] * mat[i - 1][j] + smooth[0][2] * mat[i - 1][j + 1] +
                    smooth[1][0] * mat[i][j - 1] + smooth[1][1] * mat[i][j] + smooth[1][2] * mat[i][j + 1] +
                    smooth[2][0] * mat[i + 1][j - 1] + smooth[2][1] * mat[i + 1][j] + smooth[2][2] * mat[i + 1][j + 1];

        }
    }

    //rescriem mat cu elemenetele lui m2 dupa ce am aplicat filtrul
    i = 0;
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++) {
            mat[i][j] = m2[i][j];
        }
    }
}

void blur(double mat[101][101], int n, int m) {
    //m2 matrice auxiliara, reprezinta valorile intitiale ale lui mat
    double m2[101][101];
    double a = 0.0625;
    double b = 0.125;
    double c = 0.25;
    double blur[3][3] = {
            {a, b, a},
            {b, c, b},
            {a, b, a}
    };
    int i = 0;
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++) {
            m2[i][j] = mat[i][j];
        }
    }
    //modificam m2 utilizand elementele din mat
    //tinem cont sa nu modificam elementele de pe margine
    i = 1;
    for (; i < n - 1; i++) {
        int j = 1;
        for (; j < m - 1; j++) {
            m2[i][j] = blur[0][0] * mat[i - 1][j - 1] + blur[0][1] * mat[i - 1][j] + blur[0][2] * mat[i - 1][j + 1] +
                       blur[1][0] * mat[i][j - 1] + blur[1][1] * mat[i][j] + blur[1][2] * mat[i][j + 1] +
                       blur[2][0] * mat[i + 1][j - 1] + blur[2][1] * mat[i + 1][j] + blur[2][2] * mat[i + 1][j + 1];
        }
    }
    //rescriem mat cu elemenetele lui m2 dupa ce am aplicat filtrul
    i = 0;
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++) {
            mat[i][j] = m2[i][j];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double mat[101][101];
    int i = 0;
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
    //k - numarul de operatii
    int k;
    scanf("%d", &k);
    char s[101];
    while (k > 0) {
        scanf("%s", s);
        //aplicam filtrul conform inputului
        if (strcmp(s, "smooth") == 0) {
            smooth(mat, n, m);
        }
        if (strcmp(s, "blur") == 0) {
            blur(mat, n, m);
        }
        k--;
    }
    i = 0;
    //afisam matricea cu spatierea corespunzatoare
    for (; i < n; i++) {
        int j = 0;
        for (; j < m; j++)
            printf("%8.3lf", mat[i][j]);
        printf("\n");
    }
    return 0;
}
