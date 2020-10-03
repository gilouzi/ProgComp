// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n,k;
        scanf("%d %d", &n, &k);

        int s=0;
        if(n >=k){
            int x = n/k;
            s=x*k;
            n=n-s;
        }

        if(n >= k/2) s+=k/2;
        else s+=n;

        printf("%d\n",s);
    }

    return 0;
}