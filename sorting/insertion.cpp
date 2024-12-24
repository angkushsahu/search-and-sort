#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(std::vector<int> &arr, const unsigned int& size) {
    for (unsigned int i = 1; i < size; i ++) {
        int i_value = arr[i];
        int j = i - 1;

        while (i_value < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = i_value;
    }
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    insertion_sort(arr, size);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
