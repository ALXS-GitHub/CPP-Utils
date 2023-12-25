#include <iostream>
#include "../src/utils.hpp"

using namespace std;
using namespace utils;

int main() {

    // & normal print

    print(1);
    print(2);
    print(3, "red");
    print(4, "green");
    print(5);
    print(6, "blue");
    print(7, "yellow");
    print(8);
    print(9, "cyan");
    print(10, "magenta");
    print(11);
    print(12, "white");

    // & print in line

    print_in_line(1);
    print_in_line(2);
    print_in_line(3, "red");
    print_in_line(4, "gReen");
    print_in_line(5);
    print_in_line(6, "blue");
    print_in_line(7, "YeLlow");
    print_in_line(8);
    print_in_line(9, "cyan");
    print_in_line(10, "magenta");
    print_in_line(11);
    print_in_line(12, "white");
    make_color("reset");

    cout << endl;

    print(244, {{"color", "red"}, {"bold", true}, {"underline", true}, {"strikethrough", true}, {"reverse", true}});

    return 0;
}