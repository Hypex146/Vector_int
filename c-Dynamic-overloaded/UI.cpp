#include "UI.h"

void UI::printMenu() {
    std::cout << "0) Exit" << std::endl;
    std::cout << "1) Input v1" << std::endl;
    std::cout << "2) Input v2" << std::endl;
    std::cout << "3) Output v1" << std::endl;
    std::cout << "4) Output v2" << std::endl;
    std::cout << "5) Get size v1" << std::endl;
    std::cout << "6) Get size v2" << std::endl;
    std::cout << "7) v1 = v1 + v2 (+)" << std::endl;
    std::cout << "8) v2 = v2 + v1 (+=)" << std::endl;
    std::cout << "9) v1 = v1 + v1 (+)" << std::endl;
    std::cout << "10) v2 = v2 + v2 (+=)" << std::endl;
    std::cout << "11) CopyN v1" << std::endl;
    std::cout << "12) CopyN v2" << std::endl;
    std::cout << "13) Add v1" << std::endl;
    std::cout << "14) Add v2" << std::endl;
    std::cout << "15) Sort ascending v1" << std::endl;
    std::cout << "16) Sort ascending v2" << std::endl;
    std::cout << "17) Get max v1" << std::endl;
    std::cout << "18) Get max v2" << std::endl;
    std::cout << "19) Clear v1" << std::endl;
    std::cout << "20) Clear v2" << std::endl;
    std::cout << "21) Print element form v1 by index ([])" << std::endl;
    std::cout << "22) Print element form v2 by index ([])" << std::endl;
    std::cout << "23) Print menu" << std::endl;
}

UI::UI() {
    v1_ = Vector();
    v2_ = Vector();
}

void UI::run() {
    printMenu();
    int choice;
    do {
        choice = getLimitedInt(0, 23, "[ERROR] Bad choice!");
        switch (choice) {
            case 1:
                v1_.inputVector(std::cin, std::cout);
                break;
            case 2:
                v2_.inputVector(std::cin, std::cout);
                break;
            case 3:
                std::cout << v1_;
                break;
            case 4:
                std::cout << v2_;
                break;
            case 5:
                std::cout << v1_.getSize() << std::endl;
                break;
            case 6:
                std::cout << v2_.getSize() << std::endl;
                break;
            case 7:
                v1_ = v1_ + v2_;
                break;
            case 8:
                v2_ += v1_;
                break;
            case 9:
                v1_ = v1_ + v1_;
                break;
            case 10:
                v2_ += v2_;
                break;
            case 11: {
                Vector new_v;
                std::cout << "Enter the start index" << std::endl;
                int start = getValueLoop<int>("[ERROR] Bad value of indext!");
                std::cout << "Enter the size" << std::endl;
                int size = getValueLoop<int>("[ERROR] Bad value of size!");
                try {
                    new_v = v1_.copyN(start, size);
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                new_v.outputVector(std::cout);
                break;
            }
            case 12: {
                Vector new_v;
                std::cout << "Enter the start index" << std::endl;
                int start = getValueLoop<int>("[ERROR] Bad value of indext!");
                std::cout << "Enter the size" << std::endl;
                int size = getValueLoop<int>("[ERROR] Bad value of size!");
                try {
                    new_v = v2_.copyN(start, size);
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                new_v.outputVector(std::cout);
                break;
            }
            case 13: {
                std::cout << "Enter the new value" << std::endl;
                int new_value = getValueLoop<int>("[ERROR] Bad value!");
                try {
                    v1_.add(new_value);
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            }
            case 14: {
                std::cout << "Enter the new value" << std::endl;
                int new_value = getValueLoop<int>("[ERROR] Bad value!");
                try {
                    v2_.add(new_value);
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            }
            case 15:
                v1_.sort();
                break;
            case 16:
                v2_.sort();
                break;
            case 17:
                try {
                    std::cout << v1_.getMax() << std::endl;
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            case 18:
                try {
                    std::cout << v2_.getMax() << std::endl;
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            case 19:
                v1_.clear();
                break;
            case 20:
                v2_.clear();
                break;
            case 21: {
                std::cout << "Enter the index of element" << std::endl;
                int index = getValueLoop<int>("[ERROR] Bad index!");
                try {
                    std::cout << v1_[index] << std::endl;
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            }
            case 22: {
                std::cout << "Enter the index of element" << std::endl;
                int index = getValueLoop<int>("[ERROR] Bad index!");
                try {
                    std::cout << v2_[index] << std::endl;
                } catch (std::exception &ex) {
                    std::cerr << ex.what() << std::endl;
                }
                break;
            }
            case 23:
                printMenu();
                break;
            default: {
                return;
            }
        }
    } while (true);
}

int UI::getLimitedInt(int start, int end, const char *err_message) {
    int result;
    do {
        result = getValueLoop<int>("[ERROR] Try again!");
        if (result < start || result > end) { std::cout << err_message << std::endl; }
    } while (result < start || result > end);
    return result;
}

int UI::getLimitedInt(int border, bool isStartBorder, const char *err_message) {
    int result;
    if (isStartBorder) {
        do {
            result = getValueLoop<int>("[ERROR] Try again!");
            if (result < border) { std::cout << err_message << std::endl; }
        } while (result < border);
    } else {
        do {
            result = getValueLoop<int>("[ERROR] Try again!");
            if (result > border) { std::cout << err_message << std::endl; }
        } while (result > border);
    }
    return result;
}
