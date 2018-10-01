//
//  Token.h
//  Lab1-Lexical-analyzer
//
//  Created by Shinjin Ethan Harris on 9/24/18.
//  Copyright © 2018 Shinjin Ethan Harris. All rights reserved.
//

#ifndef Token_h
#define Token_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum State {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, ENDOF};

class Token
{
private:
    State tokType;
    string value;
    int lineNum;
public:
    Token(State t, string v, int l);
    ~Token();
    void coutToken();
    string tokenToString(State tT);//make the enum into a string output
};

#endif /* Token_h */

















