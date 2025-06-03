// Email: shanig7531@gmail.com

#ifndef SIDECROSS_ORDER_ITERATOR_HPP
#define SIDECROSS_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <cstddef>

namespace Container {

    template<typename T>
    class MyContainer; 

    /**
     * @brief Iterator for traversing the container in side-cross order:
     * smallest, largest, 2nd smallest, 2nd largest, etc.
     * @tparam T The type of elements stored in the container.
     */
    template<typename T>
    class SideCrossOrderIterator {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<size_t> indices; // Indices in side-cross order
        size_t pos; // Current position in the indices vector

        /**
         * @brief Builds the indices vector in side-cross order.
         */
        void build_indices() {
            size_t n = container.size();
            indices.resize(n);
            std::vector<size_t> sorted_indices(n);
            for (size_t i = 0; i < n; ++i) {
                sorted_indices[i] = i;
            }
            // Sort indices by value (ascending)
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                [this](size_t a, size_t b) {
                    return container.data[a] < container.data[b];
                });

            // Fill indices in side-cross order: min, max, 2nd min, 2nd max, ...
            size_t left = 0, right = n ? n - 1 : 0, idx = 0;
            while (left <= right && idx < n) {
                indices[idx++] = sorted_indices[left++];
                if (left <= right && idx < n) {
                    indices[idx++] = sorted_indices[right--];
                }
            }
        }

    public:
        /**
         * @brief Constructor for the SideCrossOrderIterator.
         * @param cont Reference to the container.
         * @param start_pos The starting position for the iterator (default is 0).
         */
        SideCrossOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0)
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
        SideCrossOrderIterator& operator++() {
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
        bool operator==(const SideCrossOrderIterator& other) const {
            return pos == other.pos && &container == &other.container;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare.
         * @return True if iterators are at different positions or containers.
         */
        bool operator!=(const SideCrossOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif