#include <iostream>

using namespace std;

int main(){

    int x, N[10];
    cin>>x;
    N[0] = x;

    for(int i = 0; i < 10; i++){
        if(i == 0){
            cout<<"N["<<i<<"] = "<<N[i]<<endl;
        }
        else{
            N[i] = N[i -1] * 2;
            cout<<"N["<<i<<"] = "<<N[i]<<endl;
        }
    }
}