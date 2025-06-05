// Email: shanig7531@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <string>
#include <stdexcept>

using namespace Container;

TEST_CASE("Ascending Order Iterator") {
    SUBCASE("Integer Type") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {1, 2, 6, 7, 15};
        std::vector<int> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {1.5, 3.5, 7.5};
        std::vector<double> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Type") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        
        std::vector<std::string> expected = {"apple", "banana", "cherry"};
        std::vector<std::string> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_asc() == container.end_asc());
        CHECK_THROWS_AS(*container.begin_asc(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_asc();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_asc());
    }

    SUBCASE("Iterator Bounds") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_asc();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Duplicate Elements") {
        MyContainer<int> container;
        container.add(5);
        container.add(5);
        container.add(3);
        
        std::vector<int> expected = {3, 5, 5};
        std::vector<int> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Large Numbers") {
        MyContainer<long> container;
        container.add(1000000000L);
        container.add(2000000000L);
        container.add(1500000000L);
        
        std::vector<long> expected = {1000000000L, 1500000000L, 2000000000L};
        std::vector<long> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Negative Numbers") {
        MyContainer<int> container;
        container.add(-1);
        container.add(-5);
        container.add(-3);
        
        std::vector<int> expected = {-5, -3, -1};
        std::vector<int> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Descending Order Iterator Tests") {
    SUBCASE("Integer Descending") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {15, 7, 6, 2, 1};
        std::vector<int> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Descending") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        container.add(9.5);

        std::vector<double> expected = {9.5, 7.5, 3.5, 1.5};
        std::vector<double> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Descending") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        container.add("date");

        std::vector<std::string> expected = {"date", "cherry", "banana", "apple"};
        std::vector<std::string> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_desc() == container.end_desc());
        CHECK_THROWS_AS(*container.begin_desc(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        
        std::vector<int> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 1);
        CHECK(result[0] == 42);
    }

    SUBCASE("Iterator Bounds Check") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_desc();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Duplicate Elements") {
        MyContainer<int> container;
        container.add(5);
        container.add(5);
        container.add(3);
        container.add(3);
        container.add(1);

        std::vector<int> expected = {5, 5, 3, 3, 1};
        std::vector<int> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Large Numbers") {
        MyContainer<long> container;
        container.add(1000000000L);
        container.add(2000000000L);
        container.add(3000000000L);

        std::vector<long> expected = {3000000000L, 2000000000L, 1000000000L};
        std::vector<long> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Negative Numbers") {
        MyContainer<int> container;
        container.add(-1);
        container.add(-5);
        container.add(-3);
        container.add(-2);

        std::vector<int> expected = {-1, -2, -3, -5};
        std::vector<int> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("SideCross Order Iterator Tests") {
    SUBCASE("Integer Type") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {1, 15, 2, 7, 6};
        std::vector<int> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {1.5, 7.5, 3.5};
        std::vector<double> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Type") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        container.add("date");
        
        std::vector<std::string> expected = {"apple", "date", "banana", "cherry"};
        std::vector<std::string> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_sidecross() == container.end_sidecross());
        CHECK_THROWS_AS(*container.begin_sidecross(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        
        std::vector<int> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 1);
        CHECK(result[0] == 42);
    }

    SUBCASE("Iterator Bounds Check") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_sidecross();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Duplicate Elements") {
        MyContainer<int> container;
        container.add(5);
        container.add(5);
        container.add(3);
        container.add(3);
        
        std::vector<int> expected = {3, 5, 3, 5};
        std::vector<int> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Large Numbers") {
        MyContainer<long> container;
        container.add(1000000000L);
        container.add(2000000000L);
        container.add(3000000000L);
        
        std::vector<long> expected = {1000000000L, 3000000000L, 2000000000L};
        std::vector<long> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Regular Order Iterator Tests") {
    SUBCASE("Integer Type") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {7, 15, 6, 1, 2}; // Same order as insertion
        std::vector<int> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {7.5, 1.5, 3.5}; // Same order as insertion
        std::vector<double> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Type") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        
        std::vector<std::string> expected = {"banana", "apple", "cherry"}; // Same order as insertion
        std::vector<std::string> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_order() == container.end_order());
        CHECK_THROWS_AS(*container.begin_order(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        
        std::vector<int> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 1);
        CHECK(result[0] == 42);
    }

    SUBCASE("Iterator Bounds Check") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_order();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Duplicate Elements") {
        MyContainer<int> container;
        container.add(5);
        container.add(5);
        container.add(3);
        
        std::vector<int> expected = {5, 5, 3}; // Same order as insertion
        std::vector<int> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Large Numbers") {
        MyContainer<long> container;
        container.add(1000000000L);
        container.add(2000000000L);
        container.add(3000000000L);
        
        std::vector<long> expected = {1000000000L, 2000000000L, 3000000000L}; // Same order as insertion
        std::vector<long> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Negative Numbers") {
        MyContainer<int> container;
        container.add(-1);
        container.add(-5);
        container.add(-3);
        
        std::vector<int> expected = {-1, -5, -3}; // Same order as insertion
        std::vector<int> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Reverse Order Iterator Tests") {
    SUBCASE("Integer Type") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {2, 1, 6, 15, 7};  // Reverse of insertion order
        std::vector<int> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {3.5, 1.5, 7.5};  // Reverse of insertion order
        std::vector<double> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Type") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        
        std::vector<std::string> expected = {"cherry", "apple", "banana"};  // Reverse of insertion order
        std::vector<std::string> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_reverse() == container.end_reverse());
        CHECK_THROWS_AS(*container.begin_reverse(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        
        std::vector<int> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 1);
        CHECK(result[0] == 42);
    }

    SUBCASE("Iterator Bounds Check") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_reverse();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Duplicate Elements") {
        MyContainer<int> container;
        container.add(5);
        container.add(5);
        container.add(3);
        
        std::vector<int> expected = {3, 5, 5};  // Reverse of insertion order
        std::vector<int> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Large Numbers") {
        MyContainer<long> container;
        container.add(1000000000L);
        container.add(2000000000L);
        container.add(3000000000L);
        
        std::vector<long> expected = {3000000000L, 2000000000L, 1000000000L};
        std::vector<long> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Middle Out Order Iterator Tests") {
    SUBCASE("Integer Type") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);

        std::vector<int> expected = {6, 15, 1, 7, 2};  // Middle-out order
        std::vector<int> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Double Type") {
        MyContainer<double> container;
        container.add(7.5);
        container.add(1.5);
        container.add(3.5);
        
        std::vector<double> expected = {1.5, 7.5, 3.5}; 
        std::vector<double> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("String Type") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        container.add("date");
        
        // For 4 elements: middle-left element first (apple), then middle-right (cherry),
        // then leftmost (banana), then rightmost (date)
        std::vector<std::string> expected = {"cherry", "apple", "date", "banana"};  // Changed order
        std::vector<std::string> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }

    SUBCASE("Empty Container") {
        MyContainer<int> container;
        CHECK(container.begin_middleout() == container.end_middleout());
        CHECK_THROWS_AS(*container.begin_middleout(), std::out_of_range);
    }

    SUBCASE("Single Element") {
        MyContainer<int> container;
        container.add(42);
        
        std::vector<int> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 1);
        CHECK(result[0] == 42);
    }

    SUBCASE("Even Number of Elements") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        
        std::vector<int> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result.size() == 4);
        // Split the OR condition into two separate checks
        bool isValidFirst = (result[0] == 2 || result[0] == 3);
        CHECK(isValidFirst);
    }

    SUBCASE("Iterator Bounds Check") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        
        auto it = container.begin_middleout();
        ++it;
        ++it; // Move to end
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }
}

TEST_CASE("Error Handling and Edge Cases") {
    SUBCASE("Container Operations Errors") {
        MyContainer<int> container;
        
        // Empty container operations
        CHECK_THROWS_AS(container.remove(5), std::runtime_error);
        CHECK_THROWS_WITH(container.remove(5), "Element not found in container");
        
        // Non-existent element
        container.add(1);
        container.add(2);
        CHECK_THROWS_AS(container.remove(3), std::runtime_error);
        CHECK_THROWS_WITH(container.remove(3), "Element not found in container");
    }

    SUBCASE("Iterator Out of Bounds - Ascending") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_asc(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_asc(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_asc();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Iterator Out of Bounds - Descending") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_desc(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_desc(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_desc();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Iterator Out of Bounds - SideCross") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_sidecross(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_sidecross(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_sidecross();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Iterator Out of Bounds - Reverse") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_reverse(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_reverse(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_reverse();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Iterator Out of Bounds - Regular Order") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_order(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_order(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_order();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Iterator Out of Bounds - Middle Out") {
        MyContainer<int> container;
        
        // Empty container
        CHECK_THROWS_AS(*container.begin_middleout(), std::out_of_range);
        CHECK_THROWS_WITH(*container.begin_middleout(), "Iterator out of bounds");
        
        // Moving past end
        container.add(1);
        auto it = container.begin_middleout();
        ++it;
        CHECK_THROWS_AS(*it, std::out_of_range);
        CHECK_THROWS_AS(++it, std::out_of_range);
    }

    SUBCASE("Multiple Operations Error Chain") {
        MyContainer<int> container;
        
        // Add and remove sequence
        container.add(1);
        container.add(1);
        container.remove(1); // Should remove both 1s
        CHECK_THROWS_AS(container.remove(1), std::runtime_error);
        
        // Iterator operations after container is emptied
        CHECK_THROWS_AS(*container.begin_asc(), std::out_of_range);
        CHECK_THROWS_AS(*container.begin_desc(), std::out_of_range);
        CHECK_THROWS_AS(*container.begin_sidecross(), std::out_of_range);
        CHECK_THROWS_AS(*container.begin_reverse(), std::out_of_range);
        CHECK_THROWS_AS(*container.begin_order(), std::out_of_range);
        CHECK_THROWS_AS(*container.begin_middleout(), std::out_of_range);
    }

    SUBCASE("Iterator Operations with Different Types") {
        // Test with string
        MyContainer<std::string> strContainer;
        CHECK_THROWS_AS(*strContainer.begin_asc(), std::out_of_range);
        
        // Test with double
        MyContainer<double> doubleContainer;
        CHECK_THROWS_AS(*doubleContainer.begin_desc(), std::out_of_range);
        
        // Test with long
        MyContainer<long> longContainer;
        CHECK_THROWS_AS(*longContainer.begin_middleout(), std::out_of_range);
    }
}