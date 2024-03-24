#include <iostream>
using namespace std;

int fibonacci_recursive(int);
int fibonacci_iterative(int);

int main() {
    
    int n;
    
    cin >> n;
    
    cout << fibonacci_iterative(n) << endl;
    
    return 0;
    
}

int fibonacci_recursive(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    int sum;
    int prev2 = 0;
    int prev1 = 1;
    for(int i=0; i<n-2; i++) {
        sum = prev1 + prev2;
        prev2 = prev1;
        prev1 = sum;
    }
    return sum;
}