// Email: shanig7531@gmail.com

#ifndef MIDDLE_OUT_ORDER_ITERATOR_HPP
#define MIDDLE_OUT_ORDER_ITERATOR_HPP

#include <vector>
#include <cstddef>

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator for traversing the container from middle outwards.
     * @details Starts from middle element, then alternates between left and right elements.
     * For odd-sized containers, middle element is floor(size/2).
     * @tparam T The type of elements stored in the container.
     */
    template<typename T>
    class MiddleOutOrderIterator {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<size_t> indices; // Indices in middle-out order
        size_t pos; // Current position in indices vector

        /**
         * @brief Builds the indices vector for middle-out traversal order.
         */
        void build_indices() {
            size_t n = container.size();
            indices.resize(n);
            
            if (n == 0) return;

            // Start from middle - for odd n, take floor(n/2)
            size_t mid = n / 2;
            size_t left = mid - 1;
            size_t right = mid + 1;
            size_t idx = 0;

            // Add middle element first
            indices[idx++] = mid;

            // Alternate between left and right elements
            while (idx < n) {
                if (left != static_cast<size_t>(-1)) {
                    indices[idx++] = left--;
                }
                if (idx < n && right < n) {
                    indices[idx++] = right++;
                }
            }
        }

    public:
        /**
         * @brief Constructor for the MiddleOutOrderIterator.
         * @param cont Reference to the container.
         * @param start_pos The starting position for the iterator (default is 0).
         */
        MiddleOutOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0)
            : container(cont), pos(start_pos) {
            build_indices();
        }

        /**
         * @brief Dereference operator.
         * @return Reference to the current element in the container.
         * @throw std::out_of_range If iterator is out of bounds
         */
        const T& operator*() const {
            if (pos >= container.size()) {
                throw std::out_of_range("Iterator out of bounds");
            }
            return container.data[indices[pos]];
        }

        /**
         * @brief Pre-increment operator.
         * @return Reference to the iterator after increment.
         * @throw std::out_of_range If incrementing past the end
         */
        MiddleOutOrderIterator& operator++() {
            if (pos >= container.size()) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            ++pos;
            return *this;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Another iterator to compare.
         * @return True if both iterators are at the same position and container.
         */
        bool operator==(const MiddleOutOrderIterator& other) const {
            return pos == other.pos && &container == &other.container;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare.
         * @return True if iterators are at different positions or containers.
         */
        bool operator!=(const MiddleOutOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif