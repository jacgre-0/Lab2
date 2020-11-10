#include <iostream>

bool is_palindrome(const char str[]);

int main() {
    char str[100];
    std::cout << "Input a string: ";
    std::cin.get(str, 100);

    std::cout << "Is palindrome: " << std::boolalpha << is_palindrome(str);
    return 0;
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
