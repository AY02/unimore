#include <iostream>
using namespace std;

void swap(int &, int &);
void quick_sort(int [], int, int);
int partition(int [], int, int);

int main() {

    int arr[7] = {3, 1, 2, 7, 6, 5, 4};

    quick_sort(arr, 0, 7-1);

    for(int i=0; i<7; i++)
        cout << arr[i] << endl;

    return 0;

}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void quick_sort(int arr[], int p, int r) {
    if(p >= r)
        return;
    int q = partition(arr, p, r);
    quick_sort(arr, p, q-1);
    quick_sort(arr, q+1, r);
}

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[r], arr[i+1]);
    return i+1;
}