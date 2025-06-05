### Email: shanig7531@gmail.com

# Custom Container with Multiple Iterators

This project implements a custom generic container class with various iteration patterns. The container supports multiple traversal strategies through specialized iterators.
#### Note: 
This project is implemented primarily using header (`.hpp`) files because it extensively uses template classes. Template classes must be fully defined in headers since they need to be available at compile time. This allows the compiler to generate the correct code for each template instantiation with different types (`int`, `double`, `string`, etc.). Unlike regular classes, template code cannot be split between declaration (`.hpp`) and definition (`.cpp`) files due to template instantiation mechanics in C++.

## Overview
The project implements a generic container (`MyContainer<T>`) that can store elements of any comparable type. The main feature is the variety of iteration patterns provided through different iterator classes:

- **Ascending Order**: Elements in ascending order
- **Descending Order**: Elements in descending order
- **Side-Cross Order**: Alternating between smallest and largest elements
- **Regular Order**: Original insertion order
- **Reverse Order**: Reverse of insertion order
- **Middle-Out Order**: Starting from middle, alternating between left and right

## Project Structure
```
Ex4/
├── src/
│   ├── MyContainer.hpp              # Main container implementation
│   ├── AscendingOrderIterator.hpp   # Ascending order iterator
│   ├── DescendingOrderIterator.hpp  # Descending order iterator
│   ├── SideCrossOrderIterator.hpp   # Side-cross order iterator
│   ├── ReverseOrderIterator.hpp     # Reverse order iterator
│   ├── OrderIterator.hpp            # Regular order iterator
│   ├── MiddleOutOrderIterator.hpp   # Middle-out order iterator
│   └── main.cpp                     # Demo program
├── Tests/
│   ├── doctest.h                    # Doctest file
│   └── tests.cpp                    # Comprehensive test suite
├── makefile                         # Build configuration
└── README.md                        
```

## Iterator Types
1. **Ascending Order Iterator**
   - Traverses elements from smallest to largest
   - Example: for [7,15,6,1,2] the order will be [1,2,7,7,15]

2. **Descending Order Iterator**
   - Traverses elements from largest to smallest
   - Example: for [7,15,6,1,2] the order will be [15,7,6,2,1]

3. **Side-Cross Order Iterator**
   - Alternates between smallest and largest elements
   - Example: for [7,15,6,1,2] theorder will be [1,15,2,7,6]

4. **Regular Order Iterator**
   - Traverses in original insertion order
   - Example: If inserted as [3,1,4,2], iterates as [3,1,4,2]

5. **Reverse Order Iterator**
   - Traverses in reverse of insertion order
   - Example: If inserted as [3,1,4,2], iterates as [2,4,1,3]

6. **Middle-Out Order Iterator**
   - Starts from middle, alternates between left and right
   - Example: For [1,2,3,4,5], iterates as [3,2,4,1,5]

## Design Details

### MyContainer Class
- Template class supporting any comparable type
- Exception-safe operations

### Iterator Implementation
- Each iterator maintains its own traversal logic
- Exception handling for out-of-bounds access

### Error Handling
- `std::runtime_error` for operational errors
- `std::out_of_range` for iterator bounds violations
- Detailed error messages for debugging

## Testing
The project uses the [doctest](https://github.com/doctest/doctest) framework for testing. Tests are organized by iterator type and include:

- Basic operations
- Edge cases
- Error handling
- Different data types (int, double, string)
- Boundary conditions

### Test Categories:
1. Basic Container Operations
2. Iterator-specific tests for each type
3. Error handling and edge cases
4. Type support verification
5. Memory management

## Valgrind
Valgrind is used in this project to detect memory leaks, invalid memory access, and other memory-related issues.

## Building and Running

### Makefile
The Makefile provides the following targets:
| Target       | Description                   |
| ------------ | ----------------------------- |
| `make Main`       | Builds the main program  |
| `make test`  | Compiles and runs all tests   |
| `make valgrind`   | Run the main with valgrind for memory leak detection (can be changed to run on the tests) |
| `make clean` | Cleans all compiled files     |

### How To Run
Ensure you're in the project root directory (Ex4) and have `clang++` and `valgrind` installed.

#### Build And Run The Main Program
```bash
make Main
```
#### Test running
```bash
make test
```
#### Memory Testing Using Valgrind
```bash
make valgrind 
```
#### Clean Build Files
```bash
make clean
```




