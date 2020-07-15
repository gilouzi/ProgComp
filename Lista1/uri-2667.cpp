#include <iostream>
 
using namespace std;

int main() {

    string n;
    int t=0;

    getline( cin, n);

    for(int i=0; i<n.size(); i++){
        t+=n[i]%48;
    }
    printf("%d\n",t%3);
 
    return 0;
}

