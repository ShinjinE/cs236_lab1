//
//  Token.cpp
//  Lab1-Lexical-analyzer
//
//  Created by Shinjin Ethan Harris on 9/24/18.
//  Copyright © 2018 Shinjin Ethan Harris. All rights reserved.
//

#include "Token.h"

Token::Token(State t, string v, int l)
{
    tokType = t;
    value = v;
    lineNum = l;
}

Token::~Token()
{
}

void Token::coutToken() {
    cout << "(" << tokenToString(tokType) << ",\"" << value << "\"," << lineNum << ")" << endl;
}

string Token::tokenToString(State tT){
    switch (tT) {
        case COMMA: return "COMMA";
        case PERIOD: return "PERIOD";
        case Q_MARK: return "Q_MARK";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case COLON: return "COLON";
        case COLON_DASH: return "COLON_DASH";
        case MULTIPLY: return "MULTIPLY";
        case ADD: return "ADD";
        case SCHEMES: return "SCHEMES";
        case FACTS: return "FACTS";
        case RULES: return "RULES";
        case QUERIES: return "QUERIES";
        case ID: return "ID";
        case STRING: return "STRING";
        case COMMENT: return "COMMENT";
        case WHITESPACE: return "WHITESPACE";
        case UNDEFINED: return "UNDEFINED";
        case ENDOF: return "EOF";
    }
    return "ERROR";
}
















