#include <string>
#include <vector>


enum TokenEnum {
  NUMBER,// 0-9
  PLUS,// +
  MINUS,// -
  MULTIPLY,// *
  DIVIDE,// /
  LPAREN,// (
  RPAREN,// )
  RBRACKET,// [
  LBRACKET,// ]
  SYMBOL,// a-z
  ASSIGN,// =
  EOL,// end of line
};

struct Token {
    TokenEnum type;
    std::string value;
    Token(TokenEnum type, std::string value) : type(type), value(value) {}
};


struct BinaryExpression {
    Token _operator;
    Token left;
    Token right;
};
struct UnaryExpression {
    Token _operator;
    Token operand;
};

struct Program {
    vector<BinaryExpression, UnaryExpression> expressions;
};



class Tokenizer {
    int courser;
    std::string expression;
    public:
    std::vector<Token> tokens;
    Tokenizer(std::string expression) : expression(expression), courser(0) {}
    void advance();
};
