#include <iostream>
using namespace std;

void swap(int &, int &);
int min(int [], const int, int);
void selection_sort(int [], const int, int);

int main() {

    int arr[16] = {1, -1, 2, -2, 3, -3, 4, -4, 10, 5, -3, -2, 1, 0, 0, -5};

    selection_sort(arr, 16, 0);

    for(int i=0; i<16; i++)
        cout << arr[i] << endl;

    return 0;

}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int min(int arr[], const int N, int i) {
    int k = i;
    for(int j=i+1; j<N; j++)
        if(arr[k] > arr[j])
            k = j;
    return k;
}

void selection_sort(int arr[], const int N, int i) {
    if(i == N-2)
        return;
    int k = min(arr, N, i);
    swap(arr[k], arr[i]);
    selection_sort(arr, N, i+1);
}