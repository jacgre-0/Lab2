#include <iostream>
#include <time.h>
#include "lab2lib.h"

void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();

int main() {
    srand(time(0));
    int choice{};

    while (true) {
        std::cout << "MENU: " << "\n"
            << "1: Task 1\n"
            << "2: Task 2\n"
            << "3: Task 3\n"
            << "4: Task 4\n"
            << "5: Task 5\n"
            << "6: Task 6\n"
            << "-1: Exit"
            << "Make your choice: ";
        std::cin >> choice;

        switch (choice) {
        case -1:
            return 0;
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        default:
            std::cout << "Sorry, there is no such task!" << std::endl;
            break;
        }
    }
    return 0;
}

void Task1() {
    constexpr int SIZE = 7;
    int array[SIZE]{};

    for (size_t i = 0; i < SIZE; i++) {
        std::cout << "Input a number: ";
        std::cin >> array[i];
    }

    std::cout << "Is sorted: " << std::boolalpha << is_sorted(array, SIZE) << "\n" << std::endl;
}

void Task2() {
    char str[100];
    std::cout << "Input a string: ";
    std::cin.ignore();
    std::cin.get(str, 100);

    std::cout << "Is palindrome: " << std::boolalpha << is_palindrome(str) << "\n" << std::endl;;
}

void Task3() {
    int xRows{};
    int yColumns{};

    std::cout << "Number of rows: ";
    std::cin >> xRows;

    std::cout << "Number of columns: ";
    std::cin >> yColumns;

    std::cout << std::endl;

    int** array = new int* [xRows];

    for (int i = 0; i < xRows; i++) {
        array[i] = new int[yColumns];
    }

    for (int i = 0; i < xRows; i++) {
        for (int j = 0; j < yColumns; j++) {
            int randomValue = rand() % 10;
            array[i][j] = randomValue;
        }
    }

    array_rows_cols(array, xRows, yColumns);

    for (int i = 0; i < xRows; i++) {
        delete[] array[i];
    }
    delete[] array;

    std::cout << "\n" << std::endl;
}

void Task4() {
    int a{};
    int b{};
    int c{};
    bool sortOrder{};

    std::cout << "Give a (0 to quit): ";
    std::cin >> a;
    if (a == 0) {
        std::cout << "Bye bye!";
        return;
    }

    std::cout << "Give b: ";
    std::cin >> b;

    std::cout << "Give c: ";
    std::cin >> c;

    std::cout << "Sort ascending/descending (1/0): ";
    std::cin >> sortOrder;

    swap_sort(a, b, c, sortOrder);

    std::cout << "Result: " << a << ", " << b << ", " << c << "\n" << std::endl;
}

void Task5() {
    int array[] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };
    auto size = std::size(array);

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

    std::cout << "\n\n";
}

void Task6() {
    int choice{};

    while (true) {
        std::cout << "\nMENU: " << "\n"
            << "1. initialise database\n"
            << "2. insert\n"
            << "3. search\n"
            << "4. delete\n"
            << "5. print\n"
            << "6. quit\n"
            << "Make your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            initialise_database();
            break;
        case 2:
            insert();
            std::cout << std::endl;
            break;
        case 3:
            search();
            std::cout << std::endl;
            break;
        case 4:
            delete_user();
            std::cout << std::endl;
            break;
        case 5:
            print();
            std::cout << std::endl;
            break;
        case 6:
            return;
        default:
            std::cout << "Error! only numbers between 1 and 6 is allowed." << std::endl;
            break;
        }
    }
}
