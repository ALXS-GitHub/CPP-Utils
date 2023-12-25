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

    // & functions

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

    /**
     * @brief print a tuple
     * 
     * @param t tuple : the tuple to print
     * 
    */
    template <size_t I = 0, typename... Ts>
    void print_tuple(const tuple<Ts...> &t);

    /**
     * @brief print a variant
     * 
     * @param v variant : the variant to print
     * 
    */
    template <typename VariantType>
    void print_variant(const VariantType &v);

    /**
     * @brief print an optional
     * 
     * @param o optional : the optional to print
     * 
    */
    template <typename OptionalType>
    void print_optional(const OptionalType &o);

    /**
     * @brief print an any
     * 
     * @param a any : the any to print
    */
    template <typename AnyType>
    void print_any(const AnyType &a);

    /**
     * @brief print any type of element
     * 
     * @param element T : the element to print
     * @example print(1) will print 1
     * @example print("string") will print string
     * @example print(vector<int>{1, 2, 3}) will print [1, 2, 3]
     * 
    */
    template <typename T>
    void print(T element);

    /**
     * @brief print any type of element, with a color
     * 
     * @param element T : the element to print
     * @param color string : the color to use
     * @example print(1, "blue") will print 1 in blue
     * @example print("string", "blue") will print string in blue
     * @example print(vector<int>{1, 2, 3}, "blue") will print [1, 2, 3] in blue
     * 
    */
    template <typename T>
    void print(T element, string color);

    /**
     * @brief print any type of element, with other options
     * 
     * @param element T : the element to print
     * @param kwargs map<string, variant<string, bool>> : the color and other options to use \n
     * the other parameters are : background (string), reset (bool), bold (bool), dim (bool), underline (bool), blink (bool), reverse (bool), hidden (bool), strikethrough (bool)
     * @example print(1, {{"color", "blue"}}) will print 1 in blue
     * @example print("string", {{"bold", true}}) will print string in bold
     * @example print(vector<int>{1, 2, 3}, {{"underline", true}, {"color", "red"}}) will print [1, 2, 3] in red and underlined
     * 
    */
    template <typename T>
    void print(T element, map<string, variant<string, bool>> kwargs);

    /**
     * @brief print multiple elements
     * 
     * @param args Args... : the elements to print
     * @example prints(1, 2, "string", 3.14) will print 1 2 string 3.14
     * 
     * @note this function does not provide any color or other options, you should use the make_color() function before
     * 
    */
    template <typename... Args>
    void prints(Args... args);

    /**
     * @brief print any type of element in line
     * 
     * @param element T : the element to print
     * @example print_in_line(1) followed by print_in_line(2) will print 1 2
     * @example print_in_line("string") followed by print_in_line(3.14) will print string 3.14
    */
    template <typename T>
    void print_in_line(T element);

    /**
     * @brief print any type of element in line, with a color
     * 
     * @param element T : the element to print
     * @param color string : the color to use
     * @example print_in_line(1, "blue") followed by print_in_line(2, "red") will print 1 2 in blue and red
     * @example print_in_line("string", "blue") followed by print_in_line(3.14, "red") will print string 3.14 in blue and red
    */
    template <typename T>
    void print_in_line(T element, string color);

    /**
     * @brief print any type of element in line, with other options
     * 
     * @param element T : the element to print
     * @param kwargs map<string, variant<string, bool>> : the color and other options to use \n
     * the other parameters are : background (string), reset (bool), bold (bool), dim (bool), underline (bool), blink (bool), reverse (bool), hidden (bool), strikethrough (bool)
     * @example print_in_line(1, {{"color", "blue"}}) followed by print_in_line(2, {{"color", "red"}}) will print 1 2 in blue and red
     * @example print_in_line("string", {{"bold", true}}) followed by print_in_line(3.14, {{"bold", true}}) will print string 3.14 in bold
     * @example print_in_line(vector<int>{1, 2, 3}, {{"underline", true}, {"color", "red"}}) followed by print_in_line(vector<int>{4, 5, 6}, {{"underline", true}, {"color", "blue"}}) will print [1, 2, 3] [4, 5, 6] in red and blue and underlined
    */
    template <typename T>
    void print_in_line(T element, map<string, variant<string, bool>> kwargs);

    // TODO: logger() function to keep track of different variables during the execution

} // namespace utils

#include "utils.tpp"
