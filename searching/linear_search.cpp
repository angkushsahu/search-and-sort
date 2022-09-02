#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> arr, int element) {
    int size = arr.size();
    for (int i = 0; i < size; i ++) {
        if (arr[i] == element) { return i; }
    }

    return -1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    // the array should be in sorted order

    int element; cin >> element;
    int search_result = linear_search(arr, element);

    if (search_result == -1) {
        cout << "Element is not present in the array" << endl;
    } else {
        cout << "Element present in " << search_result << " index" << endl;
    }

    return 0;
}
