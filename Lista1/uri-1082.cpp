#include <bits/stdc++.h>
 
using namespace std;

void ordena(int dfs[27], int tam, int res[27]){
    res[0] = dfs[0];
    for(int j=1; j<tam; j++){
        res[j] =  dfs[j];
        int w = j-1;
        while(w >= 0 && dfs[j] < res[w]){
            res[w+1] = res[w];
            res[w] = dfs[j];
            w--;
        }
    }
}

void DFS(int dfs[27][27], int &c, int &j, vector <int> *g, int i, int*vis){
    if(vis[i] == 1){
        return;
    }
    else if(g[i].size() == 0){
        dfs[c][j] = i;
        dfs[c][26]++;
        vis[i] = 1;
        j++;
        return;
    }
    else{
        dfs[c][j] = i;
        dfs[c][26]++;
        vis[i] = 1;
        j++;
        for(int z=0; z<g[i].size(); z++){
            int to_go = g[i][z];
            if(vis[to_go] != 1){
                DFS(dfs, c, j, g, to_go, vis);
            }
        }
    }
    return;

}

int main() {
 
    int n, v, e;
    char V1, V2;
    int v1, v2;

    //dfs para achar os componentes e salvar
    int dfs[27][27];
    int comp[26];
    int vis[26];

    //componentes
    int c = 0;
    int j = 0;
    
    scanf("%d", &n);
    // printf("Testes a serem feitos %d: \n", n);
    for (int i=0; i<n; i++){ 
        for(int l=0; l<26; l++) vis[l]=0;
        c=0;
        j=0;
        scanf("%d %d", &v, &e);
        vector <int> g[v];
        
        // printf("%d vértices e %d arestas \n", v, e);
        //guardar as conexoes em um vector (menor guarda maior)
        for (int k=0; k<e; k++){
            scanf(" %c %c", &V1, &V2);
            v1 = V1%97;
            v2 = V2%97;
            g[v1].push_back(v2); 
            g[v2].push_back(v1); 
        }

        //impressao para ver se esta salvando as arestas da forma esperada
        // for (int i=0; i<e; i++){
        //    printf("Vertice %d: ", i);
        //     for(int w=0; w<g[i].size(); w++)
        //         printf("%d ", g[i][w]);
        //     printf("\n");
        // }

        for (int k=0; k<v; k++){
            if(vis[k] != 1){
                dfs[c][26] = 0;
                DFS(dfs, c, j, g, k, vis);
                c++;
                j=0;
            }
        }

        //imprimir componentes
        printf("Case #%d:\n", i+1);
        for (int k=0; k<c; k++){
            int tam = dfs[k][26];
            int res[tam];
            ordena(dfs[k],tam,res);
            for(int w=0; w<tam; w++){
                printf("%c,", res[w]+97);
            }
            printf("\n");
        }
        printf("%d connected components\n\n", c);

    }

    
 
    return 0;
}

