#include <bits/stdc++.h>
using namespace std;

int MAX(int i, int j){
    return i>j ? i : j;
}

int main() {
 
    int n, pac, qt, peso;
    
    scanf("%d", &n);
    for(int w=0; w<n; w++){
        scanf("%d", &pac);
        pair <int, int> l[pac+1];
        for(int j=1; j<=pac; j++){
            scanf("%d %d", &qt, &peso);
            l[j].first = qt;
            l[j].second = peso;
        }
        
        int m[pac+1][51];
        for(int i=0; i<=pac; i++){
            m[i][0] = 0;
        }
        for(int j=0; j<=50; j++){
            m[0][j] = 0;
        }

        for(int i=1; i<=pac; i++){
            for(int j=1; j<=50; j++){
                if(l[i].second > j) m[i][j] = m[i-1][j];
                else m[i][j] = MAX(m[i-1][j], m[i-1][j-l[i].second]+l[i].first);
            }
        }

        int v = m[pac][50];
        int sobra = pac;
        peso = 0;
        int i = pac;
        int j = 50;

        while(i != 0 && j != 0){
            if(m[i][j] != m[i-1][j]) {
                sobra--;
                peso+=l[i].second;
                j-=l[i].second;
            }
            i--;
        }

        // for(int i=0; i<pac+1; i++){
        //     for(int j=0; j<51; j++){
        //         printf("%3d ",m[i][j]);
        //     }
        //     printf("\n");
        // }

        printf("%d brinquedos\n", v);
        printf("Peso: %d kg\n", peso);
        printf("sobra(m) %d pacote(s)\n", sobra);
        printf("\n");

    }


    return 0;
}