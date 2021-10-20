/**
 * @file
 * @brief
 * Заголовочный файл с описанием класса "Vector".
 * @details
 * Данный файл содержит в себе описание класса "Vector" и некоторых функций, дружественных классу.
 * @author Коломенский В.Г. [Б20-503]
 * @date 16.10.2021
 */
#ifndef LAB_3_DYNAMICS_VECTOR_H
#define LAB_3_DYNAMICS_VECTOR_H

#include <iostream>

/**
 * @brief
 * Пространство имён, созданное для класса "Vector".
 */
namespace HypexVector {
    //TODO сделать модульные тесты.
    /**
     * @brief
     * Вектор целых чисел.
     * @details
     * Класс - вектор целых чисел, предназначен для работы с целочесленными элементами.
     * Вектор может быть произвольной размерности.
     * @warning
     * При обнаружении ошибок/багов, писать мне: https://vk.com/vkolomenskii02.
     * Постараюсь быстро исправить.
     */
    class Vector {
    private:

        // Указатель на массив элементов вектора типа int.
        int *elements_ = nullptr;

        // Количество элементов вектора, его размерность.
        int size_ = 0;

        // Быстрая сортировка массива типа int.
        void qSort(int start, int end, int *mas, bool reverse);

        // Изменение размера массива элементов, размерности вектора.
        // При уменьшении размерности элементы отбрасываются с конца.
        void extend(int new_size);

        // Возвращает массив целочисленных элементов, являющихся элементами вектора.
        [[nodiscard]] int *copyElements() const;

        // Ввод. Если ввод не коректен (введён не тот тип данных), метод вернёт -1.
        // Если ввод коректен, метод вернёт 0.
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

        // То же самое, что и getValue, только зациклен до тех пор, пока не будет введёт коректный тип данных.
        template<typename T>
        static T getValueLoop(const std::string &err_message) {
            T value;
            while (getValue<int>(value) != 0) {
                std::cout << err_message << std::endl;
            }
            return value;
        }

        // Ввод ограниченного с двух сторон целого числа.
        static int getLimitedInt(int start, int end, const std::string &errMessage);

        // Ввод ограниченного с одной стороны целого числа.
        static int getLimitedInt(int border, bool isStartBorder, const std::string &errMessage);

    public:

        /**
         * @brief
         * Конструктор.
         * @details
         * Данный конструктор создаёт экземпляр класса с инициализацией параметров по умолчанию.\n
         * Будет создан вектор размерности 0.
         */
        Vector() = default;

        /**
         * @brief
         * Конструктор.
         * @details
         * Данный конструктор создаёт экземпляр класса с инициализацией единственного элемента вектора.\n
         * Будет создан вектор размерности 1.
         * @param element - единственный элемент вектора.
         */
        explicit Vector(int element);

        /**
         * @brief
         * Конструктор.
         * @details
         * Данный конструктор создаёт экземпляр класса на основе переданного указателя на первый элемент массива
         * значений типа int.\n
         * Будет создан вектор размерности <size>.
         * @param size - размер передаваемого массива.
         * @param mas - указатель на первый элемент передаваемого массива.
         */
        Vector(int size, const int *mas);

        /**
         * @brief
         * Конструктор копирования.
         * @details
         * Данный конструктор выполняет грубокое копирование переданного экземпляра класса "Vector".\n
         * Будет создан вектор идентичный передаваемому вектору.
         * @param object - ссылка на копируемый экземпляр класса "Vector".
         */
        Vector(const Vector &object);

        /**
         * @brief
         * Конструктор.
         * @details
         * Данный конструктор создаёт экземпляр класса на основе переданного массива значений типа int.
         * Прошу обратить внимание: передаётся не указатель на первый элемент массива, а указатель на весь массив,
         * т.е. array type!\n
         * Будет создан вектор размерности, равной размеру массива.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v({1, 2 ,3});
         *     return 0;
         * }
         * @endcode
         * @tparam N - определяется компилятором, не трагать!
         * @param elements - указатель на массив.
         */
        template<std::size_t N>
        explicit Vector(const int (&elements)[N]) {
            size_ = N;
            elements_ = new int[size_];
            for (int i = 0; i < N; i++) {
                elements_[i] = elements[i];
            }
        }

        /**
         * @brief
         * Оператор копирования "=".
         * @details
         * Данный оператор копирует экземпляр класса "Vector", стоящий справа от оператора, в экзмепляр,
         * стоящий слева от оператора.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2 ,3});
         *     Vector v2(v1);
         *     return 0;
         * }
         * @endcode
         * @param object - ссылка на экземпляр класса "Vector".
         * @return Ссылка на экземпляр класса, в который производилось копирование.
         */
        Vector &operator=(const Vector &object);

