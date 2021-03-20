#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> res;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        res.push_back(temp);
    }

    return  res;
}


map<string, string> ruleMap;

// 명령줄 단위로 검사하는 함수
bool checkCmd(string cmd, string program) {

    // 명령줄 split한 후, 단어 단위로 꺼내서 검사
    vector<string> vCmd = split(cmd, ' ');
    
        // 1. 프로그램 이름 검사
    if (vCmd[0] != program) return false;

        // 2. flag 검사
    for (int i = 1; i < vCmd.size(); ++i) {
            // argument인 경우, 이전 flag이름을 ruleMap에서 탐색해서 argument 조건 받아오기
        if (vCmd[i][0] != '-') {
            string arg = ruleMap[vCmd[i-1]];
            
            // argument 조건에 따라 형식이 맞는지 검사
            if (arg == "STRING") {
                // 대소문자가 아닌 글자가 있으면 false 리턴
                for (int idx = 0; idx < vCmd[i].length(); ++idx) {
                    if (!(vCmd[i][idx] >= 'a' && vCmd[i][idx] <= 'z' ||
                        vCmd[i][idx] >= 'A' && vCmd[i][idx] <= 'Z')) return false;
                }
            }
            else if (arg == "NUMBER") {
                // 0~9가 아닌 숫자가 있으면 false 리턴
                for (int idx = 0; idx < vCmd[i].length(); ++idx) {
                    if (!(vCmd[i][idx] >= '0' && vCmd[i][idx] <= '9')) return false;
                }    
            }
            else { //if (arg == "NULL") 
                // NULL이어야 하는데 뭔가 있으면 false 리턴
                return false;
            }
        }
    }

    return true;
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    
    // flag_rules에 들어있는 조건을 map의 형태로 저장 (공백으로 split 후 각각을 key, value)
    for (int i = 0; i < flag_rules.size(); ++i) {
        vector<string> v = split(flag_rules[i], ' ');
        ruleMap[v[0]] = v[1];
    }

    // map 검사 
    // map<string, string>::iterator it;
    // for (it = ruleMap.begin(); it != ruleMap.end(); ++it) {
    //     printf("key = %s, value = %s\n", it->first.c_str(), it->second.c_str());
    // }

    // commands 검사해서 리턴받은 결과 값 answer에 삽입
    for (int i = 0; i < commands.size(); ++i) {
        answer.push_back(checkCmd(commands[i], program));
    }
    
    return answer;
}