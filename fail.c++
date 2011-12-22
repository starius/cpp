#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <functional>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::string;
using std::vector;

template <typename T>
int compare(const T& left, const T& right) {
    if (left == right) {
        return 0;
    } else if (left < right) {
        return -1;
    }
    return 1;
}

template <typename It, typename T>
void quickSort(It begin, It end, int (*compare)(T, T)) {

    if (begin == end) {
        return;
    }

    It leftEnd = begin;
    It rightBegin = end;
    It candidate;

    long long pivotIndex = rand() % (end - begin);
    const T pivot = begin[pivotIndex];

    for (candidate = begin; candidate != rightBegin;) {

        cout << pivot << endl;

        int compareResult = compare(*candidate, pivot);

        if (compareResult == 0) {
            ++candidate;
        }
        else
        if (compareResult <= 0) {
            //if (candidate != leftEnd) {
                std::swap(*candidate, *leftEnd);
            //}
            ++leftEnd;
            ++candidate;
        }
        else {
            --rightBegin;
            std::swap(*candidate, *rightBegin);
        }

    }
    cout << endl;

    quickSort(begin, leftEnd, compare);
    quickSort(rightBegin, end, compare);
  
}


int main() {

    int a[] = {2, 4, 4, 1, 1, 1};
    vector<int> b(a,a+6);

    quickSort(b.begin(), b.end(), &compare<int>);

    int c = 1;

    for (int i = 0; i < 6; ++i){
        compare(c, a[i]);
    }
    cout << c << endl;
    return 0;
}
