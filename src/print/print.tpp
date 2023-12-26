#include <iostream>
#include <map>
#include <string>
#include <variant>

using namespace std;

namespace utils {

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

        // % reset
        if (Utils::getInstance()->getAutoReset())
            make_color("reset");
    }

    // µ print with kwargs
    template <typename T>
    void print(T element, map<string, variant<string, bool>> kwargs)
    {
        make_color(kwargs);
        print(element);

        // % reset
        if (Utils::getInstance()->getAutoReset())
            make_color("reset");
    }

    // µ prints (for multiple elements)
    // does not accept kwargs
    template <typename... Args>
    void prints(Args... elements)
    {
        string delimiter = Utils::getInstance()->getDelimiter();
        auto tuple = make_tuple(elements...);
        apply([delimiter](auto &&...args)
              {
        size_t count = 0;
        ((std::cout << args << (++count != sizeof...(args) ? delimiter : "")), ...); },
              tuple);

        cout << endl;

        // % reset
        if (Utils::getInstance()->getAutoReset())
            make_color("reset");
    }

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

        // % reset
        if (Utils::getInstance()->getAutoReset())
            make_color("reset");
    }

    // µ print in line with kwargs
    template <typename T>
    void print_in_line(T element, map<string, variant<string, bool>> kwargs)
    {
        make_color(kwargs);
        print_in_line(element);

        // % reset
        if (Utils::getInstance()->getAutoReset())
            make_color("reset");
    }
}