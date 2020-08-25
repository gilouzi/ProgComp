#include <bits/stdc++.h>
using namespace std;

void insert(int node, int head, pair <int, int> *tree, int *s){
    if(s[node] < s[head]){
        if(tree[head].first == -1) tree[head].first = node;
        else insert(node, tree[head].first, tree, s);
    }
    else {
        if(tree[head].second == -1) tree[head].second = node;
        else insert(node, tree[head].second, tree, s);
    }
}

void print(int node, pair <int, int> *tree){
    if(tree[node].first != -1){
        print(tree[node].first, tree);
    }
    if(tree[node].second != -1){
        print(tree[node].second, tree);
    }
    printf("%c",node);
}
int main() {

    int c,n;
    string s1, s2, s3;
    scanf("%d",&c);
    for(int i=0; i<c; i++){
        scanf("%d",&n);
        int s[130];
        pair <int, int> tree[130];
        for(int i=0; i<130; i++) {
            s[i] = -1;
            tree[i].first = -1; //esquerda
            tree[i].second = -1; //direita
        }
        cin >> s1 >> s2;
        for(int i=0; i<n; i++) s[s2[i]]=i;
        for(int i = 1; i < n; i++){
            insert(s1[i], s1[0], tree, s);
        }
        print(s1[0], tree);
        printf("\n");
        // s3 = s2;
        // s3[n] = s1[0];
        // for(int i=1; i<n-1; i++){
        //     int atual = s[s1[i]];
            
        // }
    }
    return 0;
}