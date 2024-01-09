#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../detail/detail.hpp"

using namespace std;

namespace utils
{

    template <typename T>
    string strip(T element, string chars)
    {
        static_assert(detail::is_string_like<T>::value, "utils::strip() requires a string like type");

        if (chars.length() <= 1 ) {
            string s = string(element);
            s.erase(0, s.find_first_not_of(chars));
            s.erase(s.find_last_not_of(chars) + 1);
            return s;
        } else {
            std::string s = std::string(element);
            size_t pos;
            // Remove from the beginning
            while ((pos = s.find(chars)) == 0)
            {
                s.erase(0, chars.length());
            }
            // Remove from the end
            while ((pos = s.rfind(chars)) != std::string::npos && pos == s.length() - chars.length())
            {
                s.erase(pos, chars.length());
            }
            return s;
        }
    }

    template <typename T>
    string lstrip(T element, string chars)
    {
        static_assert(detail::is_string_like<T>::value, "utils::lstrip() requires a string like type");

        if (chars.length() <= 1 ) {
            string s = string(element);
            s.erase(0, s.find_first_not_of(chars));
            return s;
        } else {
            std::string s = std::string(element);
            size_t pos;
            // Remove from the beginning
            while ((pos = s.find(chars)) == 0)
            {
                s.erase(0, chars.length());
            }
            return s;
        }
    }

    template <typename T>
    string rstrip(T element, string chars)
    {
        static_assert(detail::is_string_like<T>::value, "utils::rstrip() requires a string like type");

        if (chars.length() <= 1 ) {
            string s = string(element);
            s.erase(s.find_last_not_of(chars) + 1);
            return s;
        } else {
            std::string s = std::string(element);
            size_t pos;
            // Remove from the end
            while ((pos = s.rfind(chars)) != std::string::npos && pos == s.length() - chars.length())
            {
                s.erase(pos, chars.length());
            }
            return s;
        }
    }

    template <typename T>
    vector<string> split(T element, string delimiter)
    {
        static_assert(detail::is_string_like<T>::value, "utils::split() requires a string like type");


        string s = string(element);
        vector<string> result;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            result.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        if (s.length() > 0)
            result.push_back(s);
        return result;
    }

    template <typename T, typename... Pos, typename std::enable_if<(std::is_integral<Pos>::value && ...)>::type*>
    vector<string> split(T element, Pos... positions)
    {
        static_assert(detail::is_string_like<T>::value, "utils::split() requires a string like type");

        string s = string(element);
        vector<string> result;
        size_t pos = 0;
        size_t string_length = s.length();

        for (auto position : {positions...})
        {
            if (position < 0)
            {
                position = string_length + position;
            }
            size_t p = position;
            if (position < 0 || p > string_length)
            {
                throw std::out_of_range("utils::split() position out of range");
            }
            if (p < pos)
            {
                throw std::invalid_argument("utils::split() positions must be in ascending order");
            }
            result.push_back(s.substr(pos, position - pos));
            pos = position;
        }
        if (pos < string_length)
            result.push_back(s.substr(pos, string_length - pos));
        return result;
    }

    template <typename T>
    vector<string> split_first(T element, string delimiter)
    {
        static_assert(detail::is_string_like<T>::value, "utils::split_first() requires a string like type");

        string s = string(element);
        vector<string> result;
        size_t pos = 0;
        string token;
        if ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            result.push_back(token);
            s.erase(0, pos + delimiter.length());
        }

        if (s.length() > 0)
            result.push_back(s);

        return result;
    }

    template <typename T>
    vector<string> split_last(T element, string delimiter)
    {
        static_assert(detail::is_string_like<T>::value, "utils::split_last() requires a string like type");

        string s = string(element);
        vector<string> result;
        size_t pos = 0;
        string token;
        if ((pos = s.rfind(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            result.push_back(token);
            s.erase(0, pos + delimiter.length());
        }

        if (s.length() > 0)
            result.push_back(s);

        return result;
    }

    template <typename T>
    long long int count(T element, string sub)
    {
        static_assert(detail::is_string_like<T>::value, "utils::count() requires a string like type");

        string s = string(element);
        long long int count = 0;
        size_t pos = 0;
        while ((pos = s.find(sub, pos)) != string::npos)
        {
            count++;
            pos += sub.length();
        }
        return count;
    }

    template <typename T>
    string reverse(T element)
    {
        static_assert(detail::is_string_like<T>::value, "utils::reverse() requires a string like type");

        string s = string(element);
        std::reverse(s.begin(), s.end());
        return s;
    }

} // namespace utils