        /**
         * @brief
         * Оператор "="
         * @details
         * Данный оператор изменяет экземпляр класса "Vector" в соответствии с массивом значений типа int.
         * Прошу обратить внимание: передаётся не указатель на первый элемент массива, а указатель на весь массив,
         * т.е. array type!\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v;
         *     v = {1, 2, 3};
         *     return 0;
         * }
         * @endcode
         * @tparam N - определяется компилятором, не трагать!
         * @param elements - указатель на массив.
         * @return Ссылка на экземпляр класса.
         */
        template<std::size_t N>
        Vector &operator=(const int (&elements)[N]) {
            delete[] elements_;
            size_ = N;
            elements_ = new int[size_];
            for (int i = 0; i < N; i++) {
                elements_[i] = elements[i];
            }
            return *this;
        }

        /**
         * @brief
         * Диструктор.
         */
        virtual ~Vector();

        /**
         * @brief
         * Возвращает размерность вектора - кол-во элементов.
         * @return размерность вектора - кол-во элементов.
         */
        [[nodiscard]] int getSize() const;

        /**
         * @brief
         * Ввод вектора.
         * @details
         * Заполняет вектор информацией, вводимой из стандартного входного потока.
         * Если метод будет вызван уже заполненным вектором, то имеющаяся информация будет удалена (перезаписана).
         */
        void inputVector();

        /**
         * @brief
         * Вывод вектора.
         * @details
         * Выводит вектор в стандартный поток вывода.\n\n
         * Формат вывода: {1, 2, 3, ...} или {}, если вектор с размерностью 0.
         */
        void outputVector();

        /**
         * @brief
         * Оператор "<<".
         * @details
         * Используется для помещения вектора в поток вывода.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v;
         *     std::cout << v;
         *     return 0;
         * }
         * @endcode
         * @param stream - ссылка на поток вывода.
         * @param vector - ссылка на экземпляр класса "Vector".
         * @return ссылка на поток вывода.
         */
        friend std::ostream &operator<<(std::ostream &stream, const Vector &vector);

        /**
         * @brief
         * Равенство векторов.
         * @details
         * Проверяет вектора на их эквивалентность.
         * @param vector - ссылка на экземпляр класса "Vector".
         * @return true - вектора равны, false если нет.
         */
        bool equals(const Vector &vector);

        /**
         * @brief
         * Суммирование векторов.
         * @details
         * Выполняет суммирования двух векторов, результат записывается в экземпляр, который вызвал данный метод.
         * @param summand - ссылка на экземпляр класса "Vector".
         */
        void summarize(const Vector &summand);

        /**
         * @brief
         * Раазность векторов.
         * @details
         * Выполняет вычитание переданного вектора из вектора, у которого вызывается метод.
         * Результат записывается в экземпляр класса "Vector", который вызвал данный метод.
         * @param deductible - вычитаемый вектор.
         */
        void subtract(const Vector &deductible);

        /**
         * @brief
         * Умножение на константу.
         * @details
         * Выполняет умножение данного вектора на константу.
         * @param multiplier - константа, на которую умножается вектор.
         */
        void multiply(int multiplier);

        /**
         * @brief
         * Деление на константу.
         * @details
         * Выполняет деление данного вектора на константу.
         * @warning
         * Использовать данный метод аккуратно, ибо вектор хранит в себе значения типа int!
         * @param divider - делитель.
         * @throw std::invalid_argument при попытке поделить на 0.
         */
        void divide(int divider);

        /**
         * @brief
         * Оператор "+".
         * @details
         * Выполняет суммирования двух векторов, результат возвращает.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({3, 2, 1});
         *     Vector v3;
         *     v3 = v1 + v2;
         *     return 0;
         * }
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param v2 - ссылка на экземпляр класса "Vector".
         * @return - результат, являющийся экземпляром класса "Vector".
         */
        friend Vector operator+(const Vector &v1, const Vector &v2);

        /**
         * @brief
         * Оператор "-".
         * @details
         * Выполняет вычитание двух векторов, результат возвращает.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({3, 2, 1});
         *     Vector v3;
         *     v3 = v1 - v2;
         *     return 0;
         * }
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param v2 - ссылка на экземпляр класса "Vector".
         * @return - результат, являющийся экземпляром класса "Vector".
         */
        friend Vector operator-(const Vector &v1, const Vector &v2);

        /**
         * @brief
         * Оператор "*".
         * @details
         * Выполняет умножение вектора на константу.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2;
         *     v2 = v1 * 7;
         *     return 0;
         * }
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param multiplier - множитель.
         * @return результат, являющийся экземпляром класса "Vector".
         */
        friend Vector operator*(const Vector &v1, int multiplier);

        /**
         * @brief
         * Оператор "/".
         * @details
         * Выполняет деление вектора на константу.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2;
         *     v2 = v1 / 7;
         *     return 0;
         * }
         * @endcode
         * @warning
         * Использовать данный метод аккуратно, ибо вектор хранит в себе значения типа int!
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param divider - делитель.
         * @return результат, являющийся экземпляром класса "Vector".
         * @throw std::invalid_argument при попытке поделить на 0.
         */
        friend Vector operator/(const Vector &v1, int divider);

        /**
         * @brief
         * Оператор "+=".
         * @details
         * Прибавляет к вектору, находящемуся слева от оператора, вектор, находящийся справа от оператора.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({3, 2, 1});
         *     v1 += v2;
         *     return 0;
         * }
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @return - ссылка на экземпляр класса "Vector", к которому прибавляли другой вектор.
         */
        Vector &operator+=(const Vector &v1);

        /**
         * @brief
         * Оператор "-=".
         * @details
         * Вычитает из вектора, находящегося слева от оператора, вектор, находящийся справа от оператора.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({3, 2, 1});
         *     v1 -= v2;
         *     return 0;
         * }
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @return - ссылка на экземпляр класса "Vector", из которого вычли другой вектор.
         */
        Vector &operator-=(const Vector &v1);

        /**
         * @brief
         * Оператор "*=".
         * @details
         * Умножаем вектор, находящегося слева от оператора, на константу, находящуюся справа от оператора.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     v1 *= 7;
         *     return 0;
         * }
         * @endcode
         * @param multiplier - множитель.
         * @return - ссылка на экземпляр класса "Vector", который был умножен на константу.
         */
        Vector &operator*=(int multiplier);

        /**
         * @brief
         * Оператор "/=".
         * @details
         * Делим вектор, находящегося слева от оператора, на константу, находящуюся справа от оператора.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     v1 /= 7;
         *     return 0;
         * }
         * @endcode
         * @warning
         * Использовать данный метод аккуратно, ибо вектор хранит в себе значения типа int!
         * @param divider - делитель.
         * @return - ссылка на экземпляр класса "Vector", который был поделён на константу.
         * @throw std::invalid_argument при попытке поделить на 0.
         */
        Vector &operator/=(int divider);

        /**
         * @brief
         * Выделение части вектора.
         * @details
         * Выделение части вектора указанной длины, начиная с элемента, заданного его порядковым номером в векторе.
         * @param start - порядковый номер первого элемента для выделения.
         * @param size - длина выделения.
         * @return - результат выделение части вектора, являющийся экземпляром класса "Vector".
         * @throw std::invalid_argument возникает, если start + size > размеров исходного вектора.
         */
        Vector cut(int start, int size);

        /**
         * @brief
         * Включение в вектор нового элемента.
         * @param new_element - новый элемент вектора.
         */
        void add(int new_element);

        /**
         * @brief
         * Упорядочение вектора.
         * @param reverse - изменить порядок с возрастающего на убывающий?
         * @throw std::length_error возникает, если вектор имеет размерность равную 0.
         */
        void sort(bool reverse);

        /**
         * @brief
         * Нахождение максимального элемента в векторе.
         * @return максимальный элемент в векторе.
         * @throw std::length_error возникает, если вектор имеет размерность равную 0.
         */
        int getMax();

        /**
         * @brief
         * Нахождение минимального элемента в векторе.
         * @return минимальный элемент в векторе.
         * @throw std::length_error возникает, если вектор имеет размерность равную 0.
         */
        int getMin();

        /**
         * @brief
         * Очистка вектора.
         * @details
         * Очистка вектора путём удаления всех элементов и установки размерности равной 0.
         */
        void clear();
    };

    Vector operator+(const Vector &v1, const Vector &v2);

    Vector operator-(const Vector &v1, const Vector &v2);

    Vector operator*(const Vector &v1, int multiplier);

    Vector operator/(const Vector &v1, int divider);

    std::ostream &operator<<(std::ostream &stream, const Vector &vector);
}

#endif //LAB_3_DYNAMICS_VECTOR_H
