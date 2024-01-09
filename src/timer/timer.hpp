#ifndef UTILS_TIMER_TIMER_HPP
#define UTILS_TIMER_TIMER_HPP

#include <iostream>
#include <chrono>
#include <string>
#include <functional>

using namespace std;

namespace utils {

    template <typename Func, typename... Args>
    auto time(Func func, Args... args);

    template <typename Func, typename... Args>
    auto time_and_return(Func func, Args... args);

} // namespace utils

#include "timer.tpp"

#endif // UTILS_TIMER_TIMER_HPP