#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int element) {
    int high = arr.size() - 1, low = 0;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (arr[mid] == element) { return mid; }
        else if (arr[mid] > element) { high = mid - 1; }
        else { low = mid + 1; }
    }

    if (arr[high] == element) { return high; }
    if (arr[low] == element) { return low; }

    return -1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    // the array should be in sorted order

    int element; cin >> element;
    int search_result = binary_search(arr, element);

    if (search_result == -1) {
        cout << "Element is not present in the array" << endl;
    } else {
        cout << "Element present in " << search_result << " index" << endl;
    }

    return 0;
}
