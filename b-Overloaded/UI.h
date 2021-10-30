#ifndef LAB_3_OVERLOAD_UI_H
#define LAB_3_OVERLOAD_UI_H

#include "Vector.h"

using namespace HypexVector;

class UI {
private:
    Vector v1_;
    Vector v2_;

    static int getLimitedInt(int start, int end, const std::string &errMessage);

    static int getLimitedInt(int border, bool isStartBorder, const std::string &errMessage);

    template<typename T>
    static int getValue(T &value) {
        std::cin >> value;
        if (std::cin.fail()) {
            if (std::cin.eof()) { exit(0); }
            std::cin.clear();
            std::cin.ignore();
            return -1;
        }
        return 0;
    }

    template<typename T>
    static T getValueLoop(const std::string &err_message) {
        T value;
        while (getValue<int>(value) != 0) {
            std::cout << err_message << std::endl;
        }
        return value;
    }

    void printMenu();

public:
    UI();

    void run();

};


#endif //LAB_3_OVERLOAD_UI_H
