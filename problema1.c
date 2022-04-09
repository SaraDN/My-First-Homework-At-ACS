#include <stdio.h>

void intersectie(int x1, int x2, int x3, int x4, int *x5, int *x6) {
    //aici testam posibilele cazuri
    if (x3 <= x2 && x4 >= x1) {
        *x5 = x3;
        *x6 = x2;
    }
    if (x1 <= x3 && x4 <= x2) {
        *x5 = x3;
        *x6 = x4;
    }
    if (x1 >= x3 && x2 <= x4) {
        *x5 = x1;
        *x6 = x2;
    }
    if (x1 >= x3 && x4 <= x2) {
        *x5 = x1;
        *x6 = x4;
    }
    if (x1 >= x3 && x4 <= x2 && x3 < x2 && x1 > x4) {
        *x5 = 0;
        *x6 = 0;
    }

    //cazul in care este avem multime vida
    if (x3 > x2) {
        *x5 = 0;
        *x6 = 0;
    }

    //cazul in care avem comun un singur termen
    if (x3 == x2) {
        *x5 = x2;
        *x6 = x2;
    }

    //cazul in care intersectam multimea vida cu alta multime
    if (x1 == 0 && x2 == 0) {
        *x5 = x3;
        *x6 = x4;
    }


}

void reuniune(int x1, int x2, int x3, int x4, int *x5, int *x6) {
    //reunim cele doua multimi
    if (x1 < x3)
        *x5 = x1;
    else *x5 = x3;
    if (x2 < x4)
        *x6 = x4;
    else *x6 = x2;
    //daca avem termen comun
    if (x2 == x3) {
        *x5 = x1;
        *x6 = x4;
    }

}

int main() {
    int n;
    scanf("%d", &n);
    //vector in care stocam rezultatul
    int rez[101];
    //q tine cont de indicele la care ne aflam in vectorul rez
    int q = 0;
    int g = 0;
    for (; g < n; g++) {
        int interogare;
        scanf("%d", &interogare);
        if (interogare == 1) {
            int operatie, x1, x2, x3, x4;
            scanf("%d %d %d %d %d", &operatie, &x1, &x2, &x3, &x4);
            int x5, x6;
            if (operatie == 1) {
                //intersectam cele 2 intervale
                intersectie(x1, x2, x3, x4, &x5, &x6);
                //stocam in vectorul rezultat x5 si x6
                rez[q] = x5;
                rez[q + 1] = x6;
                //incrementam indicele cu 2
                q += 2;
            }
            if (operatie == 2) {
                //reunim cele doua intervale
                reuniune(x1, x2, x3, x4, &x5, &x6);
                rez[q] = x5;
                rez[q + 1] = x6;
                q += 2;
            }
        }
        if (interogare == 2) {
            int M, v[101];
            scanf("%d", &M);
            int j = 0;
            //salvam in vectorul v operatiile citite de la tastatura
            for (; j < M; j++)
                scanf("%d", &v[j]);
            j = 0;
            //citim primul interval
            int x1, x2, x3, x4, x5, x6;
            scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
            //parcurgem vectorul v pentru a vedea operatia curenta si a o aplica
            for (; j < M; j++) {
                if (v[j] == 1) {
                    intersectie(x1, x2, x3, x4, &x5, &x6);
                    x1 = x5;
                    x2 = x6;
                }
                if (v[j] == 2) {
                    //luam un ok pe care il incrementam daca am intrat in if-ul de mai jos
                    int ok = 0;
                    //verificam daca este vorba de multimea vida sau de reuniunea unei multimi formate doar din elementul [0, 0] cu alta
                    if (x5 == 0 && x6 == 0) {
                        ok++;
                        if (x3 == 0) {
                            x5 = 0;
                            x6 = x4;
                        } else {
                            x5 = x3;
                            x6 = x4;
                        }
                    }
                    //in caz contrat, reunim intervalele
                    if (ok == 0)
                        reuniune(x1, x2, x3, x4, &x5, &x6);
                    //pregatim noul interval
                    x1 = x5;
                    x2 = x6;
                }
                if (j + 1 != M)
                    scanf("%d %d", &x3, &x4);
            }
            //adaugam rezultatul operatiei in vectorul rez
            rez[q] = x5;
            rez[q + 1] = x6;
            q += 2;

        }
    }
    //parcurgem vectorul rez si afisam, cu spatierea corespunzatoare
    int j = 0;
    for (; j < q; j += 2) {
        //daca avem doua 0-uri consecutive, avem multimea vida si outputam doar un 0
        if (rez[j] == 0 && rez[j + 1] == 0)
            printf("%d\n", rez[j]);
        else
            printf("%d %d\n", rez[j], rez[j + 1]);
    }

    return 0;
}
