// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define dez6 2000001

int crivo[dez6];
int divSum[dez6];
int hiperPrimSum[dez6];

int main() {
    int n;

    hiperPrimSum[1] = 0;
    for(int i=2; i<dez6; i++){
        crivo[i] = 1;
        divSum[i] = 1;
        hiperPrimSum[i] = 0;
    }
    for(int i=2; i<dez6; i++){
        //se i for primo
        if(crivo[i]==1){
            //divisores de i sao ele mesmo e 1 (1 ja é considerado)
            divSum[i] += 1;
            //tem 2 div, logo é hiper primo
            hiperPrimSum[i] = hiperPrimSum[i-1]+1;
            //iterar pelos multiplos j de i
            for(int j=i+i; j<dez6; j+=i) {
                //j nao é primo
                crivo[j] = 0;
                //calcular quantas vezes i divide j
                int aux = j;
                int f = 0;
                while (aux%i==0){
                    f += 1;
                    aux/=i;
                } 
                //i vai multiplicar cada div ja existente de j por j e por f gerando novos divs
                divSum[j]+=(f*divSum[j]);  
            }
        }
        //se i nao for primo pode ser hiperprimo
        else{
            if(crivo[divSum[i]] == 1) hiperPrimSum[i] = hiperPrimSum[i-1]+1;
            else hiperPrimSum[i] = hiperPrimSum[i-1];
        }
    }
    
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", hiperPrimSum[n]);
        // for(int i=2; i<n; i++) printf("%d: divSum = %d, hiperPrimSum = %d\n",i, divSum[i], hiperPrimSum[i]);
    }


    return 0;
}