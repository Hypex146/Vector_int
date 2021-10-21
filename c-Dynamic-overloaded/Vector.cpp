//
// Created by vlad_ on 14.10.2021.
//

#include "Vector.h"

using namespace HypexVector;

int Vector::getLimitedInt(int start, int end, const std::string &errMessage) {
    int result;
    do {
        result = getValueLoop<int>("[ERROR] Try again!");
        if (result < start || result > end) { std::cout << errMessage << std::endl; }
    } while (result < start || result > end);
    return result;
}

int Vector::getLimitedInt(int border, bool isStartBorder, const std::string &errMessage) {
    int result;
    if (isStartBorder) {
        do {
            result = getValueLoop<int>("[ERROR] Try again!");
            if (result < border) { std::cout << errMessage << std::endl; }
        } while (result < border);
    } else {
        do {
            result = getValueLoop<int>("[ERROR] Try again!");
            if (result > border) { std::cout << errMessage << std::endl; }
        } while (result > border);
    }
    return result;
}

int *Vector::copyElements() const {
    int *new_mas = new int[size_];
    for (int i = 0; i < size_; i++) {
        new_mas[i] = elements_[i];
    }
    return new_mas;
}

Vector::Vector(int element) {
    size_ = 1;
    elements_ = new int[1];
    elements_[0] = element;
}

Vector::Vector(int size, const int *mas) {
    size_ = size;
    elements_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        elements_[i] = mas[i];
    }
}

Vector::Vector(const Vector &object) {
    this->size_ = object.size_;
    this->elements_ = object.copyElements();
}

Vector &Vector::operator=(const Vector &object) {
    if (this == &object) { return *this; }
    delete[] elements_;
    size_ = object.size_;
    elements_ = object.copyElements();
    return *this;
}

Vector::~Vector() {
    delete[] elements_;
}

void Vector::extend(int new_size) {
    int loop_pass = 0;
    if (new_size == size_) { return; }
    else if (new_size > size_) { loop_pass = size_; }
    else { loop_pass = new_size; }
    int *new_mas = new int[new_size];
    for (int i = 0; i < loop_pass; i++) {
        new_mas[i] = elements_[i];
    }
    for (int i = loop_pass; i < new_size; i++) {
        new_mas[i] = 0;
    }
    delete[] elements_;
    size_ = new_size;
    elements_ = new_mas;
}

int Vector::getSize() const {
    return size_;
}

void Vector::inputVector() {
    clear();
    std::cout << "Enter the size of the vector (int):" << std::endl;
    int size = getLimitedInt(0, true, "[ERROR] Bad value of size! Try again");
    size_ = size;
    elements_ = new int[size_];
    std::cout << "Enter the vector elements (int):" << std::endl;
    for (int i = 0; i < size; i++) {
        int element = getValueLoop<int>("[ERROR] Bad value of element! Try again");
        elements_[i] = element;
    }
    std::cout << "Vector successfully entered!" << std::endl;
}

void Vector::outputVector() const {
    if (!elements_) {
        std::cout << "{}" << std::endl;
        return;
    }
    std::cout << "{";
    for (int i = 0; i < size_; i++) {
        if (i != size_ - 1) {
            std::cout << elements_[i] << ", ";
        } else {
            std::cout << elements_[i];
        }
    }
    std::cout << "}" << std::endl;
}

std::ostream &HypexVector::operator<<(std::ostream &stream, const Vector &vector) {
    if (!vector.elements_) {
        stream << "{}" << std::endl;
        return stream;
    }
    stream << "{";
    for (int i = 0; i < vector.size_; i++) {
        if (i != vector.size_ - 1) {
            stream << vector.elements_[i] << ", ";
        } else {
            stream << vector.elements_[i];
        }
    }
    stream << "}" << std::endl;
    return stream;
}

bool Vector::equals(const Vector &vector) const {
    if (this == &vector) { return true; }
    if (size_ != vector.size_) { return false; }
    for (int i = 0; i < size_; i++) {
        if (elements_[i] != vector.elements_[i]) { return false; }
    }
    return true;
}

bool HypexVector::operator==(const Vector &v1, const Vector &v2) {
    return v1.equals(v2);
}

void Vector::summarize(const Vector &summand) {
    int cycle_pass = summand.size_;
    int new_size = size_;
    if (summand.size_ > size_) {
        new_size = summand.size_;
        //cycle_pass = size_;
    }
    extend(new_size);
    for (int i = 0; i < cycle_pass; i++) {
        elements_[i] += summand.elements_[i];
    }
}

void Vector::subtract(const Vector &deductible) {
    int cycle_pass = deductible.size_;
    int new_size = size_;
    if (deductible.size_ > size_) {
        new_size = deductible.size_;
        //cycle_pass = size_;
    }
    extend(new_size);
    for (int i = 0; i < cycle_pass; i++) {
        elements_[i] -= deductible.elements_[i];
    }
}

void Vector::multiply(int multiplier) {
    for (int i = 0; i < size_; i++) {
        elements_[i] *= multiplier;
    }
}

void Vector::divide(int divider) {
    if (divider == 0) { throw std::invalid_argument("[ERROR] Division by zero"); }
    for (int i = 0; i < size_; i++) {
        elements_[i] /= divider;
    }
}

Vector Vector::cut(int start, int size) const {
    if (start + size > size_ || size < 0 || start < 0) { throw std::invalid_argument("[ERROR] Invalid parameters!"); }
    Vector new_vector;
    new_vector.size_ = size;
    new_vector.elements_ = new int[size];
    for (int i = 0; i < size; i++) {
        new_vector.elements_[i] = elements_[start + i];
    }
    return new_vector;
}

void Vector::add(int new_element) {
    extend(size_ + 1);
    elements_[size_ - 1] = new_element;
}

void Vector::qSort(int start, int end, int *mas, bool reverse) {
    int right = end;
    int left = start;
    int pivot = mas[(right + left) / 2];
    while (left <= right) {
        if (!reverse) { while (mas[left] < pivot) { left++; }}
        else { while (mas[left] > pivot) { left++; }}
        if (!reverse) { while (mas[right] > pivot) { right--; }}
        else { while (mas[right] < pivot) { right--; }}
        if (left <= right) {
            int tmp = mas[left];
            mas[left] = mas[right];
            mas[right] = tmp;
            right--;
            left++;
        }
    }
    if (start < right) { qSort(start, right, mas, reverse); }
    if (end > left) { qSort(left, end, mas, reverse); }
}

void Vector::sort(bool reverse) {
    if (size_ == 0) { return; }
    qSort(0, size_ - 1, elements_, reverse);
}

int Vector::getMax() const {
    if (size_ == 0) { throw std::length_error("[ERROR] Vector is empty!"); }
    int max = elements_[0];
    for (int i = 0; i < size_; i++) {
        if (max < elements_[i]) { max = elements_[i]; }
    }
    return max;
}

int Vector::getMin() const {
    if (size_ == 0) { throw std::length_error("[ERROR] Vector is empty!"); }
    int min = elements_[0];
    for (int i = 0; i < size_; i++) {
        if (min > elements_[i]) { min = elements_[i]; }
    }
    return min;
}

void Vector::clear() {
    delete[] elements_;
    elements_ = nullptr;
    size_ = 0;
}

Vector HypexVector::operator+(const Vector &v1, const Vector &v2) {
    Vector result(v1);
    result.summarize(v2);
    return result;
}

Vector &HypexVector::Vector::operator+=(const Vector &v1) {
    this->summarize(v1);
    return *this;
}

Vector HypexVector::operator-(const Vector &v1, const Vector &v2) {
    Vector result(v1);
    result.subtract(v2);
    return result;
}

Vector &Vector::operator-=(const Vector &v1) {
    this->subtract(v1);
    return *this;
}

Vector HypexVector::operator*(const Vector &v1, int multiplier) {
    Vector result(v1);
    result.multiply(multiplier);
    return result;
}

Vector &Vector::operator*=(int multiplier) {
    this->multiply(multiplier);
    return *this;
}

Vector HypexVector::operator/(const Vector &v1, int divider) {
    Vector result(v1);
    result.divide(divider);
    return result;
}

Vector &Vector::operator/=(int divider) {
    this->divide(divider);
    return *this;
}
