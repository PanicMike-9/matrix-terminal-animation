#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <random>

using std::vector;
using std::string;

#define ROWS 20
#define COLS 60
constexpr int DELAY = 100; // in milliseconds
constexpr const char* CLEAR_SCREEN = "\033[2J\033[H"; // ANSI code to clear terminal
constexpr const char* ANSI_GREEN = "\033[38;2;0;255;0m"; // ANSI code for Green color
constexpr const char* ANSI_RESET = "\033[0m"; // ANSI code for reset text format
constexpr const char* HIDE_CURSOR = "\033[?25l"; // ANSI code to hide cursor
constexpr const char* SHOW_CURSOR = "\033[?25h"; // ANSI code to show cursor again
constexpr const char* ALT_SCREEN = "\033[?1049h"; // ANSI code for alternate screen
constexpr const char* MAIN_SCREEN = "\033[?1049l"; // ANSI code to restore main screen
//updates canvas and prints 0 or 1 

void update_canvas(vector<string>& canvas, vector<int> stream_len)
{
    // row and column
    int last_row = canvas.size() - 1;

    // stream random length sizes
    int max = 25, min = 10;
    
    // shift canvas down
    for(int row = last_row; row > 0; --row)
    {
        canvas[row] = canvas[row - 1];
    }

    for(size_t col = 0; col < canvas[0].size(); ++col)
    {
        if(stream_len[col] == 0)
        {
            if(rand() % 12 == 0) 
            {
                stream_len[col] = (rand() % (max - min + 1)) + min;
            }
        }

        if(stream_len[col] > 0)
        {
            canvas[0][col] = (rand() % 2 == 0) ? '0' : '1';
            stream_len[col]--;
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
    // stream length vector to create streams
    vector<int> stream_len(COLS);
    std::cout << stream_len.size() << ' ' << canvas[0].size() << '\n';
    // animation loop
    while(true)
    {
        std::cout.flush(); //clear output buffer

        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY)); // add delay

        update_canvas(canvas, stream_len);

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
    std::cout << ALT_SCREEN;
    //std::cout << HIDE_CURSOR;
    animate(canvas);
    //std::cout << SHOW_CURSOR;
    std::cout << MAIN_SCREEN;
    return 0;
}

