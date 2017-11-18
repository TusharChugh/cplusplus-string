#include <iostream>
#include <tstring/tstring.h>

int main() {
    tlib::tstring input("test");
    std::cout<<input.c_str()<<std::endl;
    tlib::tstring input1("hello");
    std::cout<<input1.c_str();
    return 0;
}