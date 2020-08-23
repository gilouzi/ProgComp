#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    char msg[10001];
    char crib[10001];
    // int abc[26];
    int pos = 0;

    // for (int i=0; i<26; i++){
    //     abc[i]=0;
    // }
    
    scanf("%s", msg);
    scanf("%s", crib);

    int tam_msg = strlen(msg);
    int tam_crib = strlen(crib);
    int fake = 0;
//    printf("A = %d, msg: %d, crib:%d\n", 'A'%65, tam_msg, tam_crib);

     for(int i=0; i<(tam_msg-tam_crib)+1; i++){
         for(int j=0; j<tam_crib; j++){
             if(crib[j]==msg[i+j]){
                 fake=1;
                 break;
             }
         }
         if (fake==0) pos++;
             else fake=0;
     }
    // for(int i=0; i<tam_crib; i++){
    //     abc[crib[i]%65]++;
    // }

    // for(int i=0; i<tam_msg; i++){
    //     pos+=abc[msg[i]%65];
    // }

    printf("%d\n", pos);
//    printf("A = %d, msg: %d, crib:%d\n", 'A'%65, tam_msg, tam_crib);
 
    return 0;
}
