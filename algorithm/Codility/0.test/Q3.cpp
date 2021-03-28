// you can use includes, for example:
// #include <algorithm>
#include <string>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> aIndex;

    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'a') aIndex.push_back(i);
    }
    int size = aIndex.size();
    if ((size % 3) != 0) return 0;

    if (size == 0) {
        int n = S.length() - 2;
        return n * (n-1) / 2;
    }
    
    int fir = size / 3;
    int sec = fir * 2;

    int bcnt1 = aIndex[fir] - aIndex[ 0 ];
    int bcnt2 = aIndex[sec] - aIndex[fir];

    return bcnt1 * bcnt2;
}
