#include <iostream>
using namespace std;

void insertion_sort(int [], const int);

int main() {

    int arr[16] = {1, -1, 2, -2, 3, -3, 4, -4, 10, 5, -3, -2, 1, 0, 0, -5};

    insertion_sort(arr, 16);

    for(int i=0; i<16; i++)
        cout << arr[i] << endl;

    return 0;

}

void insertion_sort(int arr[], const int N) {
    for(int i=1; i<N; i++) {
        int j = i - 1;
        int tmp = arr[i];
        while(j>=0 && arr[j]>tmp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}