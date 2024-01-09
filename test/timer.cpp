#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "../src/utils.hpp"

using namespace std;
using namespace utils;

void function1() {
    cout << "Hello, world!" << endl;
}

void function2(int a) {
    long long int b = 0;
    for (int i = 0; i < a; i++) {
        b++;
    }
}

int function3(int a) {
    long long int b = 0;
    for (int i = 0; i < a; i++) {
        b++;
    }
    return b;
}

vector<int> function4(int a) {
    vector<int> v;
    for (int i = 0; i < a; i++) {
        if (i % 10000000 == 0)
            v.push_back(i);
    }
    return v;
}

void sleep_function(int a) {
    this_thread::sleep_for(chrono::milliseconds(a));
}

int main() {

    cout << "Time elapsed: " << time(function1) << " seconds" << endl;
    cout << "Time elapsed: " << time(function2, 100000000) << " seconds" << endl;
    cout << "Time elapsed: " << time(function3, 100000000) << " seconds" << endl;
    
    prints("Result: ", time_and_return(function3, 100000000));
    prints("Result: ", time_and_return(function4, 100000000));

    for (int i = 0; i < 5; i++) {
        cout << "Time elapsed: " << time(sleep_function, 1000) << " seconds" << endl;
    }

    for (int i = 0; i < 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        sleep_function(1000);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time elapsed: " << elapsed.count() << " seconds" << std::endl;
    }

    return 0;

}