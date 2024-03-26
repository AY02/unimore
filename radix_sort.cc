#include <iostream>
using namespace std;

void counting_sort(int [], const int, int);
void radix_sort(int [], const int, int, int);

int main() {

    const int N = 8;
    int arr[N] = {329, 457, 657, 8999, 839, 436, 720, 355};
    int k = 9; //Maximum number that a digit can take on
    int d = 4; //d = log2(max(arr, N));

    radix_sort(arr, N, k, d);

    for(int i=0; i<N; i++)
        cout << arr[i] << endl;

    return 0;

}

void counting_sort(int arr[], const int N, int k, int i) {
    int exp = 1;
    for(int j=0; j<i; j++)
        exp *= 10;
    int C[k+1], B[N];
    for(int j=0; j<=k; j++)
        C[j] = 0;
    for(int j=0; j<N; j++)
        C[(arr[j] / exp) % 10]++;
    for(int j=1; j<=k; j++)
        C[j] += C[j-1];
    for(int j=N-1; j>=0; j--) {
        B[C[(arr[j] / exp) % 10] - 1] = arr[j];
        C[(arr[j] / exp) % 10]--;
    }
    for(int i=0; i<N; i++)
        arr[i] = B[i];
}

void radix_sort(int arr[], const int N, int k, int d) {
    for(int i=0; i<d; i++)
        counting_sort(arr, N, k, i);
}