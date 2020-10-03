// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int r[110][110][110];

int save1(int t1, int t2, int t3){
    r[t1][t2][t3] = 1;
    return 1;
}

int y(int *p1, int t1, int *p2, int t2, int *p3, int t3){
    //se ja cheguei no fim
    if(t1 == 0 && t2 == 0 && t3 == 0) return save1(0,0,0);

    //se ja calculei
    if(r[t1][t2][t3] != -1) return r[t1][t2][t3];
    
    //se consigo tirar as tres de cima
    if(t1 != 0 && t2 != 0 && t3 != 0 && (p1[t1]+p2[t2]+p3[t3])%3 == 0) if(y(p1,t1-1,p2,t2-1,p3,t3-1) == 1) return save1(t1,t2,t3);

    //se consigo tirar duas de cima
    //primeira e segunda
    if(t1 != 0 && t2 != 0 && (p1[t1]+p2[t2])%3 == 0) if(y(p1,t1-1,p2,t2-1,p3,t3) == 1) return save1(t1,t2,t3);
    //primeira e terceira
    if(t1 != 0 && t3 != 0 && (p1[t1]+p3[t3])%3 == 0) if(y(p1,t1-1,p2,t2,p3,t3-1) == 1) return save1(t1,t2,t3);
    //segunda e terceira
    if(t2 != 0 && t3 != 0 && (p2[t2]+p3[t3])%3 == 0) if(y(p1,t1,p2,t2-1,p3,t3-1) == 1) return save1(t1,t2,t3);

    //se consigo tirar uma
    //primeira
    if(t1 != 0 && (p1[t1])%3 == 0) if(y(p1,t1-1,p2,t2,p3,t3) == 1) return save1(t1,t2,t3);
    //segunda
    if(t2 != 0 && (p2[t2])%3 == 0) if(y(p1,t1,p2,t2-1,p3,t3) == 1) return save1(t1,t2,t3);
    //terceira
    if(t3 != 0 && (p3[t3])%3 == 0) if(y(p1,t1,p2,t2,p3,t3-1) == 1) return save1(t1,t2,t3);

    r[t1][t2][t3] = 0;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n!=0){
        int p1[n+1];
        int t1 = n;
        int p2[n+1];
        int t2 = n;
        int p3[n+1];
        int t3 = n;
        for(int i=n; i>0; i--){
            scanf("%d %d %d", &p1[i], &p2[i], &p3[i]);
        }

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int w=0; w<=n; w++){
                    r[i][j][w] = -1;
                }
            }
        }

        printf("%d\n", y(p1, t1, p2, t2, p3, t3));

        scanf("%d", &n);
    }
    return 0;
}