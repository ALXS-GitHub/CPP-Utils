# CPP Utils Documentation

## Table of contents

- [CPP Utils Documentation](#cpp-utils-documentation)
  - [Table of contents](#table-of-contents)
  - [Starting out](#starting-out)
  - [Functionalities](#functionalities)
    - [Making colored text](#making-colored-text)
      - [Examples](#examples)
    - [Printing](#printing)
      - [Examples](#examples-1)

## Starting out

The functions and classes are contained in the `utils` namespace. For example, to use the `utils::print` function, you would write:

```cpp
#include "utils.hpp"

int main() {
    utils::print("Hello, world!");
    return 0;
}
```

Of course you can also use `using namespace utils;` to avoid writing `utils::` every time.

## Functionalities

### Making colored text

You can use the `utils::make_color` function to make colored text. (see [color.hpp](../src/color/color.hpp) for more details)

```cpp

void make_color(string color);

void make_color(map<string, variant<string, bool>> kwargs);
```

You can either use the `utils::make_color` function with a string as a parameter, or with a map of parameters. The available colors are:

- black
- red
- green
- yellow
- blue
- magenta
- cyan
- white
- reset

The available options are:

- color (string), it can be any of the colors listed above
- background (string), it can be any of the colors listed above
- reset (bool), if true, the output will be reset to the default one
- bold (bool)
- dim (bool)
- underline (bool)
- blink (bool)
- reverse (bool)
- hidden (bool)
- strikethrough (bool)

#### Examples

```cpp
utils::make_color("red");
cout << "This is red text" << endl;
utils::make_color("reset");
cout << "This is default text" << endl;
```

```cpp
utils::make_color({{"color", "blue"}, {"bold", true}});
cout << "This is bold blue text" << endl;
utils::make_color({{"reset", true}});
cout << "This is default text" << endl;
```

### Printing

Isn't it annoying to write `cout << endl` every time you want to print a new line, doing a for loop to print a vector, or even worse, doing a for loop to print a map? Well, you don't have to do that anymore! You can use the `utils::print` function to print text. For example, to print "Hello, world!", you would write:

```cpp
utils::print("Hello, world!");
```

There are multiple ways to use the `utils::print` function (see [print.hpp](../src/print/print.hpp) for more details):

```cpp
template <typename T>
void print(T element);

template <typename T>
void print(T element, string color);

template <typename T>
void print(T element, map<string, variant<string, bool>> kwargs);

void print(list<any> l, string delimiter, map<string, variant<string, bool>> kwargs);

template <typename... Args>
void prints(Args... args);

template <typename T>
void print_in_line(T element);

template <typename T>
void print_in_line(T element, string color);

template <typename T>
void print_in_line(T element, map<string, variant<string, bool>> kwargs);
```

The print function will always print a new line at the end, while the print_in_line function will not. The prints function will print multiple elements in the same line, separated by a space.

Note that the prints function does not support the `color` parameter and the `kwargs` parameter.

As told in the [Making colored text](#making-colored-text) section, you can use the `color` parameter to make colored text. You can also use the `kwargs` parameter to make colored text, but you can also use other options.

#### Examples

```cpp
utils::print("Hello, world!", "blue");
```
Prints "Hello, world!" in blue.

```cpp
utils::print("Hello, world!", {{"color", "blue"}, {"bold", true}});
```
Prints "Hello, world!" in bold blue.


```cpp
utils::print({1, 2, 3, 4, 5}, ", ", {{"color", "blue"}, {"bold", true}});
```
Prints "1, 2, 3, 4, 5" separated by ", " in bold and blue.

```cpp
utils::prints("Hello,", "world!");
```
Prints "Hello, world!".

```cpp
utils::print_in_line("Hello, ");
utils::print_in_line("world!");
```
Prints "Hello, world!".
