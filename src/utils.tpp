#include <iostream>
#include <type_traits>
#include <vector>
#include <map>
#include <iomanip>
#include <list>
#include <unordered_map>
#include <deque>
#include <forward_list>
#include <array>
#include <set>
#include <unordered_set>
#include <string>
#include <tuple>
#include <variant>
#include <optional>
#include <any>

using namespace std;

namespace utils
{

    // & detail nested namespace (for internal use only)

    namespace detail
    {
        // µ is_string_like

        template <typename T>
        struct is_string_like : std::false_type
        {
        };

        template <typename CharT, typename Traits, typename Alloc>
        struct is_string_like<std::basic_string<CharT, Traits, Alloc>> : std::true_type
        {
        };

        template <typename CharT, typename Traits>
        struct is_string_like<std::basic_string_view<CharT, Traits>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<std::basic_string<CharT>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<std::basic_string_view<CharT>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<CharT *> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<const CharT *> : std::true_type
        {
        };

        // µ is_vector_like
        template <typename T>
        struct is_vector_like : std::false_type
        {
        };

        template <typename T, typename Alloc>
        struct is_vector_like<std::vector<T, Alloc>> : std::true_type
        {
        };

        template <typename T, typename Alloc>
        struct is_vector_like<std::deque<T, Alloc>> : std::true_type
        {
        };

        template <typename T, std::size_t N>
        struct is_vector_like<std::array<T, N>> : std::true_type
        {
        };

        // µ is_list_like

        template <typename T>
        struct is_list_like : std::false_type
        {
        };

        template <typename T, typename Alloc>
        struct is_list_like<std::list<T, Alloc>> : std::true_type
        {
        };

        template <typename T, typename Alloc>
        struct is_list_like<std::forward_list<T, Alloc>> : std::true_type
        {
        };

        // µ is_map_like

        template <typename T>
        struct is_map_like : std::false_type
        {
        };

        template <typename Key, typename T, typename Compare, typename Alloc>
        struct is_map_like<std::map<Key, T, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Compare, typename Alloc>
        struct is_map_like<std::multimap<Key, T, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
        struct is_map_like<std::unordered_map<Key, T, Hash, Pred, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
        struct is_map_like<std::unordered_multimap<Key, T, Hash, Pred, Alloc>> : std::true_type
        {
        };

        // µ is_set_like

        template <typename T>
        struct is_set_like : std::false_type
        {
        };

        template <typename Key, typename Compare, typename Alloc>
        struct is_set_like<std::set<Key, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Compare, typename Alloc>
        struct is_set_like<std::multiset<Key, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Hash, typename Pred, typename Alloc>
        struct is_set_like<std::unordered_set<Key, Hash, Pred, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Hash, typename Pred, typename Alloc>
        struct is_set_like<std::unordered_multiset<Key, Hash, Pred, Alloc>> : std::true_type
        {
        };

        // µ is_tuple_like

        template <typename T>
        struct is_tuple_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::tuple<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::pair<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::variant<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::optional<Args...>> : std::true_type
        {
        };

        // µ is_variant_like

        template <typename T>
        struct is_variant_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_variant_like<std::variant<Args...>> : std::true_type
        {
        };

        // µ is_optional_like

        template <typename T>
        struct is_optional_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_optional_like<std::optional<Args...>> : std::true_type
        {
        };

        // µ is_any_like

        template <typename T>
        struct is_any_like : std::false_type
        {
        };

        template <>
        struct is_any_like<std::any> : std::true_type
        {
        };

    } // namespace detail

    // & Utils class

    Utils::Utils()
    {
    }

    Utils::~Utils()
    {
    }

    Utils *Utils::instance = 0;

    Utils *Utils::getInstance()
    {
        if (instance == 0)
        {
            instance = new Utils();
        }
        return instance;
    }

    // & functions

    // µ make color
    void make_color(string color)
    {
        make_color({{"color", color}});
    }

    // µ make color with kwargs
    void make_color(map<string, variant<string, bool>> kwargs)
    {
        string color_code = "\033[";
        bool colon = false;
        // $ reset
        if (kwargs.find("reset") != kwargs.end())
        {
            bool reset;
            try {
                reset = get<bool>(kwargs["reset"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Reset must be a boolean" << endl;
                return;
            }
            if (reset)
            {
                cout << "\033[0m";
                return;
            }
        }
        // $ color
        if (kwargs.find("color") != kwargs.end())
        {
            string color;
            try {
                color = get<string>(kwargs["color"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Color must be a string" << endl;
                return;
            }
            for (size_t i = 0; i < color.size(); i++)
            {
                color[i] = tolower(color[i]);
            }
            if (color == "reset")
            {
                cout << "\033[0m";
                return;
            }
            if (color == "black")
            {
                color_code += "30";
                colon = true;
            }
            else if (color == "red")
            {
                color_code += "31";
                colon = true;
            }
            else if (color == "green")
            {
                color_code += "32";
                colon = true;
            }
            else if (color == "yellow")
            {
                color_code += "33";
                colon = true;
            }
            else if (color == "blue")
            {
                color_code += "34";
                colon = true;
            }
            else if (color == "magenta")
            {
                color_code += "35";
                colon = true;
            }
            else if (color == "cyan")
            {
                color_code += "36";
                colon = true;
            }
            else if (color == "white")
            {
                color_code += "37";
                colon = true;
            }
            else
            {
                cout << "Invalid Color" << endl;
                return;
            }
        }
        // $ background
        if (kwargs.find("background") != kwargs.end())
        {
            string background;
            try {
                background = get<string>(kwargs["background"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Background must be a string" << endl;
                return;
            }
            for (size_t i = 0; i < background.size(); i++)
            {
                background[i] = tolower(background[i]);
            }
            if (background == "black")
            {
                if (colon)
                    color_code += ";";
                color_code += "40";
                colon = true;
            }
            else if (background == "red")
            {
                if (colon)
                    color_code += ";";
                color_code += "41";
                colon = true;
            }
            else if (background == "green")
            {
                if (colon)
                    color_code += ";";
                color_code += "42";
                colon = true;
            }
            else if (background == "yellow")
            {
                if (colon)
                    color_code += ";";
                color_code += "43";
                colon = true;
            }
            else if (background == "blue")
            {
                if (colon)
                    color_code += ";";
                color_code += "44";
                colon = true;
            }
            else if (background == "magenta")
            {
                if (colon)
                    color_code += ";";
                color_code += "45";
                colon = true;
            }
            else if (background == "cyan")
            {
                if (colon)
                    color_code += ";";
                color_code += "46";
                colon = true;
            }
            else if (background == "white")
            {
                if (colon)
                    color_code += ";";
                color_code += "47";
                colon = true;
            }
            else
            {
                cout << "Invalid Background" << endl;
                return;
            }
        }
        // $ bold, bright
        if (kwargs.find("bold") != kwargs.end())
        {
            bool bold;
            try {
                bold = get<bool>(kwargs["bold"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Bold must be a boolean" << endl;
                return;
            }
            if (bold)
            {
                if (colon)
                    color_code += ";";
                color_code += "1";
                colon = true;
            }
        } else if (kwargs.find("bright") != kwargs.end())
        {
            bool bright;
            try {
                bright = get<bool>(kwargs["bright"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Bright must be a boolean" << endl;
                return;
            }
            if (bright)
            {
                if (colon)
                    color_code += ";";
                color_code += "1";
                colon = true;
            }
        }
        // $ dim
        if (kwargs.find("dim") != kwargs.end())
        {
            bool dim;
            try {
                dim = get<bool>(kwargs["dim"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Dim must be a boolean" << endl;
                return;
            }
            if (dim)
            {
                if (colon)
                    color_code += ";";
                color_code += "2";
                colon = true;
            }
        }
        // $ underline
        if (kwargs.find("underline") != kwargs.end())
        {
            bool underline;
            try {
                underline = get<bool>(kwargs["underline"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Underline must be a boolean" << endl;
                return;
            }
            if (underline)
            {
                if (colon)
                    color_code += ";";
                color_code += "4";
                colon = true;
            }
        }
        // $ blink
        if (kwargs.find("blink") != kwargs.end())
        {
            bool blink;
            try {
                blink = get<bool>(kwargs["blink"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Blink must be a boolean" << endl;
                return;
            }
            if (blink)
            {
                if (colon)
                    color_code += ";";
                color_code += "5";
                colon = true;
            }
        }
        // $ reverse
        if (kwargs.find("reverse") != kwargs.end())
        {
            bool reverse;
            try {
                reverse = get<bool>(kwargs["reverse"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Reverse must be a boolean" << endl;
                return;
            }
            if (reverse)
            {
                if (colon)
                    color_code += ";";
                color_code += "7";
                colon = true;
            }
        }
        // $ hidden
        if (kwargs.find("hidden") != kwargs.end())
        {
            bool hidden;
            try {
                hidden = get<bool>(kwargs["hidden"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Hidden must be a boolean" << endl;
                return;
            }
            if (hidden)
            {
                if (colon)
                    color_code += ";";
                color_code += "8";
                colon = true;
            }
        }
        // $ strikethrough
        if (kwargs.find("strikethrough") != kwargs.end())
        {
            bool strikethrough;
            try {
                strikethrough = get<bool>(kwargs["strikethrough"]);
            }
            catch (const std::bad_variant_access& e) {
                cout << "Strikethrough must be a boolean" << endl;
                return;
            }
            if (strikethrough)
            {
                if (colon)
                    color_code += ";";
                color_code += "9";
                colon = true;
            }
        }
        color_code += "m";
        cout << color_code;
    }

    // µ print tuple
    template <size_t I, typename... Ts>
    void print_tuple(const tuple<Ts...> &t)
    {
        if constexpr (I < sizeof...(Ts))
        {
            print_in_line(get<I>(t));
            if constexpr (I != sizeof...(Ts) - 1)
                cerr << ", ";
            print_tuple<I + 1>(t);
        }
    }

    // µ print variant
    template <typename VariantType>
    void print_variant(const VariantType &v)
    {
        std::visit([](auto &&arg)
                   { std::cout << arg; },
                   v);
    }

    // µ print optional
    template <typename OptionalType>
    void print_optional(const OptionalType &o)
    {
        if (o.has_value())
        {
            cout << o.value();
        }
        // TODO add a parameter to print None if the optional is empty
        // else
        // {
        //     cout << "None";
        // }
    }

    // µ print any
    template <typename AnyType>
    void print_any(const AnyType &a)
    {
        if (a.has_value())
        {
            // $ arithmetic
            if (a.type() == typeid(int))
                print_in_line(any_cast<int>(a));
            else if (a.type() == typeid(float))
                print_in_line(any_cast<float>(a));
            else if (a.type() == typeid(double))
                print_in_line(any_cast<double>(a));
            else if (a.type() == typeid(bool))
                print_in_line(any_cast<bool>(a));
            else if (a.type() == typeid(long int))
                print_in_line(any_cast<long int>(a));
            else if (a.type() == typeid(long long int))
                print_in_line(any_cast<long long int>(a));
            else if (a.type() == typeid(unsigned int))
                print_in_line(any_cast<unsigned int>(a));
            else if (a.type() == typeid(unsigned long int))
                print_in_line(any_cast<unsigned long int>(a));
            else if (a.type() == typeid(unsigned long long int))
                print_in_line(any_cast<unsigned long long int>(a));
            else if (a.type() == typeid(unsigned char))
                print_in_line(any_cast<unsigned char>(a));
            else if (a.type() == typeid(unsigned short int))
                print_in_line(any_cast<unsigned short int>(a));
            else if (a.type() == typeid(unsigned long long int))
                print_in_line(any_cast<unsigned long long int>(a));
            else if (a.type() == typeid(long double))
                print_in_line(any_cast<long double>(a));
            else if (a.type() == typeid(short int))
                print_in_line(any_cast<short int>(a));
            else if (a.type() == typeid(signed char))
                print_in_line(any_cast<signed char>(a));
            else if (a.type() == typeid(wchar_t))
                print_in_line(any_cast<wchar_t>(a));
            else if (a.type() == typeid(char16_t))
                print_in_line(any_cast<char16_t>(a));
            else if (a.type() == typeid(char32_t))
                print_in_line(any_cast<char32_t>(a));
            else if (a.type() == typeid(unsigned short int))
                print_in_line(any_cast<unsigned short int>(a));
            else if (a.type() == typeid(std::nullptr_t))
                print_in_line(any_cast<std::nullptr_t>(a));
            else if (a.type() == typeid(std::byte))
                print_in_line(any_cast<std::byte>(a));
            else if (a.type() == typeid(std::any))
                print_in_line(any_cast<std::any>(a));
            else if (a.type() == typeid(std::monostate))
                print_in_line(any_cast<std::monostate>(a));
            // $ string
            else if (a.type() == typeid(string))
                print_in_line(any_cast<string>(a));
            else if (a.type() == typeid(char *))
                print_in_line(any_cast<char *>(a));
            else if (a.type() == typeid(const char *))
                print_in_line(any_cast<const char *>(a));
            else if (a.type() == typeid(char))
                print_in_line(any_cast<char>(a));
            else if (a.type() == typeid(char32_t))
                print_in_line(any_cast<char32_t>(a));
            else if (a.type() == typeid(char16_t))
                print_in_line(any_cast<char16_t>(a));
            else if (a.type() == typeid(wchar_t))
                print_in_line(any_cast<wchar_t>(a));
            else if (a.type() == typeid(std::string_view))
                print_in_line(any_cast<std::string_view>(a));
            // $ vector
            // TODO later
            else
                cout << "Type not supported" << endl;
        }
    }

    // µ main print function
    template <typename T>
    void print(T element)
    {
        if constexpr (is_arithmetic<T>::value)
        {
            cout << element << endl;
        }
        else if constexpr (detail::is_string_like<T>::value)
        {
            cout << element << endl;
        }
        else if constexpr (detail::is_vector_like<T>::value)
        {
            cout << "[";
            for (size_t i = 0; i < element.size(); i++)
            {
                print_in_line(element[i]);
                if (i != element.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
        else if constexpr (detail::is_list_like<T>::value)
        {
            cout << "[";
            size_t counter = 0;
            for (auto e : element)
            {
                print_in_line(e);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "]" << endl;
        }
        else if constexpr (detail::is_map_like<T>::value)
        {
            cout << "{";
            size_t counter = 0;
            for (auto [k, v] : element)
            {
                print_in_line(k);
                cout << ": ";
                print_in_line(v);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "}" << endl;
        }
        else if constexpr (detail::is_set_like<T>::value)
        {
            cout << "{";
            size_t counter = 0;
            for (auto e : element)
            {
                print_in_line(e);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "}" << endl;
        }
        else if constexpr (detail::is_tuple_like<T>::value)
        {
            cout << "(";
            print_tuple(element);
            cout << ")" << endl;
        }
        else if constexpr (detail::is_variant_like<T>::value)
        {
            print_variant(element);
            cout << endl;
        }
        else if constexpr (detail::is_optional_like<T>::value)
        {
            print_optional(element);
            cout << endl;
        }
        else if constexpr (detail::is_any_like<T>::value)
        {
            print_any(element);
            cout << endl;
        }
        else
        {
            cout << "Type not supported" << endl;
        }
    }

    // µ print with color
    template <typename T>
    void print(T element, string color)
    {
        make_color(color);
        print(element);
        make_color("reset");
    }

    // µ print with kwargs
    template <typename T>
    void print(T element, map<string, variant<string, bool>> kwargs)
    {
        make_color(kwargs);
        print(element);
        make_color("reset");
    }

    // void print(list<any> elements, map<string, variant<string, bool>> kwargs)
    // {
    //     make_color(kwargs);
    //     size_t counter = 0;
    //     for (auto e : elements)
    //     {
    //         print_in_line(e);
    //         if (counter != elements.size() - 1)
    //         {
    //             cout << ", ";
    //         }
    //         counter++;
    //     }
    //     cout << endl;
    //     make_color("reset");
    // }

    // µ print in line main function
    template <typename T>
    void print_in_line(T element)
    {
        if constexpr (is_arithmetic<T>::value)
        {
            cout << element;
        }
        else if constexpr (detail::is_string_like<T>::value)
        {
            cout << element;
        }
        else if constexpr (detail::is_vector_like<T>::value)
        {
            cout << "[";
            for (size_t i = 0; i < element.size(); i++)
            {
                print_in_line(element[i]);
                if (i != element.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]";
        }
        else if constexpr (detail::is_list_like<T>::value)
        {
            cout << "[";
            size_t counter = 0;
            for (auto e : element)
            {
                print_in_line(e);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "]";
        }
        else if constexpr (detail::is_map_like<T>::value)
        {
            cout << "{";
            size_t counter = 0;
            for (auto [k, v] : element)
            {
                print_in_line(k);
                cout << ": ";
                print_in_line(v);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "}";
        }
        else if constexpr (detail::is_set_like<T>::value)
        {
            cout << "{";
            size_t counter = 0;
            for (auto e : element)
            {
                print_in_line(e);
                if (counter != element.size() - 1)
                {
                    cout << ", ";
                }
                counter++;
            }
            cout << "}";
        }
        else if constexpr (detail::is_tuple_like<T>::value)
        {
            cout << "(";
            print_tuple(element);
            cout << ")";
        }
        else if constexpr (detail::is_variant_like<T>::value)
        {
            print_variant(element);
        }
        else if constexpr (detail::is_optional_like<T>::value)
        {
            print_optional(element);
        }
        else if constexpr (detail::is_any_like<T>::value)
        {
            print_any(element);
        }
        else
        {
            cout << "Type not supported" << endl;
        }
    }

    // µ print in line with color
    template <typename T>
    void print_in_line(T element, string color)
    {
        make_color(color);
        print_in_line(element);
        make_color("reset");
    }

    // µ print in line with kwargs
    template <typename T>
    void print_in_line(T element, map<string, variant<string, bool>> kwargs)
    {
        make_color(kwargs);
        print_in_line(element);
        make_color("reset");
    }
}
