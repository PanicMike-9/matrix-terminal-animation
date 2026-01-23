#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::string;

#define ROWS 20
#define COLS 60
constexpr int DELAY = 100; // in milliseconds
constexpr const char* CLEAR_SCREEN = "\033[2J\033[H"; // ANSI code to clear terminal
constexpr const char* ANSI_GREEN = "\e[38;2;0;255;0m"; // ANSI code for Green color
constexpr const char* ANSI_RESET = "\033[0m"; // ANSI code for reset

//updates canvas and prints 0 or 1 
void update_canvas(vector<string>& canvas)
{
    int last_row = canvas.size() - 1;

    for(int row = last_row; row > 0; --row)
    {
        canvas[row] = canvas[row - 1];
    }

    for(size_t col = 0; col < canvas[0].size(); ++col)
    {
        if(rand() % 4 == 0)
        {
            canvas[0][col] = (rand() % 2 == 0) ? '0' : '1';
        }
        else
        {
            canvas[0][col] = ' ';
        }
    }

}

// animate the canvas
void animate(vector<string>& canvas)
{
    while(true)
    {
        std::cout.flush(); //clear output buffer

        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY)); // add delay

        update_canvas(canvas);

        std::cout << CLEAR_SCREEN;

        for(const string& row : canvas)
        {
            for(const char& ch : row)
            {
                if(ch == ' ')
                    std::cout << ch;  
                else 
                {
                    std::cout << ANSI_GREEN << ch << ANSI_RESET;
                }
            }
            std::cout << '\n';
        }

        std::cout.flush();
    }
}

int main()
{
    srand(time(nullptr));
    vector<string> canvas(ROWS, string(COLS, ' '));
    canvas[0][2] = ' ';
    animate(canvas);
    return 0;
}

