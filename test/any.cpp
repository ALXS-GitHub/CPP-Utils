#include <iostream>
#include "../src/utils.hpp"
#include <any>

using namespace std;
using namespace utils;

int main() {

    // & normal print

    any a = 1;
    print_any(a);
    any b = "string";
    print_any(b);
    cout << "this" << endl;
}