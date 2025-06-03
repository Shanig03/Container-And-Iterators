// Email: shanig7531@gmail.com

#include "MyContainer.hpp"
#include <iostream>
using namespace Container;

int main() {
    // Create a container for integers (default)
    MyContainer<> intContainer;

    // Add elements
    intContainer.add(5);
    intContainer.add(2);
    intContainer.add(7);
    intContainer.add(2);
    intContainer.add(10);

    // Print container
    std::cout << "intContainer: " << intContainer << std::endl;

    // Remove element (removes all occurrences of 2)
    intContainer.remove(2);

    // Print after removal
    std::cout << "After removing 2: " << intContainer << std::endl;

    // Print size
    std::cout << "Size: " << intContainer.size() << std::endl;

    // Create a container for strings
    MyContainer<std::string> strContainer;
    strContainer.add("hello");
    strContainer.add("world");
    strContainer.add("apple");
    strContainer.add("banana");
    std::cout << "strContainer: " << strContainer << std::endl;

    // Print container in descending order using the iterator
    std::cout << "strContainer in descending order: ";
    for (auto it = strContainer.begin_desc(); it != strContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "strContainer in ascending order: ";
    for (auto it = strContainer.begin_asc(); it != strContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    strContainer.remove("world");
    std::cout << "strContainer: " << strContainer << std::endl;

    try{
        strContainer.remove("Hi");
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    MyContainer<double> doubleContainer;

    // Add elements
    doubleContainer.add(5.5);
    doubleContainer.add(2.3);
    doubleContainer.add(7.7);
    doubleContainer.add(2.2);

    // Print container
    std::cout << "doubleContainer: " << doubleContainer << std::endl;

    // Remove element (removes all occurrences of 2.2)
    doubleContainer.remove(2.2);

    // Print after removal
    std::cout << "After removing 2.2: " << doubleContainer << std::endl;

    // Print size
    std::cout << "Size: " << doubleContainer.size() << std::endl;

    // Print container in ascending order using the iterator
    std::cout << "intContainer in ascending order: ";
    for (auto it = intContainer.begin_asc(); it != intContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example for doubleContainer as well
    std::cout << "doubleContainer in ascending order: ";
    for (auto it = doubleContainer.begin_asc(); it != doubleContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in descending order using the iterator
    std::cout << "intContainer in descending order: ";
    for (auto it = intContainer.begin_desc(); it != intContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example for doubleContainer as well
    std::cout << "doubleContainer in descending order: ";
    for (auto it = doubleContainer.begin_desc(); it != doubleContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in side-cross order using the iterator
    std::cout << "intContainer in side-cross order: ";
    for (auto it = intContainer.begin_sidecross(); it != intContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example for doubleContainer as well
    std::cout << "doubleContainer in side-cross order: ";
    for (auto it = doubleContainer.begin_sidecross(); it != doubleContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example for strContainer as well
    std::cout << "strContainer in side-cross order: ";
    for (auto it = strContainer.begin_sidecross(); it != strContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "intContainer in reverse order: ";
    for (auto it = intContainer.begin_reverse(); it != intContainer.end_reverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "strContainer in reverse order: ";
    for (auto it = strContainer.begin_reverse(); it != strContainer.end_reverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "intContainer in insertion order: ";
    for (auto it = intContainer.begin_order(); it != intContainer.end_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "strContainer in insertion order: ";
    for (auto it = strContainer.begin_order(); it != strContainer.end_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "intContainer in middle-out order: ";
    for (auto it = intContainer.begin_middleout(); it != intContainer.end_middleout(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "strContainer in middle-out order: ";
    for (auto it = strContainer.begin_middleout(); it != strContainer.end_middleout(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}