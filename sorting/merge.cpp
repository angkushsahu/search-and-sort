#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, const unsigned int& start, const unsigned int& mid, const unsigned int& end) {
    unsigned int start_arr_size = mid - start + 1;
    unsigned int end_arr_size = end - mid;
    std::vector<int> start_arr(start_arr_size), end_arr(end_arr_size);

    for (unsigned int i = 0; i < start_arr_size; i ++) start_arr[i] = arr[start + i];
    for (unsigned int j = 0; j < end_arr_size; j ++) end_arr[j] = arr[mid + 1 + j];

    unsigned int i = 0, j = 0, k = start;
    while (i < start_arr_size && j < end_arr_size) {
        if (start_arr[i] <= end_arr[j]) arr[k++] = start_arr[i++];
         else arr[k++] = end_arr[j++];
    }

    while (i < start_arr_size) arr[k++] = start_arr[i++];
    while (j < end_arr_size) arr[k++] = end_arr[j++];
}

void merge_sort(std::vector<int> &arr, const unsigned int& start, const unsigned int& end) {
    if (start >= end) return;

    const int mid = start + ((end - start) >> 1);
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    merge_sort(arr, 0, size - 1);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
