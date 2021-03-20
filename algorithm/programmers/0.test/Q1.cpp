#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int score[5];

vector<string> split(string input, char delimiter) {
    vector<string> res;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        res.push_back(temp);
    }

    return  res;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<vector<string>> table_split;
    for (int i = 0; i < table.size(); ++i) {
        vector<string> v = split(table[i], ' ');
        table_split.push_back(v);
    }

    int size = languages.size();
    for (int i = 0; i < size; ++i) {
        string key = languages[i];

        for (int j = 0; j < 5; ++j) {
            int idx = find(table_split[j].begin(), table_split[j].end(), key) - table_split[j].begin();
            score[j] += (5-idx) * preference[i];
        }
    }

    int max_idx = 0;

    for (int i = 1; i < 5; ++i) {
        if (score[i] > score[max_idx]) {
            max_idx = i;
        }
        else if (score[i] == score[max_idx]) {
            if (table_split[i][0] < table_split[max_idx][0]) {
                max_idx = i;
            }
        }
    }
    answer = table_split[max_idx][0];
    return answer;
}