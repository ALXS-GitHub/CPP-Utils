#ifndef UTILS_STRING_STRING_HPP
#define UTILS_STRING_STRING_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace utils {

    template <typename T>
    string strip(T element, string chars = " ");

    template <typename T>
    string lstrip(T element, string chars = " ");

    template <typename T>
    string rstrip(T element, string chars = " ");

    template <typename T>
    vector<string> split(T element, string delimiter = " ");

    template <typename T, typename... Pos, typename std::enable_if<(std::is_integral<Pos>::value && ...)>::type * = nullptr>
    vector<string> split(T element, Pos... positions);

    template <typename T>
    vector<string> split_first(T element, string delimiter = " ");

    template <typename T>
    vector<string> split_last(T element, string delimiter = " ");

    template <typename T>
    long long int count(T element, string sub);

    template <typename T>
    string reverse(T element);

} // namespace utils

#include "string.tpp"

#endif // UTILS_STRING_STRING_HPP
