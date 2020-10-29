// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
 
    int n, m, k, a;
    int i, j;
    
    //quant vertices, quant aresta
    while(scanf("%d %d %d %lf", &n, &m) != EOF){
        int pes[n+1];
        int vis[n+1];
        int dist[n+1];
        vector<int> g[n+1];

        for(int w=0; w<n+1; w++) {
            pes[w] = 0;
            vis[w] = 0;
            dist[w] = INT_MAX;
        }

        
        
        for(int w=0; w<m; w++){
            scanf("%d %d", &i, &j);
            //indicar que pos i e j tem um caminho
            g[i].push_back(j);
            g[j].push_back(i);
        }

        scanf("%d", &a);

        //calculo do peso das arestas, provavelmente muda
        for(int w=0; w<a; w++){
            scanf("%d", &i);
            //vai contabilizar quantos atiradores tem na pos
            pes[i] += 1;
        }
        
        //ponto de partida e destino
        scanf("%d %d", &i, &j);

        dist[i] = pes[i];

        for(int v=1; v<n+1; v++){
            if(i != 0){
            vis[i] = 1;
            int nv = 0;
            for(int w=0; w<g[i].size(); w++){
                int vi = g[i][w];
                int pi = pes[vi];
                if(vis[vi] == 0){
                    if(dist[vi] > dist[i]+pi){
                        dist[vi] = dist[i]+pi;
                    }
                }
            }

            //checando qual o menor proximo vizinho
            for(int w=0; w<n+1; w++){
                if(dist[w]<dist[nv] && vis[w]==0) nv = w;
                // if(dist[g[i][w]]<dist[nv] && vis[g[i][w]]==0) nv = g[i][w];
            }

            i=nv;
            }
        }
        
        int min = dist[j];
    }

    //para outra forma de fazer checar lista 1 uri-2784
 
    
    return 0;
}