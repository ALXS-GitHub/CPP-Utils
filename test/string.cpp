#include <iostream>
#include <vector>
#include <string>

#include "../src/utils.hpp"

using namespace std;
using namespace utils;

int main()
{
    string s = "Hello World";
    vector<string> v = split(s);
    print(v);

    char c[] = "Hello World";
    vector<string> v2 = split(c);
    print(v2);

    char *c2 = "Hello World";
    vector<string> v3 = split(c2);
    print(v3);

    const char *c3 = "Hello World";
    vector<string> v4 = split(c3);
    print(v4);

    string s2 = "a, b, c, d";
    vector<string> v5 = split(s2, ", ");
    print(v5);

    string s3 = "a -- b -- c -- d";
    vector<string> v6 = split(s3, " -- ");
    print(v6);
    vector<string> v7 = split(s3, "--");
    print(v7);

    string s4 = "a, b, c, d";
    vector<string> v8 = split_first(s4, ", ");
    print(v8);

    string s5 = "a -- b -- c -- d";
    vector<string> v9 = split_first(s5, " -- ");
    print(v9);

    string s6 = "a, b, c, d";
    vector<string> v10 = split_last(s6, ", ");
    print(v10);

    string s7 = "a -- b -- c -- d";
    vector<string> v11 = split_last(s7, " -- ");
    print(v11);

    string s8 = "  Hello World  ";
    string s9 = strip(s8);
    cout << s9 << endl;

    string s10 = "--- Hello World ---";
    string s11 = strip(s10, "-");
    cout << s11 << endl;

    string s12 = "--- Hello World ---";
    string s13 = strip(s12, "--");
    cout << s13 << endl;

    char* c4 = "  Hello World  ";
    string s14 = strip(c4);
    cout << s14 << endl;

    char c5[] = "  Hello World  ";
    string s15 = strip(c5);
    cout << s15 << endl;

    string s16 = "  Hello World  ";
    vector<string> v12 = split(s16, 1, 3, 6, 9);
    print(v12);

    return 0;
}