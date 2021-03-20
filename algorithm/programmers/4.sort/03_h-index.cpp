#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());

    int size = citations.size();
    for (int h = size; h >= 0; --h) {
        int idx = lower_bound(citations.begin(), citations.end(), h) - citations.begin();

        if (size - idx >= h) {
            return h;
        }
    }

    return answer;
}

int main() 
{
    int arr[] = { 20,21,22,23 };
    vector<int> v(arr, arr + 4);

    printf("\n%d\n", solution(v));

    return 0;
}