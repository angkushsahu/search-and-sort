#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

void selection_sort(std::vector<int> &arr, const unsigned int& size) {
    for (unsigned int i = 0; i < size - 1; i ++) {
        int smallest_val_iter = i;

        for (int j = i + 1; j < size; j ++)
            if (arr[j] < arr[smallest_val_iter])
                smallest_val_iter = j;

        if (i != smallest_val_iter) swap(arr[i], arr[smallest_val_iter]);
    }
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    selection_sort(arr, size);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
