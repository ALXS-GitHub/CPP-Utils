#include <iostream>
#include <chrono>
#include <functional>

using namespace std;

namespace utils {

    template <typename Func, typename... Args>
    auto time(Func func, Args... args) {
        auto start = std::chrono::high_resolution_clock::now();

        func(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        return elapsed.count();
    }

    template <typename Func, typename... Args>
    auto time_and_return(Func func, Args... args) {
        auto start = std::chrono::high_resolution_clock::now();

        auto result = func(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time elapsed: " << elapsed.count() << " seconds" << std::endl;

        return result;
    }

} // namespace utils


