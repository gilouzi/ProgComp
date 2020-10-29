// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define tam_max 10000001

long long int crivo[tam_max];
long long int mult2[tam_max];

long long int menor(long long int a, long long int b){
    if (a<b) return a;
    else return b;
}

int main() {
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if(a==b) printf("?\n");
    else {
        //fazer sempre a ser menor que b
        if(a>b){
            long long int aux=a;
            a=b;
            b=aux;
        } 

        //calcular a qtd de primos existentes no intervalo [a,b]
        long long int primos=0;
        crivo[0]=0;
        crivo[1]=0;
        for(long long int i=2; i<=b; i++){
            crivo[i] = 1;
        }
        for(long long int i=2; i<=b; i++){
            if(crivo[i]==1){
                if(i>=a) primos++;
                for(long long int j=i+i; j<=b; j+=i) crivo[j] = 0;
            }
        }

        if(primos == 0) printf("Bob\n");
        else{
            //salvar a qtd de fatores de 2 de i
            mult2[0]=0;
            mult2[1]=0;
            for(long long int i=2; i<tam_max; i++){
                //calcular quantas vezes 2 divide i
                long long int aux = i;
                long long int f = 0;
                while (aux%2==0){
                    f += 1;
                    aux/=2;
                }
                mult2[i]=f;              
            }

            //tamanho q do intervalo [a,b]
            long long int q=b-a;

            //combinacao = ((primos-1)+q)! / (primos-1)!q!
            //ver qntos fatores de 2 tem no numerador e qntos no denominador
            long long int num=0; //numerador (vai guardar qtd de fatores)
            long long int div=0; //divisor
            long long int aux_num=primos-1+q; //(vai guardar o numero maior atual do fatorial)
            long long int aux_div=menor(primos-1,q); 
            for(long long int j=0; j<menor(primos-1,q); j++){
                if(aux_num >= tam_max){
                    //calcular quantas vezes 2 divide aux_num
                    long long int aux = aux_num;
                    long long int mult = 0;
                    while (aux%2==0){
                        mult += 1;
                        aux/=2;
                    }
                    num+=mult;                              
                }
                else num+=mult2[aux_num];

                aux_num--;
                div+=mult2[aux_div];
                aux_div--;
            }

            // aux_div=q; //fazer agr fatorial para q no denominador
            // for(long long int j=0; j<q; j++){
            //     if(aux_num >= tam_max){
            //         //calcular quantas vezes 2 divide aux_num
            //         long long int aux = aux_num;
            //         long long int mult = 0;
            //         while (aux%2==0){
            //             mult += 1;
            //             aux/=2;
            //         }
            //         num+=mult;                              
            //     }
            //     else num+=mult2[aux_num];
            //     aux_num--;
            //     div+=mult2[aux_div];
            //     aux_div--;
            // }


            //se tem mais fatores de 2 no numerador do que no denominador tem pares escolhas
            if(num-div > 0) printf("Bob\n");
            else printf("Alice\n");
        }
        
    }
    
    

    return 0;
}