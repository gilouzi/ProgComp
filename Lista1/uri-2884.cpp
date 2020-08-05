#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int n, m, l, x;
    string s0 = "";
    string s1 = "";
    string s2 = "";

    scanf("%d %d", &n, &m);
    vector <int> g[n];

    for(int i=0; i<n; i++){
        s0.append("o");
        s1.append("o");
        s2.append("o");
    }

    scanf("%d", &l);
    for(int i=0; i<l; i++){
        scanf("%d", &x);
        s1[x-1] = 'i';
        s2[x-1] = 'i';
    }

    // printf("%s\n", s0.c_str()); 
    // printf("%s\n", s1.c_str());
    // printf("%s\n", s2.c_str());
    
    for(int i=0; i<n; i++){
        scanf("%d", &l);
        for(int j=0; j<l; j++){
            scanf("%d", &x);
            g[i].push_back(x-1);
        }
    }

    int i=0;

    while(i<n && s0.compare(s2)!=0){
        for(int j=0; j<g[i].size(); j++){
            if (s2[g[i][j]] == 'i') s2[g[i][j]] = 'o';
            else s2[g[i][j]] = 'i';
        }
        // printf("%s\n", s2.c_str());
        i++;
    }

    if(s0.compare(s2)!=0) printf("-1\n");
    else printf("%d\n", i);
    
    return 0;
}