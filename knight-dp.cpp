#include <string.h>
#include <iostream>
#include <list>

using namespace std;

struct Xy {
    Xy():
        x(-1), y(-1)
    { }

    Xy(int x1, int y1):
        x(x1), y(y1)
    { }

    int x;
    int y;

    bool operator==(const Xy& xy) const {
        return x == xy.x && y == xy.y;
    }

    bool operator!=(const Xy& xy) const {
        return !(*this == xy);
    }
};

list<Xy> points;
Xy prev[8][8];

void add_point(int x, int y, const Xy& p) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return;
    }
    if (prev[x][y] != Xy()) {
        return;
    }
    prev[x][y] = p;
    Xy xy;
    xy.x = x;
    xy.y = y;
    points.push_back(xy);
}

int main() {
    int from_x, from_y;
    cin >> from_x >> from_y;
    add_point(from_x, from_y, Xy(from_x, from_y));
    while (!points.empty()) {
        Xy xy = points.front();
        points.pop_front();
        add_point(xy.x - 1, xy.y - 2, xy);
        add_point(xy.x - 1, xy.y + 2, xy);
        add_point(xy.x + 1, xy.y - 2, xy);
        add_point(xy.x + 1, xy.y + 2, xy);
        add_point(xy.x - 2, xy.y - 1, xy);
        add_point(xy.x - 2, xy.y + 1, xy);
        add_point(xy.x + 2, xy.y - 1, xy);
        add_point(xy.x + 2, xy.y + 1, xy);
    }
    int to_x, to_y;
    cin >> to_x >> to_y;
    Xy xy(to_x, to_y);
    while (prev[xy.x][xy.y] != xy) {
        cout << "(" << xy.x << "," << xy.y << ") ";
        xy = prev[xy.x][xy.y];
    }
    cout << "(" << xy.x << "," << xy.y << ") ";
    cout << endl;
}

