#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    vector<int> temp(high + 1);

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) { temp[k ++] = arr[i ++]; }
        else { temp[k ++] = arr[j ++]; }
    }

    while (i <= mid) { temp[k ++] = arr[i ++]; }
    while (j <= high) { temp[k ++] = arr[j ++]; }

    for (int x = low; x <= high; x ++) {
        arr[x] = temp[x];
    }
}

void merge_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void display_array(vector<int> arr) {
    for (int i : arr) { cout << i << " "; }
    cout << endl;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    merge_sort(arr, 0, size - 1);
    display_array(arr);

    return 0;
}
