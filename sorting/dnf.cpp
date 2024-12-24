#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

void dnf_sort(std::vector<int> &arr, const unsigned int& size) {
    unsigned int low = 0, mid = 0;
    int high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) swap(arr[mid ++], arr[low ++]);
        else if (arr[mid] == 1) mid ++;
        else swap(arr[mid], arr[high --]);
    }
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    dnf_sort(arr, size);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
