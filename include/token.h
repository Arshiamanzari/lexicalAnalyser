/***************************************************
 * Title: Lexical analyser for cpp source codes
 * Author: Arshia Manzari
 * Date: 22 March 2022
 * Availability: github.com/arshiamanzari
 * *************************************************/

#ifndef TOKEN_H  // Lexical tokens definition
#define TOKEN_H
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

struct LexToken //lexical data types and methods
{
    const std::set<std::string> keywords_set = {"if", "esle", "while",
                                                "do", "break", "continue",
                                                "int", "double",
                                                "float", "return",
                                                "char", "case", "iostream",
                                                "long", "short",
                                                "typedef", "switch",
                                                "unsigned", "void",
                                                "static", "struct",
                                                "sizeof","long",
                                                "volatile", "typedef",
                                                "enum", "const",
                                                "union", "extern",
                                                "bool", "cout","namespace",
                                                "std","using", "main","include"};

    const std::set<char> puctuators_set = {'!', '%', '^', '&', '*', '(', ')',
                                           '-', '+', '=', '{','}', '|', '~',
                                           '[', ']' ,'\\', ';', '\'', ':',
                                           '<', '>', '?', ',', '.', '/', '#'};

    const std::set<char> operators_set = {'+', '-', '*',
                                          '/', '>', '<',
                                          '=', '|', '&'};
    const std::set<char> constants_set = {'0', '1', '2', '3',
                                          '4', '5', '6',
                                          '7','8' , '9'};
    std::vector<char> *punctuatorsVec{};
    std::vector<char> *operatorsVec{};
    std::vector<char> *constantsVec{};
    std::vector<std::string> *keywordsVec{};
    std::vector<std::string> *identifiersVec{};
    std::vector<std::string> *invalid_identifiersVec{};
};

#endif // TOKEN_H
