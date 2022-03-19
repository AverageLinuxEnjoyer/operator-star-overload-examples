#include <iostream>

#include "../include/vector.hpp"
#include "../include/iterator.hpp"
#include "../include/unique_pointer.hpp"
#include "../include/shared_pointer.hpp"

int main() {
    Vector<int> vector;

    vector.push_back(1);
    vector.push_back(2);

    std::cout << "Iterator for loop: \n";

    for (auto it = vector.begin(); it != vector.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n\nRange based for loop: ";

    vector.pop_back();
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(7);
    vector.push_back(9);

    // functioneaza daca in container e implementat .begin() si .end()
    for (const auto &x : vector) {
        std::cout << x << " ";
    }

    std::cout << "\n\nUnique Pointer test: ";

    UniquePointer<std::string> pointer(new std::string("Hello"));

    std::cout << *pointer << std::endl;
    std::cout << pointer->size() << std::endl;

    std::cout << "\n\nShared Pointer test: ";

    SharedPointer<std::string> pointer2(new std::string("Hello"));
    std::cout << pointer2.getCount() << std::endl;

    SharedPointer<std::string> pointer3(pointer2);
    std::cout << pointer3.getCount() << std::endl;
}