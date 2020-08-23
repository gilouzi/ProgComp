#include <bits/stdc++.h>
 
using namespace std;

int main() {

    string s1,s2,s3;
    int d;
    char c;
    char s[6];
    map <int, string> b1;
    map <string, int> b2;

    b1.insert(pair<int,string>(1,"*..."));
    b1.insert(pair<int,string>(2,"*.*."));
    b1.insert(pair<int,string>(3,"**.."));
    b1.insert(pair<int,string>(4,"**.*"));
    b1.insert(pair<int,string>(5,"*..*"));
    b1.insert(pair<int,string>(6,"***."));
    b1.insert(pair<int,string>(7,"****"));
    b1.insert(pair<int,string>(8,"*.**"));
    b1.insert(pair<int,string>(9,".**."));
    b1.insert(pair<int,string>(0,".***"));

    b2.insert(pair<string,int>("*...",1));
    b2.insert(pair<string,int>("*.*.",2));
    b2.insert(pair<string,int>("**..",3));
    b2.insert(pair<string,int>("**.*",4));
    b2.insert(pair<string,int>("*..*",5));
    b2.insert(pair<string,int>("***.",6));
    b2.insert(pair<string,int>("****",7));
    b2.insert(pair<string,int>("*.**",8));
    b2.insert(pair<string,int>(".**.",9));
    b2.insert(pair<string,int>(".***",0));


    scanf("%d",&d);

    while(d!=0){
        scanf(" %c",&c);

        if(c=='S'){
            //mensagem de d digitos decimais para traduzir para braile
            cin.ignore();
            getline( cin, s1);
            for(int i=0; i<d-1; i++){
                printf("%c%c ", b1.find(s1[i]%48)->second[0],b1.find(s1[i]%48)->second[1]);
            }
            printf("%c%c", b1.find(s1[d-1]%48)->second[0],b1.find(s1[d-1]%48)->second[1]);
            printf("\n");
            for(int i=0; i<d-1; i++){
                printf("%c%c ", b1.find(s1[i]%48)->second[2],b1.find(s1[i]%48)->second[3]);
            }
            printf("%c%c", b1.find(s1[d-1]%48)->second[2],b1.find(s1[d-1]%48)->second[3]);
            printf("\n");
            for(int i=0; i<d-1; i++){
                printf(".. ");
            }
            printf("..");
            printf("\n");
        }
        else{
            //proximas tres linhas mensagem composta de d celulas braile p/ traduzir
            cin.ignore();
            getline( cin, s1);
            getline( cin, s2);
            getline( cin, s3);
            for(int i=0; i<3*d; i+=3){
                s[0]=s1[i];
                s[1]=s1[i+1];
                s[2]=s2[i];
                s[3]=s2[i+1];
                s[4]='\0';
                printf("%d", b2.find(s)->second);
            }
            printf("\n");
        }
        
        scanf("%d",&d);
    }
 
    return 0;
}

