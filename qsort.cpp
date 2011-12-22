
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
vector<T> myqsort(const vector<T>& v) {
    if (!v.empty()) {
        vector<T> l = v, r = v;
        T m = v.back();
        l.erase(remove_if(l.begin(), --l.end(), bind2nd(greater<T>(), m)), l.end());
        r.erase(remove_if(r.begin(), --r.end(), bind2nd(less<T>(), m)), r.end());
        l = myqsort(l);
        r = myqsort(r);
        l.push_back(m);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
    return vector<T>();
}

int main() {
    for (int i : myqsort(vector<int>({3, 1, 0, 9, 4, 2, 6, 7, 5, 8}))) {
        cout << i << endl;
    }
}

