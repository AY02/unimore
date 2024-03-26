#include <iostream>
using namespace std;

void counting_sort(int [], const int, int);

int main() {

    const int N = 10;
    int arr[N] = {5, 8, 3, 0, 8, 10, 7, 7, 3, 2};
    int k = 10;

    counting_sort(arr, N, k);

    for(int i=0; i<N; i++)
        cout << arr[i] << endl;

    return 0;

}

void counting_sort(int arr[], const int N, int k) {
    int C[k+1], B[N];
    for(int i=0; i<=k; i++)
        C[i] = 0;
    for(int i=0; i<N; i++)
        C[arr[i]]++;
    for(int i=1; i<=k; i++)
        C[i] += C[i-1];
    for(int i=N-1; i>=0; i--) {
        B[C[arr[i]] - 1] = arr[i];
        C[arr[i]]--;
    }
    for(int i=0; i<N; i++)
        arr[i] = B[i];
}