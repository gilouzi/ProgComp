// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int q=0;
    int qa=0;
    int n=0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A') qa+=q;
        if(s[i] == 'Q'){
            q+=1;
            n+=qa;
        }  
    }

    printf("%d\n", n);


    return 0;
}