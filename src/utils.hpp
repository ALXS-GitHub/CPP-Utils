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
        Utils(); // in private to avoid multiple instances
        ~Utils();

    public:
        static Utils *getInstance();
    };

    // & functions

    void make_color(string color);

    void make_color(map<string, variant<string, bool>> kwargs);

    template <size_t I = 0, typename... Ts>
    void print_tuple(const tuple<Ts...> &t);

    template <typename VariantType>
    void print_variant(const VariantType &v);

    template <typename OptionalType>
    void print_optional(const OptionalType &o);

    template <typename AnyType>
    void print_any(const AnyType &a);

    template <typename T>
    void print(T element);

    template <typename T>
    void print(T element, string color);

    template <typename T>
    void print(T element, map<string, variant<string, bool>> kwargs);

    // void print(list<any> elements, map<string, variant<string, bool>> kwargs);

    template <typename T>
    void print_in_line(T element);

    template <typename T>
    void print_in_line(T element, string color);

    template <typename T>
    void print_in_line(T element, map<string, variant<string, bool>> kwargs);

    // TODO: logger() function to keep track of different variables during the execution

} // namespace utils

#include "utils.tpp"
