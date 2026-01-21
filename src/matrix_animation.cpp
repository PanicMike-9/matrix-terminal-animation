#include <iostream>
#include <vector>
#include <string>

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
    update_canvas(canvas);
    return 0;
}
