#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int> &arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i ++) {
        int smallest_val_iter = i;
        for (int j = i + 1; j < size; j ++) {
            if (arr[j] < arr[smallest_val_iter]) { smallest_val_iter = j; }
        }
        if (i != smallest_val_iter) { swap(arr[i], arr[smallest_val_iter]); }
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

    selection_sort(arr);
    display_array(arr);

    return 0;
}
