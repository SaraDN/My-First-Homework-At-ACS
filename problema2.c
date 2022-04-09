#include <stdio.h>
#include <string.h>
#include <math.h>

void dec_to_bin(int n, char s[]) {
    //vector in care stocam reprezentarea binara
    int bin[101];
    //vector auxiliar
    int aux[101];
    //indice aux, tine cont de numarul de biti
    int ok = 0;
    //in aux se va afla reprezentarea binara inversa a numarului n
    while (n > 0) {
        aux[ok] = n % 2;
        n = n / 2;
        ok++;
    }
    int k = 0;
    //inversam aux in bin
    for (; k < ok; k++) {
        bin[ok - k - 1] = aux[k];
    }
    k = 0;
    //completam cu alfa 0-uri si modificam s
    int alfa = 16 - ok;
    int beta = alfa;
    for (; k < 16; k++) {
        if (alfa == 0) {
            //convertim din int in char
            s[k] = bin[k - beta] + '0';
        }
        if (alfa > 0) {
            s[k] = '0';
            alfa--;
        }
    }
}

int bin_to_dec(char s[]) {
    int i = strlen(s) - 1;
    //tinem cont de puterea lui 2
    int k = 0;
    //num - reprezentarea in baza 10
    int num = 0;
    for (; i >= 0; i--) {
        //transormam din char in int
        int p = s[i] - '0';
        //daca s[i]='1'
        if (p == 1)
            num += pow(2, k);
        //puterea lui 2
        k++;
    }
    return num;
}

void sir_to_mat(char s[], int m[101][101]) {
    //k - indice pentru sirul s
    int i = 0, k = 0;
    for (; i < 4; i++) {
        int j = 0;
        for (; j < 4; j++) {
            //convertim din char in int
            m[i][j] = s[k] - '0';
            k++;
        }
    }

}

void mat_to_sir(char s[], int m[101][101]) {
    //k - indice pentru sirul s
    int i = 0, k = 0;
    for (; i < 4; i++) {
        int j = 0;
        for (; j < 4; j++) {
            //convertim din int in char
            s[k] = m[i][j] + '0';
            k++;
        }
    }
    s[k] = '\0';
}

int main() {
    char s[101];
    int n, m;
    //mat va contine m linii de forma xi yi xf yf
    int mat[101][101];
    //matricea rez va contine configuratia hartii
    int rez[101][101];
    //citim datele
    scanf("%d %d", &n, &m);
    dec_to_bin(n, s);
    sir_to_mat(s, rez);
    int i = 0;
    for (; i < m; i++) {
        int j = 0;
        for (; j < 4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    i = 0;
    for (; i < m; i++) {
        int x1 = mat[i][0];
        int y1 = mat[i][1];
        int x2 = mat[i][2];
        int y2 = mat[i][3];
        int aux;
        //mutam soldatii si modificam configuratia hartii, rez
        if (rez[x1][y1] == 1 && rez[x2][y2] == 0) {
            aux = rez[x1][y1];
            rez[x1][y1] = rez[x2][y2];
            rez[x2][y2] = aux;
        }
        if ((rez[x1][y1] == 0 && rez[x2][y2] == 0) || (rez[x1][y1] == 1 && rez[x2][y2] == 1)) {
            rez[x1][y1] = 0;
            rez[x2][y2] = 0;
        }

    }
    //convertim rez intr-un sir s - reprezentarea binara a unui numar
    mat_to_sir(s, rez);
    //afisam numarul in baza 10
    printf("%d\n", bin_to_dec(s));

    return 0;
}

