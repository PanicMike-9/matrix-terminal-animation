#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#define ROWS 20
#define COLS 60

void init_canvas(vector<string>& canvas)
{
}

int main()
{
    vector<string> canvas(ROWS, string(COLS, ' '));
    init_canvas(canvas);
    return 0;
}
