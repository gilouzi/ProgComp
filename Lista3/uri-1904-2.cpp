// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define tam_max 10000001

int crivo[tam_max];
int mult2[tam_max];

int exp(int n, int e){
    if(e==0) return 1;
    int m=exp(n,e/2);
    if(e%2 == 0) return m*m;
    else return m*m*n;
}

int fat(int n){
    if(n==0 || n==1) return 1;
    int f=1;
    for(int i=2; i<=n; i++) f*=i;
    return f;
}

int main() {
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if(a==b) printf("?\n");
    else {
        //fazer sempre a ser menor que b
        if(a>b){
            int aux=a;
            a=b;
            b=aux;
        } 

        int primos=0;
        for(int i=2; i<=b; i++){
            crivo[i] = 1;
        }
        for(int i=2; i<=b; i++){
            if(crivo[i]==1){
                if(i>=a) primos++;
                for(int j=i+i; j<tam_max; j+=i) crivo[j] = 0;
            }
        }
        
        int n=0;
        int q=b-a;
        //vamos descobrir se a soma das combinacoes e par ou impar
        //primeiro tipo de combinacao é escolher todos os primos iguais
        //vai ser par se primos for par
        //vai ser impar se primos for impar
        //somar 2 para garantir que f != 0 (dps vamos multiplicar por outros num)
        //se q for igual a 1 é o unico tipo que acontece
        int f=primos%2+2;

        //segundo tipo de combinacao é escolher 1 primo diferente e o resto tudo igual
        //temos que escolher o primo repetido e o que será diferente
        //a combinacao vai ser primos*(primos-1)
        //resultado sempre sera par independente do valor de primos
        //nao precisamos calcular pq ao somar com f vai permanecer a paridade
        //vai ser diferente so se q=2, mas isso vai ser tratado dps

        if(q>2){
            //terceiro caso é escolher todos diferentes
            //vai multiplicar primos*(primos-1)*(primos-2)...(primos-q+1) -> q vezes
            //vai ser dividido por q!
            //saber quantos fatores de 2 tem no numerador e no divisor
            int num=0;
            int div=0;
            int aux_num = primos;
            int aux_div = q; 
            for(int i=0; i<q; i++){
                num+=mult2[aux_num];
                aux_num--;
                div+=mult2[aux_div];
                aux_div--;
            }
            //se tem mais fatores de 2 no divisor do que no numerador tem impares escolhas
            //somar 1 em f (mostrando que ta fazendo uma soma impar)
            if(div-num >= 0) f++; 

            //quarto caso é ir aumentando o numero de repeticoes
        }



        printf("primos: %d, q: %d, f:%d\n",primos,q,f);
        if(n%2==0) printf("Bob\n");
        else printf("Alice\n");

        // for(int i=2; i<126; i++){
        //     printf("%d: %d fatores\n",i,divSum[i]);
        // }
    }
    
    

    return 0;
}