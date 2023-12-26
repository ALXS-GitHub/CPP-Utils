#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <vector>
#include <map>
#include <variant>
#include <any>
#include <list>



using namespace std;

namespace utils
{
    // & Utils class (mainly for settings and shared stuff)
    class Utils
    {
    private:
        static Utils *instance;
        bool auto_reset = true;
        string delimiter = " ";
        Utils(); // in private to avoid multiple instances
        ~Utils();

    public:
        static Utils *getInstance();
        bool getAutoReset();
        void setAutoReset(bool auto_reset);
        string getDelimiter();
        void setDelimiter(string delimiter);
    };

    // & Utils class settings functions

    /**
     * @brief set the reset to be done automatically after each print
     * 
     * @param auto_reset bool : the value to set
     * 
    */
    void setAutoReset(bool auto_reset);

    /**
     * @brief set the delimiter to be used between each element
     * 
     * @param delimiter string : the value of the delimiter
     * @example setDelimiter(" - ") will print "1 - 2 - 3"
     * @note the default value is " "
     * @note the delimiter is mainly used in the prints() function
     * 
    */
    void setDelimiter(string delimiter);

    // TODO: logger() function to keep track of different variables during the execution

} // namespace utils

// ! the order of the includes is important
#include "./detail/detail.hpp"
#include "./color/color.hpp"
#include "./print/print.hpp"
#include "utils.tpp"

#endif // UTILS_HPP