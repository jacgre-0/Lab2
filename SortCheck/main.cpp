#include <iostream>

bool is_sorted(int array[], int size);

int main() {
    constexpr int SIZE = 7;
    int array[SIZE]{};

    for (size_t i = 0; i < SIZE; i++) {
        std::cout << "Input a number: ";
        std::cin >> array[i];
    }
   
    std::cout << "Is sorted: " << std::boolalpha << is_sorted(array, SIZE);
    return 0;
}

bool is_sorted(int array[], int size) {
    int intitial = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < intitial) {
            return false;
        }
        intitial = array[i];
    }

    return true;
}