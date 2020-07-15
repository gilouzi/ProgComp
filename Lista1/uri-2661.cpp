#include <iostream>
#include <vector> 
#include <cmath>
 
int fat(int n){
    if(n==1) return 1;
    return n*fat(n-1);
}

int fat_i(int f, int i){
    if(i==1) return f;
    else return f*fat_i(f-1,i-1);
}
using namespace std;

int main() {

    long long int n,N;
    int f=0;

    scanf("%lld",&N);
    n=N;

    if(n%2==0){
        f++;
        while (n%2==0){
            n=n/2;
        }
    }

    long long int d1=1;
    long long int d2=3;

    while(d2<=sqrt(N)){
        if(n%d2==0){
            n=n/d2;
            if(d2 != d1){
                f++;
                d1=d2;
            }
        }
        else{
            d2+=2;
        }
    } 

    if(n!=1){ //ultimo fator é o proprio n
        f++;
    }

    if(f<=1){
        printf("0\n");
        return 0;
    }

    int res=0;

    // printf("%d\n",f);
    for(int i=2; i<f; i++){
        res+=fat_i(f,i)/fat(i);
    }

    res++;

    printf("%d\n",res);

 
    return 0;
}

