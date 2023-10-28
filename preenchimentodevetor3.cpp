#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    double X;
    double N[100];
    cin >> X;

    N[0] = X;
    cout << "N[0] = " << fixed << setprecision(4) << N[0] << endl;
    
    for (int i = 1; i <= 99; i++) {
        N[i] = N[i - 1] / 2.0;
        cout << "N[" << i << "] = " << fixed << setprecision(4) << N[i] << endl;
    }

    return 0;
}