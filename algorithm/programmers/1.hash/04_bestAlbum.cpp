#include <string>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, string> pis;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pii>> m;
    map<string, int> kind;
    vector<pis> v_sort;

    for (int i = 0; i < genres.size(); ++i) {
        m[genres[i]].push_back({plays[i], i});
        kind[genres[i]] += plays[i];
    }

    map<string, int>::iterator iter;
    for (iter = kind.begin(); iter != kind.end(); ++iter) {
        v_sort.push_back(pis(iter->second, iter->first));
    }

    sort(v_sort.begin(), v_sort.end(), greater<pis>());

    for (pis genre : v_sort) {
        vector<pii> temp = m[genre.second];
        
        if (m[genre.second].size() == 1) {
            answer.push_back(temp[0].second);
            continue;
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = i+1; j < m[genre.second].size(); ++j) {
                if (temp[i].first < temp[j].first || 
                ((temp[i].first == temp[j].first) && (temp[i].second > temp[j].second))) {
                    pii t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }

        answer.push_back(temp[0].second);
        answer.push_back(temp[1].second);
    }
    
    return answer;
}