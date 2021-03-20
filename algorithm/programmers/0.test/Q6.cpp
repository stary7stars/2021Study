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

// STRING �˻�
bool checkStr(string arg) {
    for (int idx = 0; idx < arg.length(); ++idx) {
        if (!(arg[idx] >= 'a' && arg[idx] <= 'z' ||
            arg[idx] >= 'A' && arg[idx] <= 'Z')) return false;
    }

    return true;
}

// NUMBER �˻�
bool checkNum(string arg) {
    for (int idx = 0; idx < arg.length(); ++idx) {
        if (!(arg[idx] >= '0' && arg[idx] <= '9')) return false;
    }  

    return true;
}

// ����� ������ �˻��ϴ� �Լ�
bool checkCmd(string cmd, string program) {

    // ����� split�� ��, �ܾ� ������ ������ �˻�
    vector<string> vCmd = split(cmd, ' ');
    
        // 1. ���α׷� �̸� �˻�
    if (vCmd[0] != program) return false;

        // 2. flag �˻�
    string argType;
    vector<string> args;
    for (int i = 1; i < vCmd.size(); ++i) {
            // argument�� ���, args �迭�� �߰����ֱ�
        if (vCmd[i][0] == '-') {
            // '-'�� �����ϴ� flag�� �������� argType ������ ���Ӱ� �־��ְ� args �迭�� �ʱ�ȭ���ش�.
            argType = ruleMap[vCmd[i]];
            args.clear();

            
        }
        else {
            args.push_back(vCmd[i]);

            // ������ �ϳ����� �ϴµ� �������� ��� false ����
            if (argType == "STRING" || argType == "NUMBER") {
                if (args.size() > 1) return false;
            }

            // ������� ����� argument���� ���ǿ� ���� ������ �´��� �˻�
            if (argType.find("STRING") != string::npos) {
                // ��ҹ��ڰ� �ƴ� ���ڰ� ������ false ����
                if (!checkStr(vCmd[i])) return false;
            }
            else if (argType.find("NUMBER") != string::npos) {
                // 0~9�� �ƴ� ���ڰ� ������ false ����
                if (!checkNum(vCmd[i])) return false;
            }
            else if (argType == "NULL" && args.size() > 0) {
                // NULL�̾�� �ϴµ� ���� ������ false ����
                return false;
            } 
        }
    }
    
    return true;
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;
    
    // flag_rules�� ����ִ� ������ map�� ���·� ���� (�������� split �� ������ key, value)
    for (int i = 0; i < flag_rules.size(); ++i) {
        vector<string> v = split(flag_rules[i], ' ');
        
        ruleMap[v[0]] = v[1];
    }

    // map �˻� 
    // map<string, string>::iterator it;
    // for (it = ruleMap.begin(); it != ruleMap.end(); ++it) {
    //     printf("key = %s, value = %s\n", it->first.c_str(), it->second.c_str());
    // }

    // commands �˻��ؼ� ���Ϲ��� ��� �� answer�� ����
    for (int i = 0; i < commands.size(); ++i) {
        answer.push_back(checkCmd(commands[i], program));
        printf("\n");
    }
    
    return answer;
}