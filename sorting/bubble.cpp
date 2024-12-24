#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(std::vector<int> &arr, const unsigned int& size) {
    for (unsigned int i = 0; i < size - 1; i ++) {
        bool check_if_sorted = true;

        for (unsigned int j = 0; j < size - i - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                check_if_sorted = false;
            }
        }

        if (check_if_sorted) return;
    }
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    bubble_sort(arr, size);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
