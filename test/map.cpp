#include <iostream>
#include "../src/utils.hpp"
#include <map>
#include <vector>
#include <list>


using namespace std;
using namespace utils;

int main() {

    // & normal print
    map<string, string> element;
    element["name"] = "John";
    element["surname"] = "Doe";
    element["age"] = "30";
    element["city"] = "New York";
    element["country"] = "USA";

    print(element);
    print(element, "red");
    print(element, {{"color", "red"}, {"bold", true}, {"underline", true}, {"strikethrough", true}, {"reverse", true}});

}