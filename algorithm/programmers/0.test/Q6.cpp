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

// STRING 검사
bool checkStr(string arg) {
    for (int idx = 0; idx < arg.length(); ++idx) {
        if (!(arg[idx] >= 'a' && arg[idx] <= 'z' ||
            arg[idx] >= 'A' && arg[idx] <= 'Z')) return false;
    }

    return true;
}

// NUMBER 검사
bool checkNum(string arg) {
    for (int idx = 0; idx < arg.length(); ++idx) {
        if (!(arg[idx] >= '0' && arg[idx] <= '9')) return false;
    }  

    return true;
}

// 명령줄 단위로 검사하는 함수
bool checkCmd(string cmd, string program) {

    // 명령줄 split한 후, 단어 단위로 꺼내서 검사
    vector<string> vCmd = split(cmd, ' ');
    
        // 1. 프로그램 이름 검사
    if (vCmd[0] != program) return false;

        // 2. flag 검사
    string argType;
    vector<string> args;
    for (int i = 1; i < vCmd.size(); ++i) {
            // argument인 경우, args 배열에 추가해주기
        if (vCmd[i][0] == '-') {
            // '-'로 시작하는 flag를 만났으니 argType 변수에 새롭게 넣어주고 args 배열도 초기화해준다.
            argType = ruleMap[vCmd[i]];
            args.clear();

            
        }
        else {
            args.push_back(vCmd[i]);

            // 갯수가 하나여야 하는데 여러개일 경우 false 리턴
            if (argType == "STRING" || argType == "NUMBER") {
                if (args.size() > 1) return false;
            }

            // 현재까지 저장된 argument들이 조건에 따라 형식이 맞는지 검사
            if (argType.find("STRING") != string::npos) {
                // 대소문자가 아닌 글자가 있으면 false 리턴
                if (!checkStr(vCmd[i])) return false;
            }
            else if (argType.find("NUMBER") != string::npos) {
                // 0~9가 아닌 숫자가 있으면 false 리턴
                if (!checkNum(vCmd[i])) return false;
            }
            else if (argType == "NULL" && args.size() > 0) {
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
        printf("\n");
    }
    
    return answer;
}