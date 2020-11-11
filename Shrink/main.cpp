#include <iostream>

void shrink_array(int arr[], int size);

int main() {
    int array[] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };
    auto size   = std::size(array);

    std::cout << "Input array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;

    shrink_array(array, size);
    
    std::cout << "Output array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ", ";
    }
    return 0;
}

void shrink_array(int arr[], int size) {
    int j{};
    int sum{};

    int half = std::ceil(size / 2.0f);

    for (int i = 0, j = 0; j < size; i++, j += 2) {
        sum = arr[j] + arr[j + 1];
        arr[i] = sum;
    }

    if (size % 2 != 0) {
        arr[half - 1] = arr[size - 1];
    }

    //Zero out the leftovers
    for (int i = half; i < size; i++) {
        arr[i] = 0;
    }
}