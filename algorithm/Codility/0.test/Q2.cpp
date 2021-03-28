// you can use includes, for example:
// #include <algorithm>
#include <string>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    string ret = "";
    int ret_ptr = 0;
    ret += S[0];

    for (int i = 1;  i < S.length(); ++i) {
        if ((S[i] == 'A') && (ret[ret_ptr] == 'B')) { ret.pop_back(); ret_ptr--; }
        else if ((S[i] == 'B') && (ret[ret_ptr] == 'A')) { ret.pop_back(); ret_ptr--; }
        else if ((S[i] == 'C') && (ret[ret_ptr] == 'D')) { ret.pop_back(); ret_ptr--; }
        else if ((S[i] == 'D') && (ret[ret_ptr] == 'C')) { ret.pop_back(); ret_ptr--; }
        else { ret += S[i]; ret_ptr++; }
    }

    return ret;
}
