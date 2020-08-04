#include <bits/stdc++.h>
using namespace std;

void updateKeyMin(int *keyMin, int *visMin, vector<pair<int,int>> g){
    for(int i=0; i<g.size(); i++){
        int v = g[i].first;
        int w = g[i].second;
        if(w < keyMin[v] && visMin[v] == 0) keyMin[v] = w;
    }
}

void updateKeyMax(int *keyMax, int *visMax, vector<pair<int,int>> g){
    for(int i=0; i<g.size(); i++){
        int v = g[i].first;
        int w = g[i].second;
        if(w > keyMax[v] && visMax[v] == 0) keyMax[v] = w;
    }
}

int minV(int *keyMin, int *visMin, int n, int minV){
    for(int i=2; i<n+1; i++){
        if(keyMin[i] < keyMin[minV] && visMin[i]==0){
            minV=i;
        }
    }
    return minV;
}

int maxV(int *keyMax, int *visMax, int n, int maxV){
    for(int i=2; i<n+1; i++){
        if(keyMax[i] > keyMax[maxV] && visMax[i]==0){
            maxV=i;
        }
    }
    return maxV;
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
        keyMax[i+1] = -1;
        visMax[i+1] = 0;
    }

    int min = 0;
    int max = 0;
    int vMin = 1;
    int vMax = 1;
    keyMin[vMin] = 0;
    visMin[vMin] = 1;
    keyMax[vMax] = 0;
    visMax[vMax] = 1;

    for(int i=0; i<n; i++){
        updateKeyMin(keyMin, visMin, g[vMin]);
        vMin = minV(keyMin, visMin, n, g[vMin][0].first);
        min += keyMin[vMin];
        visMin[vMin]=1;

        updateKeyMax(keyMax, visMax, g[vMax]);
        vMax = maxV(keyMax, visMax, n, g[vMax][0].first);
        max += keyMax[vMax];
        visMax[vMax]=1;
    }

    printf("%d\n",max);
    printf("%d\n",min);
        
    return 0;
}
/* Algoritmo de prim
set de vertices que nao estao na arvore x set de vertices que estao
*/