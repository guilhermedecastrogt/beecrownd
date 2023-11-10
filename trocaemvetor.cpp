#include <iostream>

using namespace std;

int main(){

    int N[20];
    
    int i = 0;

    while (i <= 19){
        cin>>N[i];
        i++;
    }
    i = 0;
    for(int b = 19; b >= 0; b--){
        cout<<"N["<<i<<"] = "<<N[b]<<endl;
        i++;
    }
}