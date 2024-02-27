#include <iostream>

using namespace std;

int main(){

    int N, n2, menor, posicao;
    cin>>N;
    n2 = N;
    int X[N];

    for(int i = 0; i < n2; i++){
        cin>>X[i];
        if(i == 0){
            menor = X[0];
            posicao = 0;
        }
        else{
            if(X[i] < X[i-1] and X[i] < X[0]){
                menor = X[i];
                posicao = i;
            }
        }
    }
    cout<<"Menor valor: "<<menor<<endl;
    cout<<"Posicao: "<<posicao<<endl;
}