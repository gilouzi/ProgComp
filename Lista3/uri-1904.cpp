// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define int_max 10000001

int crivo[int_max];
int divSum[int_max];

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

        for(long long int i=2; i<int_max; i++){
            crivo[i] = 1;
            divSum[i] = 0;
        }

        for(long long int i=2; i<int_max; i++){
            //se i for primo
            if(crivo[i]==1){
                //fator de i é ele mesmo
                divSum[i] += 1;
                //iterar pelos multiplos j de i
                for(int j=i+i; j<int_max; j+=i) {
                    //j nao é primo
                    crivo[j] = 0;
                    if(i>=a && i<=b){
                        //calcular quantas vezes i divide j
                        int aux = j;
                        int f = 0;
                        while (aux%i==0){
                            f += 1;
                            aux/=i;
                        }
                        divSum[j]+=f; 
                    }
                    else divSum[j]=0;                    
                }
            }
        }
        int n=0;
        int f = b-a;
        for(int i=0; i<int_max; i++) if(divSum[i]==f) n++;
        if(n%2==0) printf("Bob\n");
        else printf("Alice\n");

        // for(int i=2; i<126; i++){
        //     printf("%d: %d fatores\n",i,divSum[i]);
        // }
    }
    
    

    return 0;
}