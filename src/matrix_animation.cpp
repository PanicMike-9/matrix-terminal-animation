#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using std::vector;
using std::string;

#define ROWS 20
#define COLS 60

void update_canvas(vector<string>& canvas)
{
    int last_row = canvas.size() - 1;

    for(int row = last_row; row > 0; --row)
    {
        canvas[row] = canvas[row - 1];
    }

    canvas[0] = string(canvas[0].size(), ' ');
}

int main()
{
    vector<string> canvas(ROWS, string(COLS, ' '));
    canvas[0][2] = 'X';

    for(const string& row : canvas)
    {
        std::cout << row << '\n';
    }

    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    update_canvas(canvas);

    std::cout << "\033[2J\033[H";
    for(const string& row : canvas)
    {
        std::cout << row << '\n';
    }
    std::cout.flush();
    return 0;
}
