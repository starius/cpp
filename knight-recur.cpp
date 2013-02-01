#include <string.h>
#include <iostream>

using namespace std;

int a[8][8];

void knight(int x, int y, int steps) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return;
    }
    if (steps < a[x][y] || a[x][y] == 0) {
        a[x][y] = steps;
        knight(x - 1, y - 2, steps + 1);
        knight(x - 1, y + 2, steps + 1);
        knight(x + 1, y - 2, steps + 1);
        knight(x + 1, y + 2, steps + 1);
        knight(x - 2, y - 1, steps + 1);
        knight(x - 2, y + 1, steps + 1);
        knight(x + 2, y - 1, steps + 1);
        knight(x + 2, y + 1, steps + 1);
    }
}

int main() {
    memset(a, 0, 8 * 8 * sizeof(int));
    knight(3, 3, 1);
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            cout << a[x][y] << ' ';
        }
        cout << endl;
    }
    int dummy;
    cin >> dummy;
}

