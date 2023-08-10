#include <iostream>
#include <string>
#include<stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
    int calPoints(vector<string> ops) {
//write code here
      vector<int> variables;
      for(int i = 0; i<ops.size(); i++){
        int total_size = variables.size();
        int opsSize = ops[i].size();
        int value = ops[i][0];
        if(total_size>0 && opsSize == 1){
        if(value=='D')
            variables.push_back(variables[(total_size-1)]*2);
        if(value=='C')
            variables.pop_back();
        if(total_size>1)
          if(value=='+')
            variables.push_back(variables[total_size-1]+ variables[total_size+2]);
        }
        if(value!= 'D' && value!='C' && value!='+')
            variables.push_back(stoi(ops[i]));
      }
      return 0;
    }
};

/**
R E A D M E
DO NOT CHANGE the code below, we use it to grade your submission. If changed your submission will be failed automatically.
**/

int main() {
  vector < string > items;
  string item;

  string line;
  getline(cin, line);
  istringstream is(line);

  while (is >> item) {
    items.push_back(item);
  }

  Solution solution;

  cout << solution.calPoints(items);
}