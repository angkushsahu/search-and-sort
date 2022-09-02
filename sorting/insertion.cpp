#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(vector<int> &arr) {
    int size = arr.size();
    for (int i = 1; i < size; i ++) {
        int i_value = arr[i];
        int j = i - 1;
        while (i_value < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = i_value;
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

    insertion_sort(arr);
    display_array(arr);

    return 0;
}
