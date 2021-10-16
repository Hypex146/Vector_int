//
// Created by vlad_ on 14.10.2021.
//

#ifndef LAB_3_DYNAMICS_VECTOR_H
#define LAB_3_DYNAMICS_VECTOR_H

#include <iostream>

namespace HypexLib {

    class Vector {
    private:
        int *elements_ = nullptr;
        int size_ = 0;

        void qSort(int start, int end, int *mas);

        void extend(int new_size);

        [[nodiscard]] int *copyElements() const;

    public:
        Vector() = default;

        explicit Vector(int element);

        Vector(int size, const int *mas);

        Vector(const Vector &object);

        template<std::size_t N>
        explicit Vector(const int (&elements)[N]){
            size_ = N;
            elements_ = new int[size_];
            for (int i = 0; i < N; i++) {
                elements_[i] = elements[i];
            }
        }

        Vector &operator=(const Vector &object);

        template<std::size_t N>
        Vector &operator=(const int (&elements)[N]) {
            delete [] elements_;
            size_ = N;
            elements_ = new int[size_];
            for (int i = 0; i < N; i++) {
                elements_[i] = elements[i];
            }
            return *this;
        }

        virtual ~Vector();

        [[nodiscard]] int getSize() const;

        void inputVector();

        void outputVector();

        friend std::ostream &operator<<(std::ostream &stream, const Vector &vector);

        void sum(const Vector &summand);

        friend Vector operator+(const Vector &v1, const Vector &v2);

        Vector &operator+=(const Vector &v1);

        Vector cut(int start, int size);

        void add(int new_element);

        void sortAscending();

        int getMax();

        void clear();
    };

    template<typename T>
    int getValue(T &value) {
        std::cin >> value;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore();
            return -1;
        }
        return 0;
    }

    template<typename T>
    T getValueLoop(const std::string &err_message) {
        T value;
        while (getValue<int>(value) != 0) {
            std::cout << err_message << std::endl;
        }
        return value;
    }

    int getLimitedInt(int start, int end, const std::string &errMessage);

    int getLimitedInt(int border, bool isStartBorder, const std::string &errMessage);

    Vector operator+(const Vector &v1, const Vector &v2);

    std::ostream &operator<<(std::ostream &stream, const Vector &vector);
}

#endif //LAB_3_DYNAMICS_VECTOR_H
