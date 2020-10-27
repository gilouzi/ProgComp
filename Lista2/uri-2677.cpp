// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int MAX(int i, int j){
    return i>j ? i : j;
}

int MIN(int i, int j){
    return i<j ? i : j;
}

vector <pair<int,int> > m1[1000][1000];

map<string, int> m;

// int m2[1001][1001][501];

int j1(int *c, int p1, int p2, int i, int j, int n, int jog){

    if(i>j) return p1;
    // if(p1 + p2 == n) return p1;

    int o1, o2;

    if(jog == 1){
        // printf("jogador 1: p1=%d p2=%d[", p1, p2);
        // for (int ii=i; ii<=j; ii++) printf("%d ", c[ii]);
        // printf("]\n");
        
        // if(m1[i][j][p1] != -1) return m1[i][j][p1];
        // char s[15];
        // sprintf(s,"%d %d %d",i,j,p1);
        // string ss = s;
        for(int w=0; w<m1[i][j].size(); w++){
            if(m1[i][j][w].first == p1) return m1[i][j][w].second;
        }
        
        // if(m.find(ss) != m.end()) return m[ss];

        if(c[i]%2 == 0) o1 = j1(c, p1+1, p2, i+1, j, n, 2);
        else o1 = j1(c, p1, p2, i+1, j, n, 2);
        
        if(c[j]%2 == 0) o2 = j1(c, p1+1, p2, i, j-1, n, 2);
        else o2 = j1(c, p1, p2, i, j-1, n, 2);

        pair <int, int> r;
        r.first = p1;
        r.second = MAX(o1, o2);
        m1[i][j].push_back(r);
        return r.second;
    }   

    else{
        // printf("jogador 2: p1=%d p2=%d[", p1, p2);
        // for (int ii=i; ii<=j; ii++) printf("%d ", c[ii]);
        // printf("]\n");

        // if(m1[i][j][p1] != -1) return m1[i][j][p1];
        // char s[15];
        // sprintf(s,"%d %d %d",i,j,p1);
        // string ss = s;
        
        // if(m.find(ss) != m.end()) return m[ss];

        for(int w=0; w<m1[i][j].size(); w++){
            if(m1[i][j][w].first == p1) return m1[i][j][w].second;
        }

        if(c[i]%2 == 0) o1 = j1(c, p1, p2+1, i+1, j, n, 1);
        else o1 = j1(c, p1, p2, i+1, j, n, 1);

        if(c[j]%2 == 0) o2 = j1(c, p1, p2+1, i, j-1, n, 1);
        else o2 = j1(c, p1, p2, i, j-1, n, 1);

        pair <int, int> r;
        r.first = p1;
        r.second = MIN(o1, o2);
        m1[i][j].push_back(r);
        return r.second;
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
                for(int p1=0; p1<n; p1++){
                    m1[i][j].clear();
                    // m2[i][j][p1]=-1;
                }
            }
        }
        
        m.clear();

        printf("%d\n", j1(c,0,0,0,(2*n)-1,n,1));

        scanf("%d", &n);
    }
    return 0;
}