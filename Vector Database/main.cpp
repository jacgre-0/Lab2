#include <vector>
#include <iostream>

std::vector<std::string> g_dataBase;

void initialise_database();
void insert();
void search();
void delete_user();
void print();

int main() {
    int choice{};

    while (true) {
        std::cout << "MENU: " << "\n"
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
            return 0;
        default:
            std::cout << "Error! only numbers between 1 and 6 is allowed." << std::endl;
            break;
        }
    }

    return 0;
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
