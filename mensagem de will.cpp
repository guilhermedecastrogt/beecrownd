#include <iostream>

using namespace std;

int main(){

    string Letras[26];
    int N;

    for(int i = 0; i <= 25; i++){
        cin>>Letras[i];
        //cout<<i<<endl;
    }
    
    cin>>N;
    int l[N];
    
    for(int i = 0; i < N; i++){
        cin>>l[i];
        l[i] = l[i]-1;
    }
    
    for(int i = 0; i < N; i++){
        cout<<Letras[l[i]];
    }
}