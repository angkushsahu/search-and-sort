#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, const unsigned int& size, const int& element) {
    unsigned int start = 0, end = size - 1;

    while (start <= end) {
        const unsigned int mid = start + ((end - start) >> 1);
        if (arr[mid] == element) return mid;
        else if (arr[mid] < element) start = mid + 1;
        else {
            if (mid == 0) return -1;
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int& array_element: arr) std::cin >> array_element;
    int element; std::cin >> element;

    const int index = binary_search(arr, size, element);
    if (index == -1) std::cout << element << " is not present in the given array" << std::endl;
    else std::cout << element << " is present at " << index << " index" << std::endl;

    return 0;
}
