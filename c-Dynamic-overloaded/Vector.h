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
        friend int getValue(T &value, std::istream &istream);

        // То же самое, что и getValue, только зациклен до тех пор, пока не будет введёт коректный тип данных.
        template<typename T>
        friend T getValueLoop(const char *err_message, std::istream &istream, std::ostream &ostream);
        //TODO убрать друзей!

        // Ввод ограниченного с двух сторон целого числа.
        static int getLimitedInt(int start, int end, const char *err_message,
                                 std::istream &istream, std::ostream &ostream);

        // Ввод ограниченного с одной стороны целого числа.
        static int getLimitedInt(int border, bool isStartBorder, const char *err_message,
                                 std::istream &istream, std::ostream &ostream);

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
         * Конструктор перемещения.
         * @details
         * Данный конструктор создаёт экземпляр класса на основе другого экземпляра (r-value) путём перемещения.
         * Будет создан вектор идентичный передаваемому вектору.
         * @param object - ссылка на r-value (экземпляр класса "Vector").
         */
        Vector(Vector &&object) noexcept;

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
         * @warning
         * Для создания пустого вектора использовать соответствующий конструктор. Не делать так:
         * @code
         * int main() {
         *     Vector v({}); // Не делать так! Ибо получится вектор с элементом 0, а не пустой: {0}
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
         * Оператор перемещения "=".
         * @details
         * Данный оператор изменяет экземпляр класса "Vector", используя семантику перемещения.\n\n
         * Пример:
         * @code
         * int createVector() {
         *     return Vector({1, 2, 3});
         * }
         *
         * int main() {
         *     Vector v1();
         *     v1 = createVector();
         *     return 0;
         * }
         * @endcode
         * @param object - ссылка на r-value (экземпляр класса "Vector").
         * @return Ссылка на экземпляр класса, в который производилось перемещение.
         */
        Vector &operator=(Vector &&object) noexcept;

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
        void inputVector(std::istream &istream, std::ostream &ostream);

        /**
         * @brief
         * Вывод вектора.
         * @details
         * Выводит вектор в стандартный поток вывода.\n\n
         * Формат вывода: {1, 2, 3, ...} или {}, если вектор с размерностью 0.
         */
        void outputVector(std::ostream &ostream) const;

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
         * Оператор ">>".
         * @details
         * Используется для считывания вектора из потока ввода.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v;
         *     std::cin >> v;
         *     return 0;
         * }
         * @endcode
         * @warning Шаблон ввода данных:
         * <размерность вектора> <элементы вектора>\n
         * Пример:\n
         * \>\> 5 1 2 3 4 5\n
         * Будет введён вектор: {1, 2, 3, 4, 5}.
         * @param stream - ссылка на поток ввода.
         * @param vector - ссылка на экземпляр класса "Vector".
         * @return ссылка на поток ввода.
         * @throw std::runtime_error при некорректном вводе данных.
         */
        friend std::istream &operator>>(std::istream &stream, Vector &vector);

        /**
         * @brief
         * Равенство векторов.
         * @details
         * Проверяет вектора на их эквивалентность.
         * @param vector - ссылка на экземпляр класса "Vector".
         * @return true - вектора равны, false если нет.
         */
        [[nodiscard]] bool equals(const Vector &vector) const;

        /**
         * @brief
         * Оператор "==".
         * @details
         * Используется для сравнения векторов.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({1, 2, 3});
         *     if (v1 == v2) {
         *         //do something;
         *     }
         *     return 0;
         * }
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param v2 - ссылка на экземпляр класса "Vector".
         * @return true - вектора равны, false если нет.
         */
        friend bool operator==(const Vector &v1, const Vector &v2);

        /**
         * @brief
         * Оператор "!=".
         * @details
         * Используется для сравнения векторов.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     Vector v2({1, 2, 3});
         *     if (v1 != v2) {
         *         //do something;
         *     }
         *     return 0;
         * }
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param v2 - ссылка на экземпляр класса "Vector".
         * @return false - вектора равны, true если нет.
         */
        friend bool operator!=(const Vector &v1, const Vector &v2);

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
         * @return результат, являющийся экземпляром класса "Vector".
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
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param v2 - ссылка на экземпляр класса "Vector".
         * @return результат, являющийся экземпляром класса "Vector".
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
         * @endcode
         * @param v1 - ссылка на экземпляр класса "Vector".
         * @param multiplier - множитель.
         * @return результат, являющийся экземпляром класса "Vector".
         */
        friend Vector operator*(const Vector &v1, int multiplier);

        /**
         * @brief
         * Оператор "/".
         * @details
         * Выполняет деление вектора на константу.
         * Целочисленное деление!\n\n
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
         * Использовать данный оператор аккуратно, ибо вектор хранит в себе значения типа int!
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
         * @return ссылка на экземпляр класса "Vector", к которому прибавляли другой вектор.
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
         * @return ссылка на экземпляр класса "Vector", из которого вычли другой вектор.
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
         * @return ссылка на экземпляр класса "Vector", который был умножен на константу.
         */
        Vector &operator*=(int multiplier);

        /**
         * @brief
         * Оператор "/=".
         * @details
         * Делим вектор, находящегося слева от оператора, на константу, находящуюся справа от оператора.
         * Целочисленное деление!\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v1({1, 2, 3});
         *     v1 /= 7;
         *     return 0;
         * }
         * @endcode
         * @warning
         * Использовать данный оператор аккуратно, ибо вектор хранит в себе значения типа int!
         * @param divider - делитель.
         * @return ссылка на экземпляр класса "Vector", который был поделён на константу.
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
         * @return результат выделение части вектора, являющийся экземпляром класса "Vector".
         * @throw std::invalid_argument возникает, если start + size > размеров исходного вектора.
         */
        [[nodiscard]] Vector copyN(int start, int size) const;

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
         */
        void sort(bool reverse = false);

        /**
         * @brief
         * Нахождение максимального элемента в векторе.
         * @return максимальный элемент в векторе.
         * @throw std::length_error возникает, если вектор имеет размерность равную 0.
         */
        [[nodiscard]] int getMax() const;

        /**
         * @brief
         * Нахождение минимального элемента в векторе.
         * @return минимальный элемент в векторе.
         * @throw std::length_error возникает, если вектор имеет размерность равную 0.
         */
        [[nodiscard]] int getMin() const;

        /**
         * @brief
         * Получение элемента.
         * @details
         * Получение элемента из вектора по его индексу.\n\n
         * Пример:
         * @code
         * int main() {
         *     Vector v({1, 2, 3});
         *     int element = v[1];
         *     return 0;
         * }
         * @endcode
         * @param index - индекс элемента.
         * @return Элемент вектора.
         * @throw std::invalid_argument возникает, если некорректно указан индекс элемента.
         */
        int operator[](int index);

        /**
         * @brief
         * Очистка вектора.
         * @details
         * Очистка вектора путём удаления всех элементов и установки размерности равной 0.
         */
        void clear();
    };

    bool operator==(const Vector &v1, const Vector &v2);

    bool operator!=(const Vector &v1, const Vector &v2);

    Vector operator+(const Vector &v1, const Vector &v2);

    Vector operator-(const Vector &v1, const Vector &v2);

    Vector operator*(const Vector &v1, int multiplier);

    Vector operator/(const Vector &v1, int divider);

    std::ostream &operator<<(std::ostream &stream, const Vector &vector);

    std::istream &operator>>(std::istream &stream, Vector &vector);

    template<typename T>
    int getValue(T &value, std::istream &istream) {
        istream >> value;
        if (istream.fail()) {
            if (istream.eof()) { throw std::runtime_error("Bad input"); }
            istream.clear();
            istream.ignore();
            return -1;
        }
        return 0;
    }

    template<typename T>
    T getValueLoop(const char *err_message, std::istream &istream, std::ostream &ostream) {
        T value;
        while (getValue<int>(value, istream) != 0) {
            ostream << err_message << std::endl;
        }
        return value;
    }
}

#endif //LAB_3_DYNAMICS_VECTOR_H
