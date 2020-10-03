// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int MIN(int i, int j){
    return i<j ? i : j;
}

int main() {
    int n; //numero feiticos disp
    int p; //hp do monstro
    while(scanf("%d %d", &n, &p) != EOF){
        int d[n+1]; //dano causado pelo feitico
        int m[n+1]; //mana necessaria para usar feitico
        for(int i=1; i<=n; i++) scanf("%d %d", &d[i], &m[i]);


        int b[n+1][p+1];
        for(int j=0; j<=n; j++){
            b[j][0] = INT_MAX;
        }
        for(int j=0; j<=p; j++){
            b[0][j] = INT_MAX;
        }

        int dam=INT_MAX;
        for(int w=1; w<=n; w++){
            for(int j=1; j<=p; j++){
                if(d[w] >= j) b[w][j] = min(m[w],b[w-1][j]);
                else if(b[w-1][j-d[w]] != INT_MAX) b[w][j] = MIN(b[w-1][j], b[w-1][j-d[w]]+m[w]);
                else b[w][j] = INT_MAX;
            }
        }

        if(b[n][p] == INT_MAX) printf("-1\n");
        else printf("%d\n",b[n][p]);
    }

    
    

    return 0;
}