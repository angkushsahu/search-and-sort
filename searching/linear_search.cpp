#include <iostream>
#include <vector>

int linear_search(const std::vector<int>& arr, const unsigned int& size, const int& element) {
    for (unsigned int i = 0; i < size; i ++)
        if (arr[i] == element)
            return i;

    return -1;
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int& array_element: arr) std::cin >> array_element;
    int element; std::cin >> element;

    const int index = linear_search(arr, size, element);
    if (index == -1) std::cout << element << " is not present in the given array" << std::endl;
    else std::cout << element << " is present at " << index << " index" << std::endl;

    return 0;
}
