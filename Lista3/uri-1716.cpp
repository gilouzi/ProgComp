// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define tam_max 50

int main() {
    //recebe chaves publicas (n,e) e mensagem criptografada (c)
    long long int n,e,c;
    scanf("%lld %lld %lld", &n, &e, &c);

    //p e q sao primos impares
    //n = p*q
    long long p,q;
    for(int i=3; i<n; i++){
        if(n%i == 0){
            p=i;
            q=n/p;
            i=n;
        }
    }

    //fi(n) = (p-1)*(q-1)
    long long fi = (p-1)*(q-1);

    //mdc(fi(n), e) = 1
    //1 < e < fi(n)

    //d é o inverso multiplicativo de e modulo fi(n)
    //d*e = 1  (mod fi(n))

    
    //x = 1  (mod y) -> y é o menor natural tal que o resto da divisao de x por y é 1
 
    
    //encontrar o valor de d*e = de e fi(n) = fi
    //"fi" é o menor natural tal que o resto da divisao de "de" por "fi" é 1
    long long de, fi;


    //m mensagem, c mensagem criptografada
    //c = m^e  (mod n)

    //para descriptografar c
    //m = c^d  (mod n)

    //retorna a mensagem original
    long long int m;
    printf("%lld\n",m);


    return 0;
}