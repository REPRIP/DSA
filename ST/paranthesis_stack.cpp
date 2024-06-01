#include <iostream>
#include "stack.h"
using namespace std;
int main() {
  int i = 0;
  bool flag = true;
  string instr;
  cout << "Enter the paranthesis expression to be checked" << endl;
  cin >> instr;
  int n = instr.length();
  if (n%2 != 0){
    cout << "Paranthesis is not balanced" << endl;
  }
  else{
  Stack stack(n);
  while (i < n){
    switch(instr[i]){
      case '(': stack.push(instr[i]); break;
      case '{': stack.push(instr[i]); break;
      case '[': stack.push(instr[i]); break;
      case ']': if (stack.pop() != '[') {flag = false;} break;
      case ')': if (stack.pop() != '(') {flag = false;} break;
      case '}': if (stack.pop() != '{') {flag = false;} break;
      default : cout << "ERROR"; break;
    }
    i++;
  }
  if (flag == false){
    cout << "Paranthesis is not balanced" << endl;
  }
  else{
    cout << "Paranthesis is balanced" << endl;
  }
  }
}