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

// ����� ������ �˻��ϴ� �Լ�
bool checkCmd(string cmd, string program) {

    // ����� split�� ��, �ܾ� ������ ������ �˻�
    vector<string> vCmd = split(cmd, ' ');
    
        // 1. ���α׷� �̸� �˻�
    if (vCmd[0] != program) return false;

        // 2. flag �˻�
    for (int i = 1; i < vCmd.size(); ++i) {
            // argument�� ���, ���� flag�̸��� ruleMap���� Ž���ؼ� argument ���� �޾ƿ���
        if (vCmd[i][0] != '-') {
            string arg = ruleMap[vCmd[i-1]];
            
            // argument ���ǿ� ���� ������ �´��� �˻�
            if (arg == "STRING") {
                // ��ҹ��ڰ� �ƴ� ���ڰ� ������ false ����
                for (int idx = 0; idx < vCmd[i].length(); ++idx) {
                    if (!(vCmd[i][idx] >= 'a' && vCmd[i][idx] <= 'z' ||
                        vCmd[i][idx] >= 'A' && vCmd[i][idx] <= 'Z')) return false;
                }
            }
            else if (arg == "NUMBER") {
                // 0~9�� �ƴ� ���ڰ� ������ false ����
                for (int idx = 0; idx < vCmd[i].length(); ++idx) {
                    if (!(vCmd[i][idx] >= '0' && vCmd[i][idx] <= '9')) return false;
                }    
            }
            else { //if (arg == "NULL") 
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
    }
    
    return answer;
}