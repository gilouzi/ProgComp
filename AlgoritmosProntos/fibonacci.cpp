// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define tam_max 50

int f[tam_max];

// int fibonacci(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     return fibonacci(n-1)+fibonacci(n-2);
// }

int fibonacci(int n){
    return f[n];
}

int main() {
    int n;

    f[0]=0;
    f[1]=1;
    for(int i=2; i<tam_max; i++){
        f[i]=f[i-1]+f[i-2];
    }


    return 0;
}