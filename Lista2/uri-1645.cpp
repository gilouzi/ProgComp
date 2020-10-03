// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long c[101][101];
unsigned long long f[112];

unsigned long long fat(int k){
    int F;
    if(k==1 || k==0) F = 1;
    else if (f[k] != -1) F = f[k];
    else F = k*fat(k-1);

    return f[k] = F;
}

// unsigned long long fat(int k){
//     return f[k];
// }

unsigned long long comb(int x,int k){
    return fat(x)/(fat(k)*fat(x-k));
}

long long combination(int x, int y){
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(i == j || j == 0){
                c[i][j] = 1;
            } else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
    return c[x][y];
}

int main() {
    int n,k;

    // f[0]=1;
    // f[1]=1;
    // for(int i=2; i<112; i++) {f[i] = i*f[i-1];
    // printf("%llu\n", f[i]);}

    // for(int i=2; i<112; i++) f[i] = -1;

    scanf("%d %d", &n, &k);

    combination(100,100);

    while(n != 0 && k != 0){
        int seq[n];
        int max[n];
        vector<int> m[n];
        int qtd[n];
        vector<int> q[n];
        for(int i=0; i<n; i++) scanf("%d", &seq[i]);

        long long t = 0;

        if(k == 1) t=n;
        else{
            max[0] = 1; 
            m[0].push_back(1);
            // printf("%d/n", m[0][m[0].size()-1]);
            qtd[0] = 1;
            q[0].push_back(1);
            for(int i=1; i<n; i++){
                max[i]=1;
                m[i].push_back(1);
                qtd[i]=1;
                q[i].push_back(1);
                int val=seq[i];

                // printf("%d/n", m[i][tam_i]);
                for(int j=i-1; j>=0; j--){
            //         // if(seq[j] < seq[i]) {
            //         //     if(max[i] < max[j]+1){
            //         //         max[i] = max[j]+1;
            //         //         qtd[i] = qtd[j];
            //         //     }
            //         //     else if(max[i] == max[j]+1){
            //         //         qtd[i]+=qtd[j];
            //         //     }
            //         // }
                    if(seq[j] < seq[i]) {
                        int tam_i = m[i].size()-1;
                        int tam_j = m[j].size()-1;
                        if(m[i][tam_i] <= m[j][tam_j]+1){
                            for (int w=0; w<=tam_j; w++){
                                if(tam_i < w){
                                    // printf("entrei1\n");
                                    m[i].push_back(m[j][w]+1);
                                    q[i].push_back(q[j][w]);
                                }
                                else if(m[i][w] == 1){
                                    // printf("entrei2\n");
                                    m[i][w] = m[j][w]+1;
                                    q[i][w] = q[j][w];
                                }
                                else if(m[i][tam_i] <= m[j][tam_j]+1){
                                    int x=w;
                                    while(x <= tam_i){
                                        if(m[i][x] == m[j][w]+1) {
                                            // printf("entrei3\n");
                                            q[i][x]+=q[j][w];
                                            w++;
                                        }
                                        x++;
                                    }
                                    if(w<=tam_j){
                                        // printf("entrei4\n");
                                        m[i].push_back(m[j][w]+1);
                                        q[i].push_back(q[j][w]);
                                        w++;
                                    }
                                }
                                int tam_i = m[i].size()-1;
                                // for(int s=0; s<=tam_i; s++) printf("%d %d %d: %d %d\n",i, j, w, q[i][s], m[i][s]);
                            }
                            // if(m[i][tam_i] == 1){
                            //     m[i][tam_i] = m[j][tam_j]+1;
                            //     q[i][tam_i] = q[j][tam_j];
                            // }
                            // else{
                            //     printf("entrei\n");
                            //     printf("%d: %d %d\n",i, q[i][tam_i], m[i][tam_i]);
                            //     m[i].push_back(m[j][tam_j]+1);
                            //     q[i].push_back(q[j][tam_j]);
                            // }
                        }
                        else if(m[i][0] <= m[j][tam_j]+1){
                            if(m[i][0] == m[j][0]) {
                                m[i][w] = m[j][w]+1;
                                q[i][w] = q[j][w];
                            }
                        }
                        // else if(m[i][tam_i] == m[j][tam_j]+1){
                        //     q[i][tam_i] += q[j][tam_j];
                        // }
                    }
                }
                // printf("Valor: %d, max: %d\n", seq[i], max[i]);
                // if(seq[i-1] < seq[i]) max[i] = max[i-1]+1;
                // else{
                //     int j = i-2;
                //     while(j > -1){
                //         if(seq[j] > seq[i]) j--;
                //         else {
                //             max[i] = max[j]+1;
                //             j=-2;
                //         }
                //     }
                //     if (j==-1) max[i]=1;
                // }
                
                // if(max[i] >= k) t+=qtd[i]*c[max[i]-1][k-1];
                int tam_i = m[i].size()-1;
                // for(int j=0; j<=tam_i; j++) printf("%d: %d %d\n",i, q[i][j], m[i][j]);
                while(tam_i >= 0 && m[i][tam_i] >= k){
                    // printf("  %d %d %d\n", q[i][tam_i], m[i][tam_i], tam_i);
                    t+=q[i][tam_i]*c[m[i][tam_i]-1][k-1];
                    tam_i--;
                }
                // printf("\n\n");
            }
        }
        
        printf("%llu\n", t);
        scanf("%d %d", &n, &k);
    }


    return 0;
}