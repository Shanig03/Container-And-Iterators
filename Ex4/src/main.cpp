// Email: shanig7531@gmail.com

#include "MyContainer.hpp"
#include <iostream>
using namespace Container;

int main() {

    std::cout << "\n===== Integer Container =====" << std::endl;

    // Create a container for integers (default)
    MyContainer<> intContainer;

    // Add elements
    intContainer.add(5);
    intContainer.add(2);
    intContainer.add(7);
    intContainer.add(2);
    intContainer.add(10);

    // Print container
    std::cout << "\nintContainer: " << intContainer << std::endl;

    // Print size
    std::cout << "\nSize: " << intContainer.size() << std::endl;

    std::cout << "\nInteger Container Iterators: " << std::endl;

    // Print container in ascending order using the iterator
    std::cout << "\nintContainer in ascending order: ";
    for (auto it = intContainer.begin_asc(); it != intContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

     // Print container in descending order using the iterator
    std::cout << "\nintContainer in descending order: ";
    for (auto it = intContainer.begin_desc(); it != intContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in side-cross order using the iterator
    std::cout << "\nintContainer in side-cross order: ";
    for (auto it = intContainer.begin_sidecross(); it != intContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in reverse order using the iterator
    std::cout << "\nintContainer in reverse order: ";
    for (auto it = intContainer.begin_reverse(); it != intContainer.end_reverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in insertion order using the iterator
    std::cout << "\nintContainer in insertion order: ";
    for (auto it = intContainer.begin_order(); it != intContainer.end_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print container in middle-out order using the iterator
    std::cout << "\nintContainer in middle-out order: ";
    for (auto it = intContainer.begin_middleout(); it != intContainer.end_middleout(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    // Remove element (removes all occurrences of 2)
    intContainer.remove(2);

    // Print after removal
    std::cout << "\nAfter removing 2: " << intContainer << std::endl;


    // Attempt to remove an element that does not exist
    std::cout << "\nAttempting to remove an element that does not exist (100): ";
    try{
        intContainer.remove(100);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    // ==========================================================

    // Example for string container
    std::cout << "\n===== String Container =====" << std::endl;

    // Create a container for strings
    MyContainer<std::string> strContainer;
        
    // Add elements
    strContainer.add("hello");
    strContainer.add("world");
    strContainer.add("apple");
    strContainer.add("banana");

    std::cout << "\nstrContainer: " << strContainer << std::endl;

    // Size of the container
    std::cout << "\nSize: " << strContainer.size() << std::endl;

    std::cout << "\nString Container Iterators: " << std::endl;

    // Print strContainer in ascending order
    std::cout << "\nstrContainer in descending order: ";
    for (auto it = strContainer.begin_desc(); it != strContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print strContainer in ascending order
    std::cout << "\nstrContainer in ascending order: ";
    for (auto it = strContainer.begin_asc(); it != strContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print strContainer in side-cross order
    std::cout << "\nstrContainer in side-cross order: ";
    for (auto it = strContainer.begin_sidecross(); it != strContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print strContainer in reverse order
    std::cout << "\nstrContainer in reverse order: ";
    for (auto it = strContainer.begin_reverse(); it != strContainer.end_reverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print strContainer in insertion order
    std::cout << "\nstrContainer in insertion order: ";
    for (auto it = strContainer.begin_order(); it != strContainer.end_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print strContainer in middle-out order
    std::cout << "\nstrContainer in middle-out order: ";
    for (auto it = strContainer.begin_middleout(); it != strContainer.end_middleout(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    // Remove element (removes all occurrences of "world")
    strContainer.remove("world");
    std::cout << "\nstrContainer After Removing \"world\": " << strContainer << std::endl;


    // Attempt to remove an element that does not exist
    std::cout << "\nAttempting to remove an element that does not exist (\"Hi\"): ";
    try{
        strContainer.remove("Hi");
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    // ==========================================================

    std::cout << "\n===== Double Container =====" << std::endl;

    // Create a container for doubles
    MyContainer<double> doubleContainer;

    // Add elements
    doubleContainer.add(5.5);
    doubleContainer.add(2.3);
    doubleContainer.add(7.7);
    doubleContainer.add(2.2);

    // Print container
    std::cout << "\ndoubleContainer: " << doubleContainer << std::endl;

    // Print size
    std::cout << "\nSize: " << doubleContainer.size() << std::endl;


    std::cout << "\nDouble Container Iterators: " << std::endl;

    // Print doubleContainer in ascending order
    std::cout << "\ndoubleContainer in ascending order: ";
    for (auto it = doubleContainer.begin_asc(); it != doubleContainer.end_asc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print doubleContainer in descending order
    std::cout << "\ndoubleContainer in descending order: ";
    for (auto it = doubleContainer.begin_desc(); it != doubleContainer.end_desc(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print doubleContainer in side-cross order
    std::cout << "\ndoubleContainer in side-cross order: ";
    for (auto it = doubleContainer.begin_sidecross(); it != doubleContainer.end_sidecross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print doubleContainer in reverse order
    std::cout << "\ndoubleContainer in reverse order: ";
    for (auto it = doubleContainer.begin_reverse(); it != doubleContainer.end_reverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print doubleContainer in insertion order
    std::cout << "\ndoubleContainer in insertion order: ";
    for (auto it = doubleContainer.begin_order(); it != doubleContainer.end_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print doubleContainer in middle-out order
    std::cout << "\ndoubleContainer in middle-out order: ";
    for (auto it = doubleContainer.begin_middleout(); it != doubleContainer.end_middleout(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    // Remove element (removes all occurrences of 2.2)
    doubleContainer.remove(2.2);

    // Print after removal
    std::cout << "\nAfter removing 2.2: " << doubleContainer << std::endl;
    
    // Print size after removal
    std::cout << "\nSize after removal: " << doubleContainer.size() << std::endl;
    
    
    // Attempt to remove an element that does not exist
    std::cout << "\nAttempting to remove an element that does not exist (3.3): ";
    try{
        doubleContainer.remove(3.3);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;


    return 0;
}