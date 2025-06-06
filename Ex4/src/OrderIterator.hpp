// Email: shanig7531@gmail.com

#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP

#include <cstddef>

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator for traversing the container in insertion order.
     * @tparam T The type of elements stored in the container.
     */
    template<typename T>
    class OrderIterator {
    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        size_t pos; // Current position in the container

    public:
        /**
         * @brief Constructor for the OrderIterator.
         * @param cont Reference to the container.
         * @param start_pos The starting position for the iterator (default is 0).
         */
        OrderIterator(const MyContainer<T>& cont, size_t start_pos = 0)
            : container(cont), pos(start_pos) {}

        /**
         * @brief Dereference operator.
         * @return Reference to the current element in the container.
         * @throw std::out_of_range If iterator is out of bounds
         */
        const T& operator*() const {
            if (pos >= container.size()) {
                throw std::out_of_range("Iterator out of bounds");
            }
            return container.data[pos];
        }

        /**
         * @brief Pre-increment operator.
         * @return Reference to the iterator after increment.
         * @throw std::out_of_range If incrementing past the end
         */
        OrderIterator& operator++() {
            if (pos >= container.size()) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            ++pos;
            return *this;
        }

        /**
         * @brief Post-increment operator.
         * @return Copy of iterator before increment.
         * @throw std::out_of_range If incrementing past the end
         */
        OrderIterator operator++(int) {
            if (pos >= container.size()) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            OrderIterator temp = *this;
            ++pos;
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Another iterator to compare.
         * @return True if both iterators are at the same position and container.
         */
        bool operator==(const OrderIterator& other) const {
            return pos == other.pos && &container == &other.container;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare.
         * @return True if iterators are at different positions or containers.
         */
        bool operator!=(const OrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif