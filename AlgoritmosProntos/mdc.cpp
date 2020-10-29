// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int mdc(int a, int b){
    if(a<b){
        int aux = a;
        a=b;
        b=aux;
    }
    if(b==0) return a;
    return mdc(b,a%b);
}

int main() {
    
    return 0;
}