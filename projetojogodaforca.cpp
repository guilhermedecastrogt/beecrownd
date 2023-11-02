#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int gerarNumeroAleatorio(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void exibirProgresso(const string& palavraOculta, const vector<bool>& letrasDescobertas) {
    for (size_t i = 0; i < palavraOculta.length(); ++i) {
        if (letrasDescobertas[i]) {
            cout << palavraOculta[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}
int main(){

    
    cout<<"JOGO DA FORCA TEMA: PARTES DO CORPO"<<endl;
    cout<<"BOA SORTE!"<<endl;

    string PALAVRA;

    string X[6];

    X[1] = "barriga";
    X[0] = "ombro";
    X[2] = "braco";
    X[3] = "mao";
    X[4] = "perna";
    X[5] = "cabeca";
    X[6] = "pe";

    int numeroAleatorio = gerarNumeroAleatorio(0,6);

    for(int i = 0; i < 6; i++){
        if(i == numeroAleatorio){
            string PALAVRA = X[i];
        }
    }

    string palavraOculta = PALAVRA;
    vector<bool> letrasDescobertas(palavraOculta.length(), false);

    int tentativas = palavraOculta.length() * 2;

    while (true) {

        cout<<endl;
        cout<<"Voce tem "<<tentativas<<" tentativas restantes."<<endl;

        exibirProgresso(palavraOculta, letrasDescobertas);

        if(tentativas == 0){
            cout<<"Acabou suas tentativas, voce perdeu!"<<endl;
            break;
        }
        
        char letra;
        cout<<endl;
        cout<<"DIGITE A LETRA QUE VOCE ACHA QUE ENCAIXA NA PALAVRA: ";
        cin>> letra;

        bool letraEncontrada = false;
        for(size_t i = 0; i < palavraOculta.length(); ++i){
            if(letra == palavraOculta[i]){
                letrasDescobertas[i] = true;
                letraEncontrada = true;
            }
        }

        if(letraEncontrada){
            cout<<"PARABENS VOCE ACERTOU!"<<endl;
        }
        else{
            cout<<"TENTE NOVAMENTE, LETRA INCORRETA"<<endl;
        }
        
        if(letrasDescobertas == vector<bool>(palavraOculta.length(), true)){
            cout<<endl;
            cout << "PARABENS, VOCE CONSEGUIU CONCLUIR A FORCA" << endl;
            break;
        }
        tentativas--;
    }
}