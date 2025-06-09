// Email: shanig7531@gmail.com

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"

namespace Container{

    /**
     * @brief Template class for a generic container that holds comparable elements.
     * 
     * @details
     * Provides basic operations like add, remove, and size.
     * All implementations are in this header file because this is a template class.
     * In C++, template implementations must be in the header file so the compiler can generate code for each type.
     * 
     * @tparam T The type of elements stored in the container. Default is int.
     */
    template<typename T = int> 
    class MyContainer{

    private:
        std::vector<T> data;// Internal storage for the container elements
    public:
        /**
         * @brief Default constructor.
         */
        MyContainer() = default;

        /**
         * @brief Default destructor.
         */
        ~MyContainer()= default;
        
        /**
         * @brief Copy constructor. Defaulted since vector handles it.
         * @param other The container to copy from.
         */
        MyContainer(const MyContainer&) = default;

        /**
         * @brief Copy assignment operator. Defaulted since vector handles it.
         * @param other The container to assign from.
         * @return Reference to this container.
         */
        MyContainer& operator=(const MyContainer&) = default;

        /**
         * @brief Adds a new element to the container.
         * @param value The value to add.
         */
        void add(const T& value) {
            data.push_back(value);
        }

        /**
         * @brief Removes all occurrences of the given value from the container.
         * @param value The value to remove.
         * @throw std::runtime_error If the value is not found in the container.
         */
        void remove(const T& value) {
            auto it = std::remove(data.begin(), data.end(), value);
            if (it == data.end()) {
                throw std::runtime_error("Element not found in container");
            }
            data.erase(it, data.end());
        }

        /**
         * @brief Returns the number of elements in the container.
         * @return The size of the container.
         */
        size_t size() const {
            return data.size();
        }

        /**
         * @brief Output operator to print the container in a readable format.
         * @param os The output stream.
         * @param container The container to print.
         * @return Reference to the output stream.
         */        
        friend std::ostream& operator<<(std::ostream& os, const MyContainer& container) {
            os << "[";
            for (size_t i = 0; i < container.data.size(); ++i) {
                os << container.data[i];
                if (i != container.data.size() - 1) os << ", ";
            }
            os << "]";
            return os;
        }

        friend class AscendingOrderIterator<T>;
        friend class DescendingOrderIterator<T>;
        friend class SideCrossOrderIterator<T>;
        friend class ReverseOrderIterator<T>;
        friend class OrderIterator<T>;
        friend class MiddleOutOrderIterator<T>;

        // Iterator accessors
        /**
         * @brief Returns an iterator to the beginning of the container in ascending order.
         * @return An iterator to the beginning of the container.
         */
        auto begin_asc() const { 
            return AscendingOrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in ascending order.
         * @return An iterator to the end of the container.
         */
        auto end_asc() const { 
            return AscendingOrderIterator<T>(*this, data.size()); 
        }

        /**
         * @brief Returns an iterator to the beginning of the container in descending order.
         * @return An iterator to the beginning of the container.
         */
        auto begin_desc() const { 
            return DescendingOrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in descending order.
         * @return An iterator to the end of the container.
         */
        auto end_desc() const { 
            return DescendingOrderIterator<T>(*this, data.size()); 
        }

        /**
         * @brief Returns an iterator to traverse the container in side-cross order.
         * @return An iterator for side-cross order traversal.
         */
        auto begin_sidecross() const { 
            return SideCrossOrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in side-cross order.
         * @return An iterator to the end of the container.
         */
        auto end_sidecross() const { 
            return SideCrossOrderIterator<T>(*this, data.size()); 
        }

        /**
         * @brief Returns an iterator to the beginning of the container in reverse order.
         * @return An iterator to the beginning of the container in reverse order.
         */
        auto begin_reverse() const { 
            return ReverseOrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in reverse order.
         * @return An iterator to the end of the container in reverse order.
         */
        auto end_reverse() const { 
            return ReverseOrderIterator<T>(*this, data.size()); 
        }

        /**
         * @brief Returns an iterator to the beginning of the container in insertion order.
         * @return An iterator to the beginning of the container in insertion order.
         */
        auto begin_order() const { 
            return OrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in insertion order.
         * @return An iterator to the end of the container in insertion order.
         */
        auto end_order() const { 
            return OrderIterator<T>(*this, data.size()); 
        }

        /**
         * @brief Returns an iterator to the beginning of the container in middle-out order.
         * @return An iterator to the beginning of the container in middle-out order.
         */
        auto begin_middleout() const { 
            return MiddleOutOrderIterator<T>(*this, 0); 
        }

        /**
         * @brief Returns an iterator to the end of the container in middle-out order.
         * @return An iterator to the end of the container in middle-out order.
         */
        auto end_middleout() const { 
            return MiddleOutOrderIterator<T>(*this, data.size()); 
        }
    };
    
}

#endif