/*
 *      Um investidor deseja aplicar um valor inicial de R$ 10.000,00 em um
 * fundo de investimento que rende 10% ao ano. Ele deseja saber quanto terá
 * acumulado no final de n anos.
 *
 *
 *      Para resolver este problema, podemos usar uma função recursiva para
 * calcular o fatorial de n. A função recursiva deve funcionar da seguinte forma:
 *
 *      Se n for igual a 0, então o fatorial de n é igual a 1.
 *      Caso contrário, o fatorial de n é igual a n multiplicado pelo fatorial de n-1.
 * */


#include <iostream>
#include <cmath>

using namespace std;

// Função recursiva para calcular o fatorial de n
int calcularFatorial(int n) {
    if (n == 0) {
        return 1;
    }

    // Chamada recursiva
    return n * calcularFatorial(n - 1);
}

int main() {

    int n;
    double valor_acumulado;

    cout << "Digite o número de anos: ";
    cin >> n;

    // Calculando o fatorial de n
    int fatorial = calcularFatorial(n);

    valor_acumulado = 10000 * pow(1.1, n);

    cout << "O valor acumulado será de R$ " << valor_acumulado << endl;

    return 0;
}
