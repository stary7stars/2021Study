#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int ans[1000];

vector<int> solution(vector<int> enter, vector<int> leave) {
    deque<int> dq;

    dq.push_back(enter[0]);

    int ptr_enter = 1;
    int size = leave.size();
    for (int i = 0; i < size; ++i) {
        deque<int>::iterator iter = find(dq.begin(), dq.end(), leave[i]);
        if (iter != dq.end()) {
            dq.erase(iter);
        }
        else {
            do {
                dq.push_back(enter[ptr_enter]);
            } while (enter[ptr_enter++] != leave[i]);

            deque<int>::iterator it;
            for (it = dq.begin(); it < dq.end(); ++it) {
                ans[*it - 1] += (dq.size()-1);
            }

            dq.erase(find(dq.begin(), dq.end(), leave[i]));
        }
    }

    vector<int> answer(ans, ans+size);
    return answer;
}

int main()
{
    int a1[] = {1, 4, 2, 3}; vector<int> v1(a1, a1 + 4);
    int a2[] = {2, 1, 3, 4}; vector<int> v2(a2, a2 + 4);
    solution(v1, v2);
    return 0;
}