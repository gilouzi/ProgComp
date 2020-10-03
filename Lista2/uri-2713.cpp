// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double MIN(double i, double j){
    return i<j ? i : j;
}

double tempoSemMana(int w, int *x, int v){
    return (double)x[w]/v;
}

double tempoComMana(int w, int *x, int *d, int v){
    v+=d[w];
    return (double)x[w]/v;
}

int main() {
    int n, k, v;
    //n salas
    //k quantidade de mana 
    //v valor do dano constante
    while (scanf("%d %d %d", &n, &k, &v) != EOF) {
        int x[n+1]; //pontos de vida do monstro
        int d[n+1]; //dano a ser aumentado
        for (int i=1; i<=n; i++){
            scanf("%d %d", &x[i], &d[i]);
        }

        double m[n+1][k+1];
        for(int j=0; j<=k; j++){
            m[0][j] = 0;
        }
        for(int j=1; j<=n; j++){
            m[j][0] = m[j-1][0]+tempoSemMana(j,x,v);
        }

        

        for(int w=1; w<=n; w++){
            for(int j=1; j<=k; j++){
                m[w][j] = MIN(m[w-1][j]+tempoSemMana(w,x,v), m[w-1][j-1]+tempoComMana(w,x,d,v));
            }
        }

        printf("%.4f\n", m[n][k]);
    }


    return 0;
}