#include <iostream>
using namespace std;

const int NOT_FOUND = -1;

int binary_search(const int, int[], int, int);

int main() {
    const int N = 10;
    int arr[N];
    for(int i=0; i<N; i++)
        arr[i] = i+1;
    cout << binary_search(5, arr, 0, N-1) << endl;
    return 0;
}

int binary_search(const int KEY, int arr[], int i, int j) {
    if(i > j)
        return NOT_FOUND;
    int mid = (i + j) / 2;
    if(KEY == arr[mid])
        return mid;
    if(KEY > arr[mid])
        return binary_search(KEY, arr, mid+1, j);
    return binary_search(KEY, arr, i, mid-1);
}