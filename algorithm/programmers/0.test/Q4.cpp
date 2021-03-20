#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Node {
    public :
    int id;
    int parent_id;
    string name;
    Node();
    Node(int id, int parent_id, string name) {
        this->id = id;
        this->parent_id = parent_id;
        this->name = name;
    }
};

vector<string> split(string input, char delimiter) {
    vector<string> res;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        res.push_back(temp);
    }

    return  res;
}


vector<Node> nodes;
bool in[1000];

void checkLeaf() {
    for (int i = 0; i < nodes.size(); ++i) {
        in[nodes[i].parent_id] = true;
    }
}

vector<Node> Search(string word) {
    vector<Node> res;
    
    for (int i = 0; i < nodes.size(); ++i) {
        if (!in[nodes[i].id] && nodes[i].name.find(word) != string::npos) {
            res.push_back(nodes[i]);
        }
    }

    return res;
}

vector<Node> sortRes(vector<Node> res) {
    // 검색 조건에 따라 구현

    return res;
}

vector<string> solution(vector<string> data, string word) {
    vector<string> answer;
    
    for (int i = 0; i < data.size(); ++i) {
        vector<string> v = split(data[i], ' ');
        nodes.push_back(Node(stoi(v[0]), stoi(v[2]), v[1]));
    }

    checkLeaf();

    vector<Node> res = Search(word);

    
    res = sortRes(res);
    return answer;
}