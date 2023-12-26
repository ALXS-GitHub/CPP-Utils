#ifndef UTILS_COLOR_COLOR_HPP
#define UTILS_COLOR_COLOR_HPP
#include <iostream>
#include <map>
#include <string>
#include <variant>

using namespace std;

namespace utils {
    /**
     * @brief set up the color for further prints
     *
     * @param color string : the color to use
     * @example make_color("blue") will print the next elements in blue
     * @example make_color("reset") will reset the color to the default one
     *
     */
    void make_color(string color);

    /**
     * @brief set up the color for further prints, with other options
     *
     * @param kwargs map<string, variant<string, bool>> : the color and other options to use \n
     * the other parameters are : background (string), reset (bool), bold (bool), dim (bool), underline (bool), blink (bool), reverse (bool), hidden (bool), strikethrough (bool)
     * @example make_color({{"color", "blue"}}) will print the next elements in blue
     *
     */
    void make_color(map<string, variant<string, bool>> kwargs);
}

#include "color.tpp"

#endif // UTILS_COLOR_COLOR_HPP