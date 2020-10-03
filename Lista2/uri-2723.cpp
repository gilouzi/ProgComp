// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dif(int a,int b){
    return abs(a-b);
}

bool x(int j, int n, int *p, int a, int b){
    
    if (dif(a,b) > 5) return false;
    else if(j==n) return true;
    
    if(x(j+1, n, p, a+p[j],b) == true) return true;
    else if(x(j+1, n, p, a,b+p[j]) == true) return true;

    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int p[n];
        for(int j=0; j<n; j++) {
            scanf("%d", &p[j]);
        }

        int c = x(0,n,p,0,0);

        if (c == true) printf("Feliz Natal!\n");
        else printf("Ho Ho Ho!\n");
        

    }
    return 0;
}