#include "msh/lexer.hpp"

#include <cassert>
#include <iostream>

int main()
{
    auto tokens = msh::tokenize("cat file.txt | grep hello > output.txt");

    assert(tokens.size() == 7);

    assert(tokens[0].type == msh::TokenType::word);
    assert(tokens[0].value == "cat");

    assert(tokens[1].value == "file.txt");

    assert(tokens[2].type == msh::TokenType::pipe);

    assert(tokens[3].value == "grep");
    assert(tokens[4].value == "hello");

    assert(tokens[5].type == msh::TokenType::redirect_out);
    assert(tokens[6].type == msh::TokenType::word);
    assert(tokens[6].value == "output.txt");
    std::cout << "Lexer tests passed.\n";
}
