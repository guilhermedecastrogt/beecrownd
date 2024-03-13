#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    double n, n1, media;
    cin>>n;
    
    while(n > 10 or n < 0){
        cout<<"nota invalida"<<endl;
        cin>>n;
    }
    n1 = n;
    cin>>n;
    while(n > 10 or n < 0){
        cout<<"nota invalida"<<endl;
        cin>>n;
    }
    media = (n1 + n) / 2;
    cout<<"media = "<<fixed<<setprecision(2)<<media<<endl;
}