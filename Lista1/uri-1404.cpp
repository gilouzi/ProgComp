// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void captura(int casas, int *t, int *l, int *c, int &max, int i, vector<int> adv){
    if(i-1 >= 0){
        // if(c[i-1])
    }
}

int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    while(true){
        if(n==0 && m==0) break;
        int casas = (int)ceil((double)(n*m)/2);
        int t[casas];
        int l[casas];
        int li = 0;
        int c[casas];
        int ci = 0;
        vector <int> adv;
        printf("casas: %d n: %d m: %d\n",casas, n, m);
        for(int i=0; i<casas; i++){
            scanf("%d", &t[i]);
            // printf("%d", t[i]);
            if(t[i]==2) adv.push_back(i);
            l[i] = li;
            c[i] = ci;
            ci+=2;
            if(li%2 == 0){
                if(ci > (int)ceil((double)m/2)){
                    //ta indo pra linha impar, coluna vazia na pos 1
                    ci=1;
                    li+=1;
                }
            }
            else{
                if(ci > (int)floor((double)m/2)){
                    ci=0;
                    li+=1;
                }
            }
        }

        for(int i=0; i<casas; i++){
            printf("%d ", t[i]);
        }
        printf("\n");

        for(int i=0; i<casas; i++){
            printf("%d ", l[i]);
        }
        printf("\n");

        for(int i=0; i<casas; i++){
            printf("%d ", c[i]);
        }
        printf("\n");

        int max = 0;
        for(int i=0; i<casas; i++){
            if(t[i]==1){
                captura(casas, t, l, c, max, i, adv);
            }
        }

        scanf("%d %d", &n, &m);
    };
    return 0;
}