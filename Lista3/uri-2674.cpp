// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int crivo[100001];

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
    for(int i=2; i<100001; i++){
        crivo[i] = 1;
    }
    for(int i=2; i<100001; i++){
        if(crivo[i]==1){
            for(int j=i+i; j<100001; j+=i) crivo[j] = 0;
        }
    }
    
    while (scanf("%d", &n) != EOF) {
        if(primo(n)){
            int i=1;
            int super = 1;
            while(i <= n){
                if(!primo((n%(i*10))/i)){
                    super=0;
                    i = n+1;
                }
                else i*=10;
            }
            if(super==1) printf("Super\n");
            else printf("Primo\n");
        }
        else printf("Nada\n");
    }


    return 0;
}