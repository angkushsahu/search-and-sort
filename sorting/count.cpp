#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void count_sort(vector<int> &arr) {
    int size = arr.size();
    int max_ele = *max_element(arr.begin(), arr.end());
    vector<int> count(max_ele + 1, 0);
    for (int i : arr) { count[i] ++; }
    for (int i = 1; i < max_ele + 1; i ++) { count[i] += count[i - 1]; }
    vector<int> temp(size);
    for (int i = size - 1; i >= 0; i --) {
        count[arr[i]] --;
        temp[count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i ++) { arr[i] = temp[i]; }
}

void display_array(vector<int> arr) {
    for (int i : arr) { cout << i << " "; }
    cout << endl;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    count_sort(arr);
    display_array(arr);

    return 0;
}
