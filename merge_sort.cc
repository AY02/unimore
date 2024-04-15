#include <iostream>
using namespace std;

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

int main() {

    int arr[8] = {33, 21, 7, 48, 28, 13, 65, 17};

    merge_sort(arr, 0, 8-1);

    for(int i=0; i<8; i++)
        cout << arr[i] << endl;

    return 0;
}

void merge_sort(int arr[], int i, int j) {
    if(i >= j)
        return;
    int k = (i + j) / 2;
    merge_sort(arr, i, k);
    merge_sort(arr, k+1, j);
    merge(arr, i, k, j);
}

void merge(int arr[], int i, int k, int j) {
    int l = i;
    int r = k + 1;
    int t = 0;
    int tmp[j-i+1];
    while(l<=k && r<=j) {
        if(arr[l] <= arr[r]) {
            tmp[t] = arr[l];
            l++;
        }
        else {
            tmp[t] = arr[r];
            r++;
        }
        t++;
    }
    for(int z=k; z>=l; z--) {
        arr[j] = arr[z];
        j--;
    }
    for(int z=0; z<t; z++)
        arr[i+z] = tmp[z];
}