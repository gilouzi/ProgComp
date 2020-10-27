// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int MAX(int i, int j){
    return i>j ? i : j;
}

int MIN(int i, int j){
    return i<j ? i : j;
}

int m1[1001][1001];

int m2[1001][1001];

int j1(int *c, int p1, int i, int j){

    if(i>j) return p1;
    // if(p1 + p2 == n) return p1;

    int o1, o2, o3;

    o1 = -1;
    o2 = -1;
    o3 = -1;

    if(m1[i][j] != -1) return m1[i][j];

    if(c[i]%2 == 0 && c[j]%2 == 0){
        if(c[i+1]%2 == c[j-1]%2){
            o1 = j1(c, p1+1, i+1, j-1);
        }
        if(c[i+1]%2 == 0){
            o2 = j1(c, p1+1, i+2, j);
        }
        if(c[j-1]%2 == 0){
            o3 = j1(c, p1+1, i, j-2);
        }

        o1, -1, -1
        o1, o2, -1 -> jog 2 q define
        o1, -1, o3 ->
        o1, o2, o3
        return m1[i][j]=MIN(o1,o2),MIN(o1,o3);
    }
    
    else if(c[i]%2 != 0 && c[j]%2 == 0){
        if(c[j-1]%2 == 0){
            o1 = j1(c, p1+1, i, j-2);
        }
        else {
            o2 = j1(c, p1+1, i, j-2);
            o3 = j1(c, p1+1, i+1, j-1);
        }
        return m1[i][j]=MAX(o1, MIN(o2,o3));
    }

    else if(c[i]%2 == 0 && c[j]%2 != 0){
        if(c[i+1]%2 == 0){
            o1 = j1(c, p1+1,i+2, j);
        }
        else {
            o2 = j1(c, p1+1, i+2, j);
            o3 = j1(c, p1+1, i+1, j-1);
        }
        return m1[i][j]=MAX(o1, MIN(o2,o3));
    }

    else {
        o1 = j1(c,p1,i+1,j-1);
        o2 = j1(c,p1,i+2,j);
        o3 = j1(c,p1,i,j-2);
        return m1[i][j]=MAX(o1, MIN(o2,o3));
    }

  

    
    
}

int main() {
    int n;
    scanf("%d", &n);

    while (n!=0){
        int c[2*n];
        for(int i=0; i<2*n; i++){
            scanf("%d", &c[i]);
        }

        for(int i=0; i<2*n; i++){
            for(int j=0; j<2*n; j++){
                m1[i][j]=-1;
                m2[i][j]=-1;
            }
        }

        printf("%d\n", j1(c,0,0,(2*n)-1));

        scanf("%d", &n);
    }
    return 0;
}