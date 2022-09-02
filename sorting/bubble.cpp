#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i ++) {
        int check_if_sorted = true;
        for (int j = 0; j < size - i - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                check_if_sorted = false;
            }
        }
        if (check_if_sorted) { return; }
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

    bubble_sort(arr);
    display_array(arr);

    return 0;
}
