#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void dnf_sort(vector<int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) { swap(arr[mid ++], arr[low ++]); }
        else if (arr[mid] == 1) { mid ++; }
        else { swap(arr[mid], arr[high --]); }
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

    dnf_sort(arr);
    display_array(arr);

    return 0;
}
