#include <bits/stdc++.h>
using namespace std;

void walk(int *pos, int pos_i, int pos_f, int balas, int mortos, int &min, vector<int> g[], int *vis){
    //vai atirar nas pessoas da posicao atual
    // printf("Posicao atual: %d\n", pos_i);
    balas -= pos[pos_i];
    mortos += pos[pos_i];
    vis[pos_i] = 1;
    //pode continuar movimentando se nao ficar com balas negativas
    if(balas >= 0 && mortos < min){
        //se posicao atual diferente final continua andando
        if(pos_i != pos_f) {
            for(int i=0; i<g[pos_i].size(); i++){
                if(vis[g[pos_i][i]] == 0)
                walk(pos, g[pos_i][i], pos_f, balas, mortos, min, g, vis);
            }
        }
        //se chegou na posicao final
        else{
            if (mortos < min) min = mortos;
            // printf("%d\n",mortos);
        }
    }
};

int main() {
 
    int n, m, k, a;
    int i, j;
    double p;
    
    //num pontos estrategicos, num estradas, num balas, prob
    while(scanf("%d %d %d %lf", &n, &m, &k, &p) != EOF){
        int pos[n+1];
        int vis[n+1];
        vector<int> g[n+1];

        for(int w=0; w<n+1; w++) {
            pos[w] = 0;
            vis[w] = 0;
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
        int min = INT_MAX;
        walk(pos,i,j,k,0,min,g,vis);
        printf("%.3lf\n",pow(p,min));
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