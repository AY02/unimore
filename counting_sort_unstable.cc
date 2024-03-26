#include <iostream>
using namespace std;

void counting_sort(int [], const int, int);

int main() {

    int arr[10] = {5, 8, 3, 0, 8, 10, 7, 7, 3, 2};

    int k = 10;

    counting_sort(arr, 10, k);

    for(int i=0; i<10; i++)
        cout << arr[i] << endl;

    return 0;
}

void counting_sort(int arr[], const int N, int k) {
    int tmp[k+1];
    for(int i=0; i<k+1; i++)
        tmp[i] = 0;
    for(int i=0; i<N; i++)
        tmp[arr[i]]++;
    int i = 0;
    for(int j=0; j<k+1; j++) {
        while(tmp[j] > 0) {
            arr[i] = j;
            i++;
            tmp[j]--;
        }
    }
}