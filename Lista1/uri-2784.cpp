#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m, ui, vi, pi, s;

    scanf("%d %d", &n, &m);
    int d[n+1];
    int v[n+1];

    for (int i=0; i<n+1; i++){
        d[i] = INT_MAX;
        v[i] = 0;
    }

    vector<pair<int,int>> g[n+1];

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &ui, &vi, &pi);
        g[ui].push_back(make_pair(vi,pi));
        g[vi].push_back(make_pair(ui,pi));
    }

    scanf("%d", &s);
    int S = s;
    d[s] = 0;

    for(int j=0; j<n; j++){
        v[s] = 1;
        int nv = 0;
        for(int i=0; i<g[s].size(); i++){
            vi = g[s][i].first;
            pi = g[s][i].second;
            if (v[vi] == 0){
                if(d[vi] > d[s]+pi){
                    d[vi] = d[s]+pi;
                }
            }
        }
        //checando qual o menor proximo vizinho
        for(int w=1; w<n+1; w++){
            if(d[w]<d[nv] && v[w]==0) nv = w;
        }
        s=nv;
    }

    int menor = INT_MAX; 
    int maior = 0;
    for(int w=1; w<n+1; w++){
        if(w != S){
            if(d[w] < menor) menor = d[w];
            if(d[w] > maior) maior = d[w];
        }
    }
    printf("%d\n", maior-menor);
 
    return 0;
}

