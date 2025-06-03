// Email: shanig7531@gmail.com

#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP

#include <vector>
#include <cstddef>

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator for traversing the container in reverse (insertion) order.
     * @tparam T The type of elements stored in the container.
     */
    template<typename T>
    class ReverseOrderIterator {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        size_t pos; // Current position (reverse index)

    public:
        /**
         * @brief Constructor for the ReverseOrderIterator.
         * @param cont Reference to the container.
         * @param start_pos The starting position for the iterator (default is 0).
         */
        ReverseOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0)
            : container(cont) {
            // Start from the last element if start_pos == 0, otherwise from (size - start_pos)
            pos = cont.size() == 0 ? 0 : cont.size() - 1 - start_pos;
        }

        /**
         * @brief Dereference operator.
         * @return Reference to the current element in the container.
         * @throw std::out_of_range If iterator is out of bounds
         */
        const T& operator*() const {
            if (pos == static_cast<size_t>(-1) || pos >= container.size()) {
                throw std::out_of_range("Iterator out of bounds");
            }
            return container.data[pos];
        }

        /**
         * @brief Pre-increment operator.
         * @return Reference to the iterator after increment.
         * @throw std::out_of_range If incrementing past the end
         */
        ReverseOrderIterator& operator++() {
            if (pos == static_cast<size_t>(-1)) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            if (pos == 0) {
                pos = static_cast<size_t>(-1);
            } else {
                --pos;
            }
            return *this;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Another iterator to compare.
         * @return True if both iterators are at the same position and container.
         */
        bool operator==(const ReverseOrderIterator& other) const {
            return pos == other.pos && &container == &other.container;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare.
         * @return True if iterators are at different positions or containers.
         */
        bool operator!=(const ReverseOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif