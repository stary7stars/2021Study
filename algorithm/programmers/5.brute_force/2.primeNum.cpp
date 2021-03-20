#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool prime[10000000];

int solution(string numbers) {
    int answer = 0;

    prime[0] = prime[1] = true;
    for (int i = 2; i*i < 10000000; ++i) {
        if (!prime[i]) {
            for (int j = i*i; j < 10000000; j += i) {
                prime[j] = true;
            }
        }
    }

    vector<char> vNum;
    vector<int> vTotal;

    for (int i = 0; i < numbers.length(); ++i) {
        vNum.push_back(numbers[i]);
    }
    sort(vNum.begin(), vNum.end());

    while(true) {
        string tmp = "";

        for (int i = 0; i < vNum.size(); ++i) {
            tmp += vNum[i];
            vTotal.push_back(stoi(tmp));
        }

        if (!next_permutation(vNum.begin(), vNum.end())) break;
    }

    sort(vTotal.begin(), vTotal.end());
    vTotal.erase(unique(vTotal.begin(), vTotal.end()), vTotal.end());

    for (int i = 0; i < vTotal.size(); ++i) {
        if (!prime[vTotal[i]]) {
            printf("%d\n", vTotal[i]);
            answer++;
        }
    }

    return answer;
}


int main()
{
    printf("ans = %d\n", solution("00"));

    return 0;
}