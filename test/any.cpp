#include <iostream>
#include "../src/utils.hpp"
#include <any>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <variant>
#include <map>

using namespace std;
using namespace utils;

int main() {

    // & normal print

    any a = 1;
    print_any(a);
    any b = "string";
    print_any(b);
    cout << "this" << endl;

    prints(1, 2, "string", 3.14);

    make_color("blue");
    prints(1, 2, "string", 3.14);
    make_color("reset");


    setDelimiter("-0---0-");
    make_color("green");
    prints(1, 2, "string", 3.14);
    make_color("reset");
    setDelimiter(" ");

    print({1, 4, "string", 3.14}, "-O-", {{"color", "red"}});

    vector<any> v = {1, 2, 3, "string", 3.14};
    prints(v, 9, "s", v);

}