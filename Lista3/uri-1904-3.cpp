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

        for(int i=1; i<tam_max; i++){
            //calcular quantas vezes 2 divide i
            int aux = i;
            int f = 0;
            while (aux%2==0){
                f += 1;
                aux/=2;
            }
            mult2[i]=f;              
        }

        int q=b-a;

        //f = soma das escolhas
        //se a qtd de escolhas calculada for impar soma 1 a f
        //se for par nao faz nada (da na msm)

        //se escolher so um primo p/ fazer parte da escolha
        //escolhas = quantidade de primos
        int f=primos%2+2;

        //se escolher x dos primos p/ fazer parte da escolha
        //fazer a conta de quantos grupos de x pode ser formado
        //se for par a quantidade de grupos de x, escolhas é par (vai multiplicar por par)
        //se nao ve se a combinacao formada por x numeros distintos é par ou impar
        if(q>1){
            //i = quantidade de primos distintos que vao fatorar o numero
            for(int i=2; i<=q; i++){
                int n=0; //qtd de grupos de i possiveis
                int num=0; //numerador
                int div=0; //divisor
                int aux_num = primos;
                int aux_div = i; 
                for(int j=0; j<i; j++){
                    num+=mult2[aux_num];
                    aux_num--;
                    div+=mult2[aux_div];
                    aux_div--;
                }
                //se tem mais fatores de 2 no divisor do que no numerador tem impares grupos
                if(num-div < 0) {
                    //ver se a combinacao é par ou impar
                    //i valores em tamanho q
                }

            }
        }

        printf("primos: %d, q: %d, f:%d\n",primos,q,f);
        if(f%2==0) printf("Bob\n");
        else printf("Alice\n");

        for(int i=2; i<126; i++){
            printf("%d: %d fatores\n",i,mult2[i]);
        }
    }
    
    

    return 0;
}