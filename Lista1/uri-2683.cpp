#include <bits/stdc++.h>
using namespace std;

void updateKey(int *keyMin, vector<pair<int,int>> g){
    printf("oi1\n");
    for(int i=0; i<g.size(); i++){
        int v = g[i].first;
        int w = g[i].second;
        if(w < keyMin[v]) keyMin[v] = w;
    }
}

int minV(int *keyMin, int *visMin, int n, int minV){
    printf("oi2\n");
    for(int i=2; i<n+1; i++){
        if(keyMin[i] < keyMin[minV] && visMin[i]==0){
            minV=i;
        }
    }
    return minV;
}

int main() {
 
    int n, u, v, w;

    scanf("%d", &n);

    vector<pair<int,int>> g[n+1];
    vector<pair<int,int>> nSet;
    int keyMax[n+1];
    int visMax[n+1];
    int keyMin[n+1];
    int visMin[n+1];

    for(int i=0; i<n; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
        keyMin[i+1] = INT_MAX;
        visMin[i+1] = 0;
    }

    v = 1;
    int min = 0;
    int max = 0;
    keyMin[v] = 0;
    visMin[v] = 1;

    for(int i=0; i<n; i++){
        updateKey(keyMin, g[v]);
        v = minV(keyMin, visMin, n, g[v][0].first);
        min += keyMin[v];
        visMin[v]=1;
        printf("%d\n", min);
    }
        
        return 0;
}
/* Algoritmo de prim
set de vertices que nao estao na arvore x set de vertices que estao
*/