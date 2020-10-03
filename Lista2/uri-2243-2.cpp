// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int MIN(int i, int j){
    return i<j ? i : j;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int e[n];
    e[0] = 1;
    for(int i=1; i<n; i++){
        e[i] = MIN(a[i], e[i-1]+1);
    }
    
    int d[n];
    d[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        d[i] = MIN(a[i], d[i+1]+1);
    }

    int max = 1;
    for(int i=1; i<n; i++){
        int min = MIN(d[i], e[i]);
        if(min > max) max = min;
    }

    printf("%d\n", max);

    return 0;
}