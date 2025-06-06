// Email: shanig7531@gmail.com

#ifndef ASCENDING_ORDER_ITERATOR_HPP
#define ASCENDING_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <cstddef>

namespace Container {

    template<typename T>
    class MyContainer; 

    /**
     * @brief Iterator for traversing the container in ascending order.
     * @tparam T The type of elements stored in the container.
     */
    template<typename T>
    class AscendingOrderIterator {

    private:
        const MyContainer<T>& container; // Reference to the container being iterated
        std::vector<size_t> indices; // Indices of elements in ascending order
        size_t pos; // Current position in the indices vector

        /**
         * @brief Builds the indices vector sorted by the container's elements in ascending order.
         */
        void build_indices() {
            indices.resize(container.size());
            for (size_t i = 0; i < container.size(); ++i) {
                indices[i] = i;
            }
            std::sort(indices.begin(), indices.end(),
                [this](size_t a, size_t b) {
                    return container.data[a] < container.data[b];
                });
        }

    public:
        /**
         * @brief Constructor for the AscendingOrderIterator.
         * @param cont Reference to the container.
         * @param start_pos The starting position for the iterator (default is 0).
         */
        AscendingOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0)
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
        AscendingOrderIterator& operator++() {
            if (pos >= container.size()) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            ++pos;
            return *this;
        }

        /**
         * @brief Post-increment operator.
         * @return Iterator to the position before increment.
         * @throw std::out_of_range If incrementing past the end
         */
        AscendingOrderIterator operator++(int) {
            if (pos >= container.size()) {
                throw std::out_of_range("Cannot increment iterator past end");
            }
            AscendingOrderIterator temp = *this;
            ++pos;
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Another iterator to compare.
         * @return True if both iterators are at the same position and container.
         */
        bool operator==(const AscendingOrderIterator& other) const {
            return pos == other.pos && &container == &other.container;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Another iterator to compare.
         * @return True if iterators are at different positions or containers.
         */
        bool operator!=(const AscendingOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace Container

#endif