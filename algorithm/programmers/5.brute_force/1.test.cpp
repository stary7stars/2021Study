#include <string>
#include <vector>

using namespace std;

int st1[] = { 1, 2, 3, 4, 5 }; // 5
int st2[] = { 2, 1, 2, 3, 2, 4, 2, 5 }; // 8
int st3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 10

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score1=0, score2=0, score3=0;
    
    for (int i = 0; i < answers.size(); ++i) {
        int ans = answers[i];
        if (st1[i%5] == ans) score1++;
        if (st2[i%8] == ans) score2++;
        if (st3[i%10] == ans) score3++;
    }

    if (score1 >= score2 && score1 >= score3) answer.push_back(1);
    if (score2 >= score1 && score2 >= score3) answer.push_back(2);
    if (score3 >= score1 && score3 >= score2) answer.push_back(3);

    return answer;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a(arr, arr+5);
    vector<int> b = solution(a);
    for (int i =0; i < b.size(); ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}