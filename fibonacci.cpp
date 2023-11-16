#include <iostream>

using namespace std;

int main(){

    int N, total = 0, temporario1 = 0, temporario2 = 1, cont = 1;
    cin>>N;

    if (N == 1){
        cout<<"0"<<endl;
    }
    if(N == 2){
        cout<<"0 1"<<endl;
    }
    else if (N > 2){
        for(int i = 0; i <= N - 3; i++){
            if (total == 0){
            cout<<total<<" ";
            }
            if (cont == 1){
                cout<<cont<<" ";
            }
            total = temporario1 + temporario2;
            if(i != N -3){
                cout<<total<<" ";
                temporario1 = temporario2;
                temporario2 = total;
                cont++;
            }
            else if (i == N -3){
                cout<<total<<endl;
            }
        }
    }
}