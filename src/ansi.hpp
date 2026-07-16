#pragma once
#include <string>

namespace ansi
{
    // color normal foreground
    constexpr const char* black = "\033[30m";
    constexpr const char* red = "\033[31m";
    constexpr const char* green = "\033[32m";
    constexpr const char* yellow = "\033[33m";
    constexpr const char* blue = "\033[34m";
    constexpr const char* magenta = "\033[35m";
    constexpr const char* cyan = "\033[36m";
    constexpr const char* white = "\033[37m";

    // color bright foreground
    constexpr const char* bright_black = "\033[90m";
    constexpr const char* bright_red = "\033[91m";
    constexpr const char* bright_green = "\033[92m";
    constexpr const char* bright_yellow = "\033[93m";
    constexpr const char* bright_blue = "\033[94m";
    constexpr const char* bright_magenta = "\033[95m";
    constexpr const char* bright_cyan = "\033[96m";
    constexpr const char* bright_white = "\033[97m";

    // color normal background
    constexpr const char* bg_black = "\033[40m";
    constexpr const char* bg_red = "\033[41m";
    constexpr const char* bg_green = "\033[42m";
    constexpr const char* bg_yellow = "\033[43m";
    constexpr const char* bg_blue = "\033[44m";
    constexpr const char* bg_magenta = "\033[45m";
    constexpr const char* bg_cyan = "\033[46m";
    constexpr const char* bg_white = "\033[47m";

    // text style
    constexpr const char* bold = "\033[1m";
    constexpr const char* dim = "\033[2m";
    constexpr const char* italic = "\033[3m";
    constexpr const char* underline = "\033[4m";
    constexpr const char* inverse = "\033[7m";
    constexpr const char* strike_through = "\033[9m";

    // cursor position
    inline std::string move(int row, int col)
    {
        return "\033[" + std::to_string(row) + ";" 
                       + std::to_string(col) + "H";
    }

    // clear 
    constexpr const char* clear_screen = "\033[2J\033[H";
    constexpr const char* clear_line = "\033[2K";
    constexpr const char* hide_cursor = "\033[?25l";
    constexpr const char* show_cursor = "\033[?25h";
    constexpr const char* home = "\033[H";

    // alternate screen
    constexpr const char* alt_screen = "\033[?1049h";
    constexpr const char* main_screen = "\033[?1049l";
    
    // reset all
    constexpr const char* reset = "\033[0m";
}
