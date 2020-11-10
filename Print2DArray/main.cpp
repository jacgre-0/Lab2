#include <iostream>
#include <time.h>

void array_rows_cols(int** arr, int rows, int cols);

int main() {
    srand(time(0));
    int xRows{};
    int yColumns{};

    std::cout << "Number of rows: ";
    std::cin >> xRows;

    std::cout << "Number of columns: ";
    std::cin >> yColumns;

    std::cout << std::endl;

    int** array = new int*[xRows];

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

    return 0;
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