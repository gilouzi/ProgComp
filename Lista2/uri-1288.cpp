// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int MAX(int i, int j){
    return i>j ? i : j;
}

int main() {
    int c;
    scanf("%d", &c);
    for(int i=0; i<c; i++){
        int n, x, y, k, r;
        scanf("%d", &n);
        pair <int, int> canh[n+1];
        for(int j=1; j<=n; j++){
            scanf("%d %d", &x, &y);
            canh[j].first = x;
            canh[j].second = y;
        }
        scanf("%d", &k);
        scanf("%d", &r);

        int m[n+1][k+1];
        for(int j=0; j<=n; j++){
            m[j][0] = 0;
        }
        for(int j=0; j<=k; j++){
            m[0][j] = 0;
        }

        int d=0;
        for(int w=1; w<=n; w++){
            for(int j=1; j<=k; j++){
                if(canh[w].second > j) m[w][j] = m[w-1][j];
                else m[w][j] = MAX(m[w-1][j], m[w-1][j-canh[w].second]+canh[w].first);
                if(m[w][j] >= r) {
                    d=1;
                    break;
                }
            }
        }

        if(d==1) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    };

    return 0;
}