#include <string>
#include <vector>

using namespace std;

bool check1 = false, check2 = false, check3 = false, check4 = true, check5 = true;
int hasAl[] = {0, 0, 0, 0}; 
int ascii[128];

void rule23(string inp_str) {
    string s = "~!@#$%^&*";

    for (int i = 0; i < inp_str.length(); ++i) {
        char c = inp_str[i];
        ascii[c]++;
        if (c >= 'A' && c <= 'Z') hasAl[0]++;
        else if (c >= 'a' && c <= 'z') hasAl[1]++;
        else if (c >= '0' && c <= '9') hasAl[2]++;
        else if (s.find(c) != string::npos) hasAl[3]++;
    }

    if (hasAl[0] + hasAl[1] + hasAl[2] + hasAl[3] == inp_str.length()) check2 = true;

    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        if (hasAl[i] == 0) cnt++; 
    }

    if (cnt < 2) check3 = true;
}

void rule4(string inp_str) {
    for (int i = 0; i <= inp_str.length()-4; ++i) {
        if (inp_str[i] == inp_str[i+1] &&
            inp_str[i+1] == inp_str[i+2] &&
            inp_str[i+2] == inp_str[i+3])
            check4 = false;
    }
}

vector<int> solution(string inp_str) {
    vector<int> answer;

    if (inp_str.length() >= 8 && inp_str.length() <= 15) check1 = true;

    rule23(inp_str);
    rule4(inp_str);

    for (int i = 0; i < 128; ++i) {
        if (ascii[i] >= 5) check5 = false;
    }

    if (!check1) answer.push_back(1);
    if (!check2) answer.push_back(2);
    if (!check3) answer.push_back(3);
    if (!check4) answer.push_back(4);
    if (!check5) answer.push_back(5);
    if (answer.size() == 0) answer.push_back(0);
    return answer;
}

int main()
{   
    string a = "CaCbCgCdC888834A";
    vector<int> b = solution(a);
    for (int i = 0; i < b.size(); ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}