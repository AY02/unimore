#include <iostream>
using namespace std;

int extended_euclid_algorithm(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclid_algorithm(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}

int main() {
    
    int a, b;
    int x, y;
    
    while(true) {
        cin >> a >> b;
        cout << "Risultato: " << extended_euclid_algorithm(a, b, x, y) << endl;
        cout << "x = " << x << ", y = " << y << endl;
    }
    
    return 0;
}
