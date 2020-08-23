#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    double a;
    
    int val[12] = {10000,5000,2000,1000,500,200,100,50,25,10,5,1};
    int res[12];
    
    scanf("%lf", &a);
    
    int total = a*100.00;

    printf("NOTAS:\n");

    for (int i=0; i<6; i++){
        if (total>=val[i])
            res[i]=total/val[i];
        else
            res[i]=0;
        
        printf("%d nota(s) de R$ %.2lf\n", res[i], val[i]/100.00);
        if(res[i] != 0)
            total = total-res[i]*val[i];
    }

    printf("MOEDAS:\n");
    for (int i=6; i<12; i++){
        if (total>=val[i])
            res[i]=total/val[i];
        else
            res[i]=0;
        
        printf("%d moeda(s) de R$ %.2lf\n", res[i], val[i]/100.00);
        if(res[i] != 0)
            total = total-res[i]*val[i];
    }

   
 
    return 0;
}