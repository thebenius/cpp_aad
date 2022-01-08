#pragma once

#include <iostream>
#include "conditional.hpp"

namespace aad {
    
    /**
     * @brief aad::Array is a container that encapsulates fixed size arrays
     * 
     * It combines the low complexity of arrays and the advantages of
     * container types such as knowing the size
     * 
     * @tparam T type stored in array
     * @tparam N size of the array
     */
    template<typename T, size_t N>
    class Array {
        private:
            T *values;

            inline void reserveSpaceForValues() {
                values = (T*)malloc(sizeof(T) * N);
                if (values == nullptr) {
                    throw std::ios_base::failure("malloc");
                }
            }

            inline void freeValues() {
                delete[] values;
                values = nullptr;
            }

            inline void copyValues(const T *other) {
                memcpy(values, other, sizeof(T) * N);
            }

            inline bool inRange(size_t pos) const {
                return (pos < N);
            }

            inline void keepInBounds(size_t pos) const {
                if (!inRange(pos)) {
                    throw std::out_of_range("Intex out of bounds");
                }
            }

            inline void insert(const size_t pos, const T& arg) {
                values[pos] = arg;
            }

            template <typename ...Args>
            inline void insert(const size_t pos, const T& arg, const Args&... args) {
                insert(pos, arg);
                insert(pos+1, args...);
            }

        public:

            /**
             * @brief iterable version of array
             */
            class iterator {
                private:
                    Array<T, N> *obj;

                protected:
                    size_t pos;

                public:
                    iterator(Array<T, N> *obj, size_t pos) {
                        this->obj = obj;
                        this->pos = pos;
                    }

                    T& operator*() const {
                        return (*obj)[pos];
                    }

                    iterator operator++(int) {
                        iterator old = *this;
                        ++(this->pos);
                        return old;
                    }

                    iterator operator++() {
                        ++pos;
                        return *this;
                    }


                    bool operator==(const aad::Array<T, N>::iterator &other) const {
                        if (this->pos != other.pos) return false;
                        if (obj != other.obj) return false;
                        return true;
                    }

                    bool operator!=(const aad::Array<T, N>::iterator &other) const {
                        return !(*this == other);
                    }

            };

            /**
             * @brief iterable version of array in reverse
             */
            class reverse_iterator {
                private:
                    Array<T, N> *obj;

                protected:
                    size_t pos;

                public:
                    reverse_iterator(Array<T, N> *obj, size_t pos) {
                        this->obj = obj;
                        this->pos = pos;
                    }

                    T& operator*() const {
                        return (*obj)[pos];
                    }

                    reverse_iterator operator++(int) {
                        reverse_iterator old = *this;
                        --(this->pos);
                        return old;
                    }

                    reverse_iterator operator++() {
                        --pos;
                        return *this;
                    }
                    
                    bool operator==(const aad::Array<T, N>::reverse_iterator &other) const {
                        if (this->pos != other.pos) return false;
                        if (obj != other.obj) return false;
                        return true;
                    }

                    bool operator!=(const aad::Array<T, N>::reverse_iterator &other) const {
                        return !(*this == other);
                    }

            };

            /**
             * @brief Construct a new Array object
             * 
             * Instantiates array of variables of type T with length N.
             * It doesn't initializes variables. Values are undefined. 
             * 
             * ### Complexity
             * constant
             * 
             * @attention unspecified behavior for N=0
             */
            Array() {
                reserveSpaceForValues();
            }

            /**
             * @brief Construct a new Array object from literal
             * 
             * Copies the array literal into the array.
             * 
             * @note Literal size must be smaler or equal to array size.
             * 
             * @param args an array literal
             * 
             * ### Complexity
             * linear
             */
            template <typename ...Args,
            typename = typename std::enable_if<are_all_convertible<T, Args...>::value>::type>
            Array(const Args&... args) {
                static_assert(sizeof...(args) <= N);
                reserveSpaceForValues();
                insert(0, args...);
            }


            Array(const Array& other) {
                reserveSpaceForValues();
                copyValues(other.data());
            }

            Array& operator=(const Array& other) {
                T *tmp = values;
                freeValues();
                reserveSpaceForValues();
                copyValues(other.data());
                values = tmp;
                return *this;
            }

            ~Array() {
                freeValues();
            }

            /**
             * @brief Access Operator
             * 
             * Returns the element at the index specified
             * 
             * @param index element index
             * @return T& element at given index
             * 
             * ### Complexity
             * constant
             */
            T& operator[](int index) const {
                return values[index];
            }

            bool operator==(aad::Array<T, N> &other) {
                return this == &other;
            }

            bool operator!=(aad::Array<T, N> &other) {
                return !(*this == other);
            }

            /**
             * @brief Access Element at specified position
             * 
             * Returns the element at the position specified in pos
             * 
             * @param pos position
             * @return T& element at given position
             * 
             * ### Complexity
             * constant
             */
            T& at(size_t pos) const {
                keepInBounds(pos);
                return values[pos];
            }

            /**
             * @brief returns the number of elements
             * 
             * @return size_t number of elements
             * 
             * ### Complexity
             * constant
             */
            size_t size() const {
                return N;
            }

            /**
             * @brief direct access to the underlying data
             * 
             * @return T* pointer to the actual array
             * 
             * ### Complexity
             * constant
             */
            T *data() const {
                return values;
            }

            /**
             * @brief access the first element
             * 
             * @return T& first element
             * 
             * ### Complexity
             * constant
             */
            T& front() const {
                return values[0];
            }

            /**
             * @brief access last element
             * 
             * @return T& last element
             * 
             * ### Complexity
             * constant
             */
            T& back() const {
                return values[N-1];
            }

            /**
             * @brief get iterator pointing to first element
             * 
             * @return self::iterator
             */
            iterator begin() {
                return iterator(this, 0);
            }

            /**
             * @brief get iterator pointing to end of array
             * 
             * @return self::iterator
             */
            iterator end() {
                return iterator(this, size());
            }

            /**
             * @brief get reverse_iterator pointing to first element of reversed array
             * 
             * @return self::reverse_iterator
             */
            reverse_iterator rbegin() {
                return reverse_iterator(this, size()-1);
            }


            /**
             * @brief get reverse_iterator pointing to end of reversed array
             * 
             * @return self::iterator
             */
            reverse_iterator rend() {
                return reverse_iterator(this, -1);
            }
    };

}

