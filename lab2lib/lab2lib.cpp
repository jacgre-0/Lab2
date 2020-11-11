#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> g_dataBase;

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

void swap_sort(int& a, int& b, int& c, bool sortOrder) {
    //sort ascending
    {
        bool worstCaseFlag{ false };

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            //If b is greater than c, we need to compare and possibly swap a and b again 
            //(since b is now c and we haven't compared a with c)
            //So we set the flag to true
            worstCaseFlag = true;

            int temp = b;
            b = c;
            c = temp;
        }

        if (worstCaseFlag) {
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
        }
    }

    //sort descending
    //Just reverse the order by swapping a and c
    if (!sortOrder) {
        int temp = a;
        a = c;
        c = temp;
    }
}

void array_rows_cols(int** arr, int rows, int cols) {
    int rowSum{};
    int colSum{};
    int totalRowSum{};
    int totalColSum{};

    for (int i = 0; i < rows; i++) {
        colSum = 0;
        for (int j = 0; j < cols; j++) {
            colSum += arr[i][j];
            std::cout << arr[i][j] << " ";
        }
        totalColSum += colSum;
        std::cout << colSum;
        std::cout << std::endl;
    }

    for (int i = 0; i < cols; i++) {
        rowSum = 0;
        for (int j = 0; j < rows; j++) {
            rowSum += arr[j][i];
        }
        totalRowSum += rowSum;
        std::cout << rowSum << " ";
    }
    std::cout << " " << totalRowSum + totalColSum << std::endl;
}

bool is_palindrome(const char str[]) {
    bool isPalindrome{ true };
    int size = strlen(str);
    int halfSize = std::ceil(size / 2.0f);

    //reverse the string. We only need to reverse half of the string, rounding upwards, that is
    //if the string has 5 characters, we need to check that the first 3 characters is the same as the last 3 reversed.
    for (int i = size - 1, j = 0; j < halfSize; i--, j++) {
        if (str[j] != str[i]) {
            isPalindrome = false;
            break;
        }
    }

    return isPalindrome;
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

void initialise_database() {
    bool initialise{};
    std::cout << "Are you sure? (1/0) ";
    std::cin >> initialise;

    if (initialise) {
        g_dataBase.clear();
    }
}

void insert() {
    std::string input{};

    while (true) {
        std::cout << "Write a name you would like to insert in the database (write Q/q to stop): ";
        std::cin >> input;

        if (input == "Q" || input == "q")
            return;

        g_dataBase.push_back(input);
    }
}

void search() {
    std::string substr{};

    std::cout << "Type the search string: ";
    std::cin >> substr;

    for (const auto& name : g_dataBase) {
        if (name.find(substr) != std::string::npos) {
            std::cout << name << std::endl;
        }
    }
}

void delete_user() {
    std::string personToDelete{};

    std::cout << "Type the person to delete: ";
    std::cin >> personToDelete;

    for (int i = 0; i < g_dataBase.size(); i++) {
        if (g_dataBase.at(i) == personToDelete) {
            g_dataBase.erase(g_dataBase.begin() + i);
        }
    }
}

void print() {
    for (const auto& name : g_dataBase) {
        std::cout << name << std::endl;
    }
}

