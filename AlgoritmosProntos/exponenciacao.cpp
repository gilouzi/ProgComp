// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// int exp(int n, int e){
//     if(e==0) return 1;
//     int aux=n;
//     for(int i=2; i<=e; i++) aux*=n;
//     return aux;
// }

int exp(int n, int e){
    if(e==0) return 1;
    int m=exp(n,e/2);
    if(e%2 == 0) return m*m;
    else return m*m*n;
}

int main() {
    

    return 0;
}