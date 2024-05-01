#include "iostream"
#include "core.h"
#include <cctype>
#include <ratio>
// #include "vector"

using namespace std;


// math expression evaluator


void Tokenizer::advance(){
    while (courser <= expression.size()){
        switch (expression[courser]){
            case ' ':
                courser++;
                break;
            case '+':
                tokens.push_back(Token(TokenEnum::PLUS, "+"));
                courser++;
                break;
            case '-':
                tokens.push_back(Token(TokenEnum::MINUS, "-"));
                courser++;
                break;
            case '*':
                tokens.push_back(Token(TokenEnum::MULTIPLY, "*"));
                courser++;
                break;
            case '/':
                tokens.push_back(Token(TokenEnum::DIVIDE, "/"));
                courser++;
                break;
            case '(':
                tokens.push_back(Token(TokenEnum::LPAREN, "("));
                courser++;
                break;
            case ')':
                tokens.push_back(Token(TokenEnum::RPAREN, ")"));
                courser++;
                break;
            case '[':
                tokens.push_back(Token(TokenEnum::LBRACKET, "["));
                courser++;
                break;
            case ']':
                tokens.push_back(Token(TokenEnum::RBRACKET, "]"));
                courser++;
                break;
            default:
                if (isdigit(expression[courser])){
                    string number;
                    while (isdigit(expression[courser])){
                        number += expression[courser];
                        courser++;
                    }
                    tokens.push_back(Token(TokenEnum::NUMBER, number));
                } else if  (isalpha(expression[courser])){
                    char var = expression[courser];
                    courser++;
                    if (isalpha(expression[courser])){
                        cout << "Error: only one letter variables are supported" << endl;
                        exit(1);
                    }
                    tokens.push_back(Token(TokenEnum::SYMBOL, string(1, var)));
                } else {
                    cout << "Error: invalid character" << endl;
                    exit(1);
                }

        }
        tokens.push_back(Token(TokenEnum::EOL, ""));
    }
}


Program parser(Tokenizer tokenizer){
    Program program;
    tokenizer.advance();
    int index = 0;
    do {
        if (tokenizer.tokens[index].type == TokenEnum::NUMBER){
            UnaryExpression unary;
            unary.operand = tokenizer.tokens[index];
            program.expressions.push_back(unary);
        } else if (tokenizer.tokens[index].type == TokenEnum::SYMBOL){
            UnaryExpression unary;
            unary.operand = tokenizer.tokens[index];
            program.expressions.push_back(unary);
        } else if (tokenizer.tokens[index].type == TokenEnum::PLUS){
            BinaryExpression binary;
            binary._operator = tokenizer.tokens[index];
            binary.left = tokenizer.tokens[index - 1];
            binary.right = tokenizer.tokens[index + 1];
            program.expressions.push_back(binary);
        } else if (tokenizer.tokens[index].type == TokenEnum::MINUS){
            BinaryExpression binary;
            binary._operator = tokenizer.tokens[index];
            binary.left = tokenizer.tokens[index - 1];
            binary.right = tokenizer.tokens[index + 1];
            program.expressions.push_back(binary);
        } else if (tokenizer.tokens[index].type == TokenEnum::MULTIPLY){
            BinaryExpression binary;
            binary._operator = tokenizer.tokens[index];
            binary.left = tokenizer.tokens[index - 1];
            binary.right = tokenizer.tokens[index + 1];
            program.expressions.push_back(binary);
        } else if (tokenizer.tokens[index].type == TokenEnum::DIVIDE){
            BinaryExpression binary;
            binary._operator = tokenizer.tokens[index];
            binary.left = tokenizer.tokens[index - 1];
            binary.right = tokenizer.tokens[index + 1];
            program.expressions.push_back(binary);
        }
        index++;
    } while (tokenizer.tokens[index].type != TokenEnum::EOL);
    return program;
}

















int main() {
  return 0;
}
