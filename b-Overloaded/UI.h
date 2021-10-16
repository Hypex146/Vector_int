//
// Created by vlad_ on 14.10.2021.
//

#ifndef LAB_3_OVERLOAD_UI_H
#define LAB_3_OVERLOAD_UI_H

#include "Vector.h"

using namespace HypexLib;

class UI {
private:
    Vector v1_;
    Vector v2_;

    void printMenu();

public:
    UI();

    void run();

};


#endif //LAB_3_OVERLOAD_UI_H
