//
//  Scanner.cpp
//  Lab1-Lexical-analyzer
//
//  Created by Shinjin Ethan Harris on 9/27/18.
//  Copyright © 2018 Shinjin Ethan Harris. All rights reserved.
//

#include "Scanner.hpp"

Scanner::Scanner(ifstream& f){
    file = &f;
}

Scanner::~Scanner()
{
    file->close();
}

void Scanner::Lex(){
    char next;
    lineNum = 1;//starts reading at the first line
    string tokenString;
    while(file->get(next)){
       
        if (isalpha(next)){
            isID(next);
        }
        else if(isspace(next)){
            if(next == '\n'){
                lineNum++;
            }
        }
        else if(next == '\''){
            isString(next);
        }
        else if(next == '#'){
            if(file->peek() != '|'){
                isSingleLineComment(next);
            }
            else{
                isBlockComment(next);
            }
        }
        else {
            isSymbol(next);
        }
    }
    if(lineNum != 1)
        lineNum++;
    //file->get(next);
    token.push_back(new Token(ENDOF, "", lineNum));
}

void Scanner::isSymbol(char next){
    string tokenString;
    tokenString = next;
    switch (next) {
        case ',': token.push_back(new Token(COMMA, tokenString, lineNum)); break;
        case '.': token.push_back(new Token(PERIOD, tokenString, lineNum)); break;
        case '?': token.push_back(new Token(Q_MARK, tokenString, lineNum)); break;
        case '(': token.push_back(new Token(LEFT_PAREN, tokenString, lineNum)); break;
        case ')': token.push_back(new Token(RIGHT_PAREN, tokenString, lineNum)); break;
        case ':':
            if(file->peek() == '-'){
                file->get(next);
                tokenString += next;
                token.push_back(new Token(COLON_DASH, tokenString, lineNum));
                break;
            }
            token.push_back(new Token(COLON, tokenString, lineNum));
            break;
        case '*': token.push_back(new Token(MULTIPLY, tokenString, lineNum)); break;
        case '+': token.push_back(new Token(ADD, tokenString, lineNum)); break;
        default : token.push_back(new Token(UNDEFINED, tokenString, lineNum)); break;
    }
}

void Scanner::isID(char next){
    string id;
    id += next;
    while(isalpha(file->peek()) || isdigit(file->peek())){
        file->get(next);
        id += next;
    }
    if(id == "Schemes"){
        token.push_back(new Token(SCHEMES, id, lineNum));
    }
    else if(id == "Facts"){
        token.push_back(new Token(FACTS, id, lineNum));
    }
    else if(id == "Rules"){
        token.push_back(new Token(RULES, id, lineNum));
    }
    else if(id == "Queries"){
        token.push_back(new Token(QUERIES, id, lineNum));
    }
    else{
        token.push_back(new Token(ID, id, lineNum));
    }
}

void Scanner::isString(char next){
    int startLineNum = lineNum;
    string strng;
    strng += next;
    while(file->peek() != '\''){
        file->get(next);
        strng += next;
        if(next == '\n'){
            lineNum++;
            cout << strng << lineNum << endl;
        }
        if (file->peek() == EOF){
            token.push_back(new Token(UNDEFINED, strng, startLineNum));
            return;
        }
        if (file->peek() == '\''){
            file->get(next);
            strng += next;
            if (file->peek() != '\''){
                token.push_back(new Token(STRING, strng, startLineNum));
                return;
            }
            file->get(next);
            strng += next;
        }
    }
    file->get(next);
    strng += next;
    token.push_back(new Token(STRING, strng, startLineNum));
}

void Scanner::isSingleLineComment(char next){
    string SLC;
    SLC += next;
    while(file->peek() != EOF && file->peek() != '\n'){
        file->get(next);
        SLC += next;
    }
    token.push_back(new Token(COMMENT, SLC, lineNum));
}

void Scanner::isBlockComment(char next){
    int startLineNum = lineNum;
    string BC;
    BC += next;
    while(next != '|' || file->peek() != '#'){
        file->get(next);
        BC += next;
        if(next == '\n'){
            lineNum++;
            cout << BC << lineNum << endl;
        }
        if (file->peek() == EOF){
            token.push_back(new Token(UNDEFINED, BC, startLineNum));
            return;
        }
    }
    file->get(next);
    BC += next;
    token.push_back(new Token(COMMENT, BC, startLineNum));
}

void Scanner::print(){
    
    for (unsigned int i = 0; i<token.size(); i++){
        token[i]->coutToken();
        delete token[i];
    }
    cout << "Total Tokens = " << token.size() << endl;
    token.clear();
}

















