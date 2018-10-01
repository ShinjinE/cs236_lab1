//
//  main.cpp
//  Lab1-Lexical-analyzer
//
//  Created by Shinjin Ethan Harris on 9/24/18.
//  Copyright © 2018 Shinjin Ethan Harris. All rights reserved.
//

#include <iostream>
#include <string>
#include "Token.h"
#include "Scanner.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc > 1){
        string filename = argv[1];
        ifstream file;
        file.open(filename);
        if (!file.good()){
            cout << "File " << filename << " is not acceptable" << endl;
            file.close();
            return 0;
        }
        else {
            Scanner* scan;
            scan = new Scanner(file);
            scan->Lex();//begin to scan
            scan->print();//print out the vector of tokens
            delete scan;
        }
        file.close();
    }
    return 0;
}















