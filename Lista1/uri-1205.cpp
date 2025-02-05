#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int n, m, k, a;
    int i, j;
    double p;
    
    //num pontos estrategicos, num estradas, num balas, prob
    while(scanf("%d %d %d %lf", &n, &m, &k, &p) != EOF){
        int pos[n+1];
        int vis[n+1];
        int dist[n+1];
        vector<int> g[n+1];

        for(int w=0; w<n+1; w++) {
            pos[w] = 0;
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

        for(int w=0; w<a; w++){
            scanf("%d", &i);
            //vai contabilizar quantos atiradores tem na pos
            pos[i] += 1;
        }
        
        //ponto de partida e destino do soldado
        scanf("%d %d", &i, &j);

        dist[i] = pos[i];

        for(int v=1; v<n+1; v++){
            if(i != 0){
            vis[i] = 1;
            int nv = 0;
            for(int w=0; w<g[i].size(); w++){
                int vi = g[i][w];
                int pi = pos[vi];
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
        printf("%.3lf\n", pow(p,min));
    }

    

    //ter que ver os caminhos possiveis entre i e j
    //a cada nova posicao uma bala a menos
    //um caminho deve parar de ser considerado quando acabarem as balas
    //contar a cada caminho quantos atiradores serao encontrados
    //o melhor caminho é o que tem menos atiradores
    //fazer o calculo de probabilidade final considerando a quantidade de atiradores
    //so guardar o valor do melhor caminho
    //todos os caminhos devem ser testados desde que continuem tendo menos atiradores que o melhor caminho
 
    
    return 0;
}