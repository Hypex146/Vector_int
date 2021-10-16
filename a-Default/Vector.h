//
// Created by vlad_ on 14.10.2021.
//

#ifndef LAB_3_VECTOR_H
#define LAB_3_VECTOR_H

#include <iostream>

namespace HypexLib {

    class Vector {
    private:
        static const int max_size_ = 10;
        int elements_[max_size_] = {0};
        int size_ = 0;

        void qSort(int start, int end, int *mas);

        [[nodiscard]] bool canAdd() const;

    public:
        Vector() = default;

        explicit Vector(int element);

        Vector(int size, const int *mas);

        Vector(const Vector &object) = default;

        Vector &operator=(const Vector &object) = default;

        ~Vector() = default;

        [[nodiscard]] int getSize() const;

        void inputVector();

        void outputVector();

        void sum(const Vector &summand);

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

}

#endif //LAB_3_VECTOR_H
