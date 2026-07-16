#include <iostream>

#include <vector>
#include <string>

#include <chrono>
#include <thread>
#include <ctime>

#include <random>

#include "ansi.hpp"

const constexpr int DELAY = 50; 
const constexpr int ROWS  = 48;
const constexpr int COLS  = 180;

// random algorithm
static std::mt19937 gen(std::random_device{}());

// refactoring in progress...
struct Stream 
{
    int column;
    int head;
    int length;
};

//updates canvas and prints 0 or 1 
void update_canvas(std::vector<std::string>& canvas, std::vector<int>& stream_len)
{
    // stream random length sizes
    constexpr int max_len = 25; 
    constexpr int min_len = 10;

    // range
    std::uniform_int_distribution<> distrib(1, 50);

    // row and column
    const int& last_row = canvas.size() - 1;

    // row loop
    for (auto rows = last_row; rows > 0; --rows)
    {
        canvas[rows] = canvas[rows - 1];
    }

    // column loop
    for (auto cols = 0; cols < canvas[0].size(); ++cols)
    {
        if (stream_len[cols] > 0) 
        {
            canvas[0][cols] = (distrib(gen) % 2 == 0) ? '0' : '1';
            canvas[2][cols] = (distrib(gen) % 2 == 0) ? '<' : '@';
            canvas[4][cols] = (distrib(gen) % 2 == 0) ? '~' : '^';

            /*
            for (auto i = 1; i < 10; ++i)
            {
                canvas[0][cols] = (distrib(gen) % i == 0) ? '$' : '0';
                canvas[2][cols] = (distrib(gen) % i == 0) ? '1' : '*';
                canvas[4][cols] = (distrib(gen) % i == 0) ? '~' : '5';
            }
            */
            stream_len[cols]--;
        }
        else 
        {
            canvas[0][cols] = ' ';

            if (stream_len[cols] == 0)
            {
                if (distrib(gen) % 20 == 0)
                {
                    stream_len[cols] = (distrib(gen) % (max_len - min_len + 1)) + min_len;
                }
            }
        }
    }
}

// animate the canvas
void animate(std::vector<std::string>& canvas)
{
    // stream length std::vector to create streams
    std::vector<int> stream_len(COLS);

    // animation loop
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY)); // add delay

        std::cout << ansi::home;

        update_canvas(canvas, stream_len);

        for (const std::string& row : canvas)
        {
            for (const char& ch : row)
            {
                if (ch == ' ')
                {
                    std::cout << ch;
                }
                else 
                {
                    std::cout << ansi::bright_red << ch;
                }
            }
            std::cout << '\n';
            std::cout.flush();
        }
    }
}

int main()
{
    srand(time(nullptr));
    std::vector<std::string> canvas(ROWS, std::string(COLS, ' '));
    canvas[0][2] = ' ';

    // open alternate screen
    std::cout << ansi::alt_screen;
 
    // play animation
    animate(canvas);    

    // back to main screen
    std::cout << ansi::main_screen;

    return 0;
}


