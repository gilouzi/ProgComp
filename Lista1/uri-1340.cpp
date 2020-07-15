#include <iostream>
#include <vector> 
#include <stack>

using namespace std;

int main() {

    int s,q,p;
    int aux;
    int n, c, x;


    while(scanf("%d", &n) != EOF){
        s=1;
        q=1;
        p=1;

        stack <int> stck;
        vector <int> queue;
        vector <int> prty;
        make_heap(prty.begin(), prty.end());
        for(int i=0; i<n; i++){
            scanf("%d %d", &c, &x);
            if(c==1){
                stck.push(x);
                queue.push_back(x);
                prty.push_back(x);
                push_heap(prty.begin(), prty.end());
            }
            else{
                aux = stck.top();
                stck.pop();
                if(aux != x){
                    s=0;
                }
                aux = queue[0];
                queue.erase(queue.begin());
                if(aux != x){
                    q=0;
                }
                aux = prty.front();
                pop_heap(prty.begin(), prty.end());
                prty.pop_back();
                if(aux != x){
                    p=0;
                }
            }
        }
        if(s==0 && q==0 && p==0) printf("impossible\n");
        else if(s==1 && q==0 && p==0) printf("stack\n");
        else if(s==0 && q==1 && p==0) printf("queue\n");
        else if(s==0 && q==0 && p==1) printf("priority queue\n");
        else printf("not sure\n");
    }
   
 
    return 0;
}

