/***************************************************
 * Title: Lexical analyser for cpp source codes
 * Author: Arshia Manzari
 * Date: 22 March 2022
 * Availability: github.com/arshiamanzari
 * *************************************************/
#ifndef PARSE_H
#define PARSE_H
#include <stdlib.h>
#include <cstdio>
#include "token.h"

class Parse : public LexToken
{
private:
    std::ifstream sources;
     //given source file
    char letter_buffer;       //used to convert character to string
    std::string word_buffer;
    bool inside_doublequotes = false;
    bool punctuator,constant;
public:
    void display();
    void init(), read();
    bool isKeyword(),
    isPunctuator(),
    isConstant(),
    isOperator();
};

#endif // PARSE_H
