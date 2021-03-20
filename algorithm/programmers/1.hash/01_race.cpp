// 완주하지 못한 선수
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  map<string, int> m;
  
  for (string name : participant) {
    m[name]++;
  }

  for (string name : completion) {
    m[name]--;
  }

  for (pair<string, int> psi : m) {
    if (psi.second > 0) {
      answer = psi.first;
      break;
    }
  }
  return answer;
}

int main() {
  vector<string> a = {"leo", "kiki", "eden"}, b= {"eden", "kiki"};
  printf("%s\n", solution(a, b));
  return 0;
}