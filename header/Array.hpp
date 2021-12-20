#pragma once

#include <iostream>

namespace aad {


    
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

        public:

            Array() {
                reserveSpaceForValues();
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

            T& operator[](int index) const {
                return values[index];
            }

            T& at(size_t pos) const {
                keepInBounds(pos);
                return values[pos];
            }

            size_t size() const {
                return N;
            }

            T *data() const {
                return values;
            }

            T& front() const {
                return values[0];
            }

            T& back() const {
                return values[N-1];
            }
    };

}