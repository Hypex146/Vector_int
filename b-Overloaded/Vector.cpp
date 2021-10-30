#include "Vector.h"

using namespace HypexVector;

int Vector::getLimitedInt(int start, int end,
                          const std::string &errMessage, std::istream &istream, std::ostream &ostream) {
    int result;
    do {
        result = getValueLoop<int>("[ERROR] Try again!", istream, ostream);
        if (result < start || result > end) { ostream << errMessage << std::endl; }
    } while (result < start || result > end);
    return result;
}

int Vector::getLimitedInt(int border, bool isStartBorder,
                          const std::string &errMessage, std::istream &istream, std::ostream &ostream) {
    int result;
    if (isStartBorder) {
        do {
            result = getValueLoop<int>("[ERROR] Try again!", istream, ostream);
            if (result < border) { ostream << errMessage << std::endl; }
        } while (result < border);
    } else {
        do {
            result = getValueLoop<int>("[ERROR] Try again!", istream, ostream);
            if (result > border) { ostream << errMessage << std::endl; }
        } while (result > border);
    }
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

void Vector::inputVector(std::istream &istream, std::ostream &ostream) {
    clear();
    ostream << "Enter the size of the vector (int):" << std::endl;
    int size = getLimitedInt(0, max_size_,
                             "[ERROR] Bad value of size! Try again", istream, ostream);
    size_ = size;
    ostream << "Enter the vector elements (int):" << std::endl;
    for (int i = 0; i < size; i++) {
        int element = getValueLoop<int>("[ERROR] Bad value of element! Try again",
                                        istream, ostream);
        elements_[i] = element;
    }
    ostream << "Vector successfully entered!" << std::endl;
}

void Vector::outputVector(std::ostream &ostream) const {
    ostream << "{";
    for (int i = 0; i < size_; i++) {
        if (i != size_ - 1) {
            ostream << elements_[i] << ", ";
        } else {
            ostream << elements_[i];
        }
    }
    ostream << "}" << std::endl;
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

Vector Vector::copyN(int start, int size) const {
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
    if (size_ == 0) { return; }
    qSort(0, size_ - 1, elements_);
}

int Vector::getMax() const {
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

Vector HypexVector::operator+(const Vector &v1, const Vector &v2) {
    Vector result(v1);
    result.sum(v2);
    return result;
}

Vector &Vector::operator+=(const Vector &v1) {
    this->sum(v1);
    return *this;
}

std::ostream &HypexVector::operator<<(std::ostream &stream, const Vector &vector) {
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

std::istream &HypexVector::operator>>(std::istream &stream, Vector &vector) {
    vector.clear();
    int new_size;
    int new_element;
    stream >> new_size;
    if (!stream.good()) { throw std::runtime_error("Bad input"); }
    for (int i = 0; i < new_size; i++) {
        stream >> new_element;
        if (!stream.good()) { throw std::runtime_error("Bad input"); }
        vector.add(new_element);
    }
    return stream;
}

Vector &Vector::operator-() {
    for (int i = 0; i < size_; i++) {
        elements_[i] = -elements_[i];
    }
    return *this;
}

int Vector::operator[](int index) {
    if (index >= size_ || index < 0) { throw std::invalid_argument("[ERROR] Out of range!"); }
    return elements_[index];
}
