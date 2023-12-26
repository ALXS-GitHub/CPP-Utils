#include <iostream>
#include <map>
#include <string>
#include <variant>

using namespace std;

namespace utils {
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
            try
            {
                reset = get<bool>(kwargs["reset"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                color = get<string>(kwargs["color"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                background = get<string>(kwargs["background"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                bold = get<bool>(kwargs["bold"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
        }
        else if (kwargs.find("bright") != kwargs.end())
        {
            bool bright;
            try
            {
                bright = get<bool>(kwargs["bright"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                dim = get<bool>(kwargs["dim"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                underline = get<bool>(kwargs["underline"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                blink = get<bool>(kwargs["blink"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                reverse = get<bool>(kwargs["reverse"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                hidden = get<bool>(kwargs["hidden"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
            try
            {
                strikethrough = get<bool>(kwargs["strikethrough"]);
            }
            catch (const std::bad_variant_access &e)
            {
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
}