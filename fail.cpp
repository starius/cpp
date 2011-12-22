#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <functional>
#include <iterator>
#include <algorithm>

using namespace std;

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
    T pivot = begin[pivotIndex];
    for (candidate = begin; candidate != rightBegin;) {
        int compareResult = compare(*candidate, pivot);
        if (compareResult == 0) {
            ++candidate;
        } else if (compareResult <= 0) {
            std::swap(*candidate, *leftEnd);
            ++leftEnd;
            ++candidate;
        } else {
            --rightBegin;
            std::swap(*candidate, *rightBegin);
        }
    }
    quickSort(begin, leftEnd, compare);
    quickSort(rightBegin, end, compare);
}

int main() {
    int a[] = {2, 4, 4, 1, 1, 1};
    vector<int> b(a, a + 6);
    quickSort(b.begin(), b.end(), &compare<int>);
    for (vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
        cout << *it << endl;
    }
}

