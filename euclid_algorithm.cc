#include <iostream>
using namespace std;

int euclid_algorithm(int a, int b) {
    if(b == 0)
        return a;
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int euclid_algorithm_rec(int a, int b) {
    if(b == 0)
        return a;
    return euclid_algorithm_rec(b, a % b);
}

int main() {
    
    int a, b;
    
    while(true) {
        cin >> a >> b;
        cout << "Result: " << euclid_algorithm_rec(a, b) << endl;
    }
    
    return 0;
}
