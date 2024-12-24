#include <iostream>
#include <climits>
#include <vector>

void count_sort(std::vector<int> &arr, const unsigned int& size) {
    int min_value = INT_MAX, max_value = INT_MIN;
    for (const int& element: arr) {
        min_value = std::min(min_value, element);
        max_value = std::max(max_value, element);
    }

    int shift = -min_value;
    int range = max_value - min_value + 1;

    std::vector<int> frequency(range, 0);
    for (const int& num : arr) frequency[num + shift] ++;
    for (unsigned int i = 1; i < range; i ++) frequency[i] += frequency[i - 1];

    std::vector<int> output_array(size);
    for (int i = size - 1; i >= 0; i --) {
        output_array[frequency[arr[i] + shift] - 1] = arr[i];
        frequency[arr[i] + shift] --;
    }

    arr = output_array;
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    count_sort(arr, size);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
