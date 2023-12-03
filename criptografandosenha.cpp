#include <iostream>

using namespace std;

int main(){
    
    int senha = 338342310949, cinsenha;
    cinsenha = 0;

    while(cinsenha != senha){
        cout<<"Senha Invalida"<<endl;
        cinsenha++;
    }
    cout<<"Acesso Permitido"<<endl;
    
    return 0;
}