//
// Created by vlad_ on 14.10.2021.
//

#include "Vector.h"

using namespace HypexLib;

int HypexLib::getLimitedInt(int start, int end, const std::string &errMessage) {
    int result;
    do {
        result = getValueLoop<int>("[ERROR] Try again!");
        if (result < start || result > end) { std::cout << errMessage << std::endl; }
    } while (result < start || result > end);
    return result;
}

Vector::Vector(int element) {
    size_ = 1;
    elements_[0] = element;
}

Vector::Vector(int size, const int *mas) {
    size_ = size;
    for (int i = 0; i < size_; i++) {
        elements_[i] = mas[i];
    }
}

bool Vector::canAdd() const {
    if (size_ < max_size_) { return true; }
    return false;
}

int Vector::getSize() const {
    return size_;
}

void Vector::inputVector() {
    clear();
    std::cout << "Enter the size of the vector (int):" << std::endl;
    int size = getLimitedInt(0, max_size_, "[ERROR] Bad value of size! Try again");
    size_ = size;
    std::cout << "Enter the vector elements (int):" << std::endl;
    for (int i = 0; i < size; i++) {
        int element = getValueLoop<int>("[ERROR] Bad value of element! Try again");
        elements_[i] = element;
    }
    std::cout << "Vector successfully entered!" << std::endl;
}

void Vector::outputVector() {
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

void Vector::sum(const Vector &summand) {
    int cycle_pass = summand.size_;
    if (summand.size_ > size_) {
        size_ = summand.size_;
        cycle_pass = size_;
    }
    for (int i = 0; i < cycle_pass; i++) {
        elements_[i] += summand.elements_[i];
    }
}

Vector Vector::cut(int start, int size) {
    if (start + size > size_ || size < 0 || start < 0) { throw std::invalid_argument("[ERROR] Invalid parameters!"); }
    Vector new_vector;
    new_vector.size_ = size;
    for (int i = 0; i < size; i++) {
        new_vector.elements_[i] = elements_[start + i];
    }
    return new_vector;
}

void Vector::add(int new_element) {
    if (!canAdd()) { throw std::invalid_argument("[ERROR] Vector overflow!"); }
    size_++;
    elements_[size_ - 1] = new_element;
}

void Vector::qSort(int start, int end, int *mas) {
    int right = end;
    int left = start;
    int pivot = mas[(right + left) / 2];
    while (left <= right) {
        while (mas[left] < pivot) { left++; }
        while (mas[right] > pivot) { right--; }
        if (left <= right) {
            int tmp = mas[left];
            mas[left] = mas[right];
            mas[right] = tmp;
            right--;
            left++;
        }
    }
    if (start < right) { qSort(start, right, mas); }
    if (end > left) { qSort(left, end, mas); }
}

void Vector::sortAscending() {
    qSort(0, size_ - 1, elements_);
}

int Vector::getMax() {
    if (size_ == 0) { throw std::invalid_argument("[ERROR] Vector is empty!"); }
    int max = elements_[0];
    for (int i = 0; i < size_; i++) {
        if (max < elements_[i]) { max = elements_[i]; }
    }
    return max;
}

void Vector::clear() {
    for (int i = 0; i < size_; i++) {
        elements_[i] = 0;
    }
    size_ = 0;
}
