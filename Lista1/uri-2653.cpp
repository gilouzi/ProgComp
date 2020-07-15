#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <set>

using namespace std;
 
int main() {
 
    int quant=0;
    int t;
    char joia[100040];
    //vector <string> joias;
    vector <int> tam;
    
    set<string> joias;
    
    while(scanf("%s", joia) != EOF){
        joias.insert(joia);
    }
//    while(scanf("%s", joia) != EOF){
//        t = strlen(joia);
//        printf("%s",joia);
//        for(int i=0; i<joias.size(); i++){
//            if(tam[i] == t){
//                for(int j=0; j<t; j++){
//                    if(joia[j] != joias[i][j]){
//                        break;
//                    }
//                }
//            }
//            if(i==joias.size()-1){
//                joias.push_back(joia);
//                tam.push_back(t);
//                quant++;
//            }
//        }
//        if(joias.size()==0){
//            joias.push_back(joia);
//            tam.push_back(t);
//            quant++;
//        }
//    }
//
//    printf("%d\n", quant);
    printf("%d\n", (int)joias.size());
    return 0;
}
