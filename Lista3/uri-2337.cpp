// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define tam_max 50

long long int f[tam_max];
long long int e2[tam_max];

long long int fibonacci(int n){
    return f[n];
}

long long int exp(int n, int e){
    if(e==0) return 1;
    int m=exp(n,e/2);
    if(e%2 == 0) return m*m;
    else return m*m*n;
}

long long int mdc(long long int a, long long int b){
    if(a<b){
        int aux = a;
        a=b;
        b=aux;
    }
    if(b==0) return a;
    return mdc(b,a%b);
}

int main() {
    int n;

    //inicializando fibonacci
    f[0]=0;
    f[1]=1;
    for(int i=2; i<tam_max; i++){
        f[i]=f[i-1]+f[i-2];
    }

    //inicializando exponencial
    e2[0]=1;
    for(int i=1; i<tam_max; i++){
        e2[i]=e2[i-1]*2;
    }
    
    while (scanf("%d", &n) != EOF) {
        // printf("%d: ",n);
        long long int num=fibonacci(n+2);
        // printf("fib=%lld ",num);
        long long int den=e2[n];
        // printf("exp=%lld ",den);
        long long int div = mdc(den,num);
        // printf("div=%lld\n",div);
        printf("%lld/%lld\n",num/div,den/div);
    }


    return 0;
}