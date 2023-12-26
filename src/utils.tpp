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

#include "./detail/detail.hpp"
#include "./color/color.hpp"

using namespace std;

namespace utils
{

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

    bool Utils::getAutoReset()
    {
        return auto_reset;
    }

    void Utils::setAutoReset(bool auto_reset)
    {
        this->auto_reset = auto_reset;
    }

    string Utils::getDelimiter()
    {
        return delimiter;
    }

    void Utils::setDelimiter(string delimiter)
    {
        this->delimiter = delimiter;
    }

    // & Utils class settings functions

    void setAutoReset(bool auto_reset)
    {
        Utils::getInstance()->setAutoReset(auto_reset);
    }

    void setDelimiter(string delimiter)
    {
        Utils::getInstance()->setDelimiter(delimiter);
    }
}
