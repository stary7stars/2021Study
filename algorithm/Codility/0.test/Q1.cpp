// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define LIMIT (1<<20) 

stack<int> st;

vector<string> split(string in, char token) 
{
    stringstream ss(in);
    vector<string> ret;
    string tmp;

    while (getline(ss, tmp, token)) {
        ret.push_back(tmp);
    }

    return  ret;
}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<string> cmd;

    cmd = split(S, ' ');

    for (auto c : cmd) {
        if (c[0] >= '0' && c[0] <= '9') { // PUSH
            st.push(stoi(c));
        }
        else if (c[0] == 'P') {
            if (st.empty()) return -1;

            st.pop();
        }
        else if (c[0] == 'D') { // DUP
            if (st.empty()) return -1;

            st.push(st.top());
        }
        else if (c[0] == '+') { // +
            if (st.size() < 2) return -1;

            int fir = st.top(); st.pop();
            int sec = st.top(); st.pop();

            if (fir + sec > LIMIT) return -1;

            st.push(fir + sec);
        }
        else { // -
            if (st.size() < 2) return -1;

            int fir = st.top(); st.pop();
            int sec = st.top(); st.pop();

            if (fir - sec < 0) return -1;

            st.push(fir - sec);
        }
    }

    return st.top();
}
