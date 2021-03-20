#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> prices) {
    
    int size = prices.size();
    int * ans_arr = new int[size];

    stack<pii> st;
    st.push(pii(prices[0], 0));
    
    for (int i = 1; i < size; ++i) {
        int price = prices[i];

        if (!st.empty()) {
            pii top = st.top();
            while (top.first > price) {
                int idx = top.second;
                ans_arr[idx] = i - idx;
                st.pop();
                if (st.empty()) break;
                top = st.top();
            } 
        }

        st.push(pii(price, i));
    }

    while (!st.empty()) {
        ans_arr[st.top().second] = size - st.top().second - 1;
        st.pop();
    }
    
    return vector<int>(ans_arr, ans_arr+size);
}

int main() 
{
    int arr[] = { 5, 8, 6, 2, 4, 1 };
    vector<int> v(arr, arr + 6);
    vector<int> a = solution(v);
    for (int i = 0; i < a.size(); ++i) {
        printf("%d\n", a[i]);
    }

    return 0;
}