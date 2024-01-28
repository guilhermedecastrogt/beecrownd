#include <iostream>

using namespace std;

int main() {
    int vet[1000], n, nv;
    cin >> n;

    vet[0] = 0;
    vet[1] = 1;

    for (int i = 2; i <= n; i++) {
        vet[i] = vet[i - 1] + vet[i - 2];
    }

    for (int i = 0; i < n; i++) {
        cin >> nv;
        cout << "Fib(" << nv << ") = " << vet[nv] << endl;
    }

    return 0;
}