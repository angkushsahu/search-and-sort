#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &arr, const int start, const int end) {
    const int pivot = arr[end];
    int i = start - 1;
    for (unsigned int j = start; j < end; j ++) {
        if (arr[j] < pivot) {
            i ++;
            if (i != j) swap(arr[j], arr[i]);
        }
    }

    i ++;
    swap(arr[end], arr[i]);
    return i;
}

void quick_sort(std::vector<int> &arr, int start, int end) {
    while (start < end) {
        const int pivot = partition(arr, start, end);

        if (pivot - start < end - pivot) {
            quick_sort(arr, start, pivot - 1);
            start = pivot + 1;
        } else {
            quick_sort(arr, pivot + 1, end);
            end = pivot - 1;
        }
    }
}

int main() {
    unsigned int size; std::cin >> size;
    std::vector<int> arr(size);
    for (int &array_element : arr) std::cin >> array_element;

    quick_sort(arr, 0, size - 1);
    for (const int &array_element : arr) std::cout << array_element << ' ';
    std::cout << std::endl;

    return 0;
}
