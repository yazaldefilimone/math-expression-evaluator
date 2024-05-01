#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

 
int get_math_operation_priority(char operation) {
    switch (operation) {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

bool is_operator(char operation) {
    return operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^';
}
bool is_close_parenthesis(char operation) {
  return operation == ')';
}
bool is_open_parenthesis(char operation) {
  return operation == '(';
}
int string_to_int(string str_number) {
    // 10_000_000 -> 10000000
    string _number = "";
    //!todo: use internal function to remove all '_' characters
    for (int cursor = 0; cursor < str_number.size(); cursor++) {
      if (str_number[cursor] != '_') {
        _number += str_number[cursor];
      }
    }
    return stoi(_number);
}

bool is_digit(char character) {
    return isdigit(character) || character == '_';
}
bool is_whitespace(char character) {
    return character == ' ';
}

int binary_operation(int left_operand, int right_operand, char operation) {
  switch (operation) {
    case '+':
      return left_operand + right_operand;
    case '-':
      return left_operand - right_operand;
    case '*':
      return left_operand * right_operand;
    case '/':
      return left_operand / right_operand;
    case '^':
      return pow(left_operand, right_operand);
    default:
      return 0;
  }
}
int evaluate(string expression) {
  vector<int> stack;
  for (int cursor =  0; cursor < expression.size(); cursor++) {
    if (expression[cursor] == ' ') {
      continue;
    }
    if (isdigit(expression[cursor])) {
        string str_num = "";
        while (cursor < expression.size() && is_digit(expression[cursor])) {
          str_num += expression[cursor];
          cursor++;
        }
        int number = string_to_int(str_num);
        stack.push_back(number);
    }
    if (is_operator(expression[cursor]) && stack.size() >= 2) {
      int right_operand = stack.back();
      stack.pop_back();
      int left_operand = stack.back();
      stack.pop_back();
      int result = binary_operation(left_operand, right_operand, expression[cursor]);
      stack.push_back(result);
    }
  }

    return stack.back();
}

int main() {
    string expression = "10 + 2 * 6";
    cout << evaluate(expression) << endl;
}
