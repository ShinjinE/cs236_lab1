//
//  Scanner.hpp
//  Lab1-Lexical-analyzer
//
//  Created by Shinjin Ethan Harris on 9/27/18.
//  Copyright © 2018 Shinjin Ethan Harris. All rights reserved.
//

#ifndef Scanner_hpp
#define Scanner_hpp
#include "Token.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

class Scanner
{
private:
    ifstream* file;
    int lineNum;
    vector<Token*> token;
public:
    Scanner(ifstream& f);
    ~Scanner();
    void Lex();
    void print();
    int getTokenType(char next);
    void isSymbol(char next);
    void isID(char next);
    void isSingleLineComment(char next);
    void isBlockComment(char next);
    void isString(char next);
};

#endif /* Scanner_hpp */
