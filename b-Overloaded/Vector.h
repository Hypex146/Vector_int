#ifndef LAB_3_OVERLOAD_VECTOR_H
#define LAB_3_OVERLOAD_VECTOR_H

#include <iostream>

namespace HypexVector {

    class Vector {
    private:
        static const int max_size_ = 100;
        int elements_[max_size_] = {0};
        int size_ = 0;

        // Быстрая сортировка
        void qSort(int start, int end, int *mas);

        // Проверка на возможность добавления нового элемента в вектор
        [[nodiscard]] bool canAdd() const;

        // Ввод. Если ввод не коректен (введён не тот тип данных), метод вернёт -1
        // Если ввод коректен, метод вернёт 0
        template<typename T>
        static int getValue(T &value) {
            std::cin >> value;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore();
                return -1;
            }
            return 0;
        }

        // То же самое, что и getValue, только зациклен до тех пор, пока не будет введёт коректный тип данных
        template<typename T>
        static T getValueLoop(const std::string &err_message) {
            T value;
            while (getValue<int>(value) != 0) {
                std::cout << err_message << std::endl;
            }
            return value;
        }

        // Ввод ограниченного с двух сторон целого числа
        static int getLimitedInt(int start, int end, const std::string &errMessage);

        // Ввод ограниченного с одной стороны целого числа.
        static int getLimitedInt(int border, bool isStartBorder, const std::string &errMessage);

    public:
        // Пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию
        Vector() = default;

        // Создание экземпляров класса с инициализацией единственным элементом вектора
        explicit Vector(int element);

        // Создание экземпляров класса с инициализацией размером и массивом значений элементов вектора
        Vector(int size, const int *mas);

        // Создание экземпляра класса с его инициализацией другим экземпляром класса (копирующий конструктор)
        Vector(const Vector &object) = default;

        // Переопределение экземпляра класса (с помощью перегруженного оператора присваивания)
        Vector &operator=(const Vector &object) = default;

        ~Vector() = default;

        [[nodiscard]] int getSize() const;

        // Ввод экземпляров класса из входного потока
        void inputVector();

        // Вывод значений вектора в выходной поток
        void outputVector() const;

        friend std::ostream &operator<<(std::ostream &stream, const Vector &vector);

        // Выполнение операции сложения двух векторов
        void sum(const Vector &summand);

        friend Vector operator+(const Vector &v1, const Vector &v2);

        Vector &operator+=(const Vector &v1);

        // Выделение части вектора указанной длины, начиная с элемента, заданного его порядковым номером в векторе
        [[nodiscard]] Vector cut(int start, int size) const;

        //  Выполнение операции включения в вектор нового элемента
        void add(int new_element);

        // Упорядочение вектора по возрастанию
        void sortAscending();

        // Нахождение максимального элемента в векторе
        [[nodiscard]] int getMax() const;

        // Очистка вектора
        void clear();
    };

    std::ostream &operator<<(std::ostream &stream, const Vector &vector);

    Vector operator+(const Vector &v1, const Vector &v2);

}

#endif //LAB_3_OVERLOAD_VECTOR_H
