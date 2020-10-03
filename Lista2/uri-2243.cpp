// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;



int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int max=1;
    for(int i=1; i<n; i++){
        //j vai indicar a posicao do centro do triangulo
        int j=i;
        //alt_max vai indicar a altura maior que o triangulo vai atingir
        int alt_max = 2;

        //enquanto o proximo elemento é maior que altura max
        while(a[j+1] > alt_max && j+1 < n){
            //o centro do triangulo pode ser o proximo e alt_max pode aumentar em 1
            j++;
            alt_max++;
        }
        
        //se maior altura possivel for maior que o max vale a pena testar
        if(alt_max > max){
            //done = temos um triangulo pronto
            int done=0;
            while(done==0){
                //w = posicao atual
                int w=j;
                //alt = altura da posicao atual
                int alt = alt_max;

                //enquanto proxima posicao for pelo menos do tamanho de alt-1
                //e ainda nao atingimos alt == 0
                // if(alt_max <= n-w){
                while(a[w+1] >= alt-1 && alt>0 && w+1 < n){
                    //posicao atual entra no triangulo
                    w++;
                    //tamanho da posicao atual é um a menos
                    alt--;
                }

                //se alt==0 temos um triangulo formado
                if(alt == 0 || (w+1 == n && alt == 1)){
                    done = 1;
                    if(alt_max > max) max = alt_max;
                }
                // }
                

                //nao conseguimos formar um triangulo
                else{
                    // if(w+1 <= n){
                    //     j-=(a[w]-a[w+1])/2;
                    //     alt-=(a[w]-a[w+1])/2;
                    // }
                    // else{
                        //centro do triangulo vai um pra tras
                        j--;
                        //alt_max diminui de um possível
                        alt_max--;
                    // }
                    
                    //se j==i ja testamos todas as possibilidades
                    //ou se alt_max <= max nao precisa testar mais
                    if(j <= i || alt_max <= max) done=1;
                } 
            }   
        }
        
    }

    printf("%d\n", max);
    return 0;
}