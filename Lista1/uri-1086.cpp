#include <iostream>
 
using namespace std;

void quicksort(int *v, int b, int e)
{
    if (b >= e){
        return;
    }
    
    int pivot = v[e];
    int j = b;

    for (int i=b; i<=e; i++){
        if (v[i] <= pivot){
            int aux=v[j];
            v[j]=v[i];
            v[i]=aux;
            j++;
        }
    }
    
    quicksort(v, b, j-2); // Recursively sort the left side of pivot
    quicksort(v, j, e);   // Recursively sort the right side of pivot
}

int sol(int *x, int k, int s1, int s2, int l, int r1){
    int i=0;
    int j=k-1;
    int res=0;
    int u=0;


    //tirar os tamanhos que nao cabem
    while(x[j] > s1){
            j--;
        }

    //ir colocando o maior tamanho como parte da resposta
    while(x[j] == s1){
        res++;
        j--;
        u+=l;
        if(u==s2) return res;
        if(r1!=0 && res>r1) return 0;
       // else if(res1!=0 && res>res1) return 0;
    }

    //ir formando os pares para encaixar
    while(j>i){
        if(x[j]+x[i] == s1){
            res+=2;
            j--;
            i++;
            u+=l;
            if(u==s2) return res;
            if(r1!=0 && res>r1) return 0;
            //else if(res1!=0 && res>res1) return 0;
        }
        else if(x[j]+x[i] < s1){
            i++;
        }
        else if(x[j]+x[i] > s1){
            j--;
        }
    }

    return 0;
}

int main() {

    int n,m,l,k;

    
    scanf("%d %d", &n, &m);

    while(n!=0 && m!=0){
        scanf("%d",&l);
        scanf("%d",&k);
    
        int x[k];
        for(int i=0; i<k; i++){
            scanf("%d", &x[i]);
            x[i]=x[i]*100;
        }

        // for(int i=0; i<k; i++){
        //     printf("%d ", x[i]);
        // }
        // printf("\n");
        quicksort(x,0,k-1);
        // for(int i=0; i<k; i++){
        //     printf("%d ", x[i]);
        // }
        // printf("\n");

        m=m*100;
        n=n*100;
        int s1 = sol(x,k,n,m,l,0);
        int s2 = sol(x,k,m,n,l,s1);

        //printf("s1:%d s2:%d\n",s1,s2);

        if(s1==0 && s2==0) printf("impossivel\n");
        else if (s2==0 || (s1<s2 && s1!=0) ) printf("%d\n",s1);
        else printf("%d\n",s2);

        scanf("%d %d", &n, &m);
    }
 
    return 0;
}

