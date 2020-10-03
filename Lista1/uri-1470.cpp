// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dobra(int n, int m, int *v, int *w){
    for(int i=1; i<n; i++){
        if(i < n-i){
            int tam = n-i;
            if(tam >= m){
                int f[tam];
                for(int j=0; j<n-2*i; j++){
                    f[j]=v[n-1-j];
                }
                int k=0;
                for(int j=n-2*i; j<tam; j++){
                    f[j]=v[n-1-j]+v[k];
                    k++;
                }
                // for(int j=0; j<tam; j++){
                //     printf("%d ",f[j]);
                // }
                // printf("\n"); 
                if(tam==m){
                    int igual=1;
                    for(int j=0; j<m; j++){
                        if(f[j] != w[j]) {
                            igual=0;
                            break;
                        }
                    }
                    if(igual == 1) return 1;
                }

                if(dobra(tam,m,f,w) == 1) return 1;
            }
        }
        else{
            int tam = n-(n-i);
            if(tam >= m){
                int f[tam];
                for(int j=0; j<n-2*(n-i); j++){
                    f[j]=v[j];
                }
                int k=0;
                for(int j=n-2*(n-i); j<tam; j++){
                    f[j]=v[j]+v[n-1-k];
                    k++;
                }
                // for(int j=0; j<tam; j++){
                //     printf("%d ",f[j]);
                // }
                // printf("\n"); 
                if(tam==m){
                    int igual=1;
                    for(int j=0; j<m; j++){
                        if(f[j] != w[j]) {
                            igual=0;
                            break;
                        }
                    }
                    if(igual == 1) return 1;
                }
                
                if(dobra(tam,m,f,w) == 1) return 1;
            }
        }    
    }
    int f[n];
    for(int j=0; j<n; j++){
        f[j]=v[n-1-j];
    }
    if(n==m){
        int igual=1;
        for(int j=0; j<m; j++){
            if(f[j] != w[j]) {
                igual=0;
                break;
            }
        }
        if(igual == 1) return 1;
    }
    
    // if(dobra(n,m,f,w) == 1) return 1;
    return 0;
}
int main(){

    int m, n;
    while(scanf("%d",&n) != EOF){
        int v[n];
        for(int i=0; i<n; i++) scanf("%d",&v[i]);
        // for(int i=0; i<n; i++) printf("%d ",v[i]);
        // printf("\n");
        // printf("\n");

        scanf("%d",&m);
        int w[m]; 
        for(int i=0; i<m; i++) scanf("%d",&w[i]);

        int f[n];
        for(int j=0; j<n; j++){
            f[j]=v[n-1-j];
        }

        if(dobra(n,m,v,w) == 1) printf("S\n");
        else if(dobra(n,m,f,w) == 1) printf("S\n");
        else printf("N\n");
        
    };
    
    return 0;
}