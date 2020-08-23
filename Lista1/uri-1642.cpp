#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int m, max, used, j;
    int c[256];
    string t;
    
    scanf("%d",&m);
    while (m != 0){
        for(int i=0; i<256; i++){
            c[i]=0;
        }
        // printf("Entrei aqui\n");
        max = 0;
        used = 0;
        j = 0;

        cin.ignore();
        getline(cin, t);

        // printf("T: %s\n", t.c_str());
        for(int i=0; i<t.size(); i++){
            if(c[t[i]] != 0){ //carac ja esta sendo utilizado, pode so adicionar
                c[t[i]]++;
            }
            else{ //carac nao ta sendo usada ainda, tem q tratar
                if(used<m){ //nao atingiu o limite ainda de carac q podem ser usados
                    used++;
                    c[t[i]]++;
                }
                else{ //atingiu o limite tem que remover um caracter pra add novo
                    while(j<i){
                        c[t[j]]--;
                        j++;
                        if(c[t[j-1]]==0) break;
                    }
                    c[t[i]]++;
                }
            }
            if((i-j)+1 > max) max=i-j+1;
        }
        printf("%d\n", max);
        scanf("%d",&m);
    }
    
    return 0;
}
