#ifdef __unix__

#include "UnixConsole.h"
#include "Color.h"

#include <cstdlib>
#include <iostream>
#include <unordered_map>

namespace aod {
    UnixConsole::UnixConsole()
    {
    }

    void UnixConsole::SetWindowTitle(const std::string &title)
    {
        std::cout << "\033] << title << \007";
    }

    void UnixConsole::MoveCursor(int x, int y)
    {
        std::cout << "\033[" << y << ";" << x << "H" << std::flush;
    }

    void UnixConsole::SetColor(Color color)
    {
        std::cout << getANSIFgColor(color) << std::flush;
    }

    void UnixConsole::SetColor(Color fgColor, Color bgColor)
    {
        std::cout << getANSIFgColor(fgColor) << std::flush;
        std::cout << getANSIBgColor(bgColor) << std::flush;
    }

    void UnixConsole::ClearScreen()
    {
        std::system("clear");
    }

    void UnixConsole::SetCursorVisibility(bool visibility)
    {
        if (visibility)
        {
            std::cout << "\033[?25h" << std::flush;
        }
        else
        {
            std::cout << "\033[?25l" << std::flush;
        }
    }

    std::string UnixConsole::getANSIFgColor(Color color)
    {
        static const std::unordered_map<Color, std::string> colorMap = {
            {Color::BLACK, "30"},      {Color::BLUE, "34"},        {Color::GREEN, "32"},
            {Color::AQUA, "36"},       {Color::RED, "31"},         {Color::PURPLE, "35"},
            {Color::YELLOW, "33"},     {Color::WHITE, "37"},       {Color::GRAY, "90"},
            {Color::LIGHTBLUE, "94"},  {Color::LIGHTGREEN, "92"},  {Color::LIGHTAQUA, "96"},
            {Color::LIGHTRED, "91"},   {Color::LIGHTPURPLE, "95"}, {Color::LIGHTYELLOW, "93"},
            {Color::BRIGHTWHITE, "97"}};

        auto it = colorMap.find(color);
        if (it == colorMap.end())
        {
            throw std::invalid_argument("Invalid color.");
        }
        return "\033[" + it->second + "m";
    }

    std::string UnixConsole::getANSIBgColor(Color color)
    {
        static const std::unordered_map<Color, std::string> colorMap = {
            {Color::BLACK, "40"},      {Color::BLUE, "44"},        {Color::GREEN, "42"},
            {Color::AQUA, "46"},       {Color::RED, "41"},         {Color::PURPLE, "45"},
            {Color::YELLOW, "43"},     {Color::WHITE, "47"},       {Color::GRAY, "90"},
            {Color::LIGHTBLUE, "94"},  {Color::LIGHTGREEN, "92"},  {Color::LIGHTAQUA, "96"},
            {Color::LIGHTRED, "91"},   {Color::LIGHTPURPLE, "95"}, {Color::LIGHTYELLOW, "93"},
            {Color::BRIGHTWHITE, "97"}};

        auto it = colorMap.find(color);
        if (it == colorMap.end())
        {
            throw std::invalid_argument("Invalid color.");
        }
        return "\033[" + it->second + "m";
    }

} // namespace aod

#endif
