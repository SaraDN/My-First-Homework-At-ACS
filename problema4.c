#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[101][101];
    int alfa;
    //vector de aparitii ale soldatiilor pe randul i
    int v[101];
    int i = 0;
    for (; i < n; i++) {
        //sol numara aparitiile lui 1 pe linia i
        int sol = 0;
        int j = 0;
        for (; j < m; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1)
                sol++;
        }
        //salvam in v numarul soldatilor
        v[i] = sol;
    }
    scanf("%d", &alfa);
    i = 0;
    for (; i < alfa; i++) {
        //initializam un prag de maxim ca sa putem afla minimul
        int min = 999999;
        int j = 0;
        int poz = 0;
        for (; j < n; j++) {
            //aflam minimul de soldati din v si salvam indicele in poz
            if (v[j] < min) {
                min = v[j];
                poz = j;
            }
        }
        //modificam valoarea minima cu un maxim pentru ca sa putem identifica urmatorul minum din v, de alfa ori
        v[poz] = m + 1;
        //afisam linia la care am gasit minimul
        if (i + 1 == alfa) {
            printf("%d", poz);
        } else printf("%d ", poz);
    }
    printf("\n");

    return 0;
}
