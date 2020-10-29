// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define tam_max 100001

int crivo[tam_max];

// bool primo(int n){
//     for(int i=2; i<n; i++){
//         if(n%i == 0) return false;
//     }
//     return true;
// }

bool primo(int n){
    if(crivo[n]==0) return false;
    return true;
}

int main() {
    int n;

    crivo[0] = 0;
    crivo[1] = 0;
    for(int i=2; i<tam_max; i++){
        crivo[i] = 1;
    }
    for(int i=2; i<tam_max; i++){
        if(crivo[i]==1){
            for(int j=i+i; j<tam_max; j+=i) crivo[j] = 0;
        }
    }


    return 0;
}