/* ******************************
 * implementation of parse class*
 * ******************************/
#include "parse.h"
#include "token.h"

void Parse::init()
{
    punctuatorsVec = new std::vector<char>;
    operatorsVec = new std::vector<char>;
    constantsVec = new std::vector<char>;
    keywordsVec = new std::vector<std::string>;
    identifiersVec = new std::vector<std::string>;
    invalid_identifiersVec = new std::vector<std::string>;
}

void Parse::read()
{
    std::ifstream source;
    source.open ("input.txt");
    if (source)
    {
        while(!source.eof())
        {
            source.get( letter_buffer );
            if (letter_buffer == '"'){
                if(!inside_doublequotes)
                    inside_doublequotes = true;
                else
                {
                    inside_doublequotes = false;
                }
            }
            if(inside_doublequotes){
//                std::cout << "\n[dev] inside doueblequotes!";
                continue;
            }
            if(isOperator()){
//                std::cout << "\n[dev] operator: " << letter_buffer <<"!\n\n";
                operatorsVec->push_back(letter_buffer);
                continue;
            }
            if(isPunctuator()){
//                std::cout << "\n[dev] punctuator: " << letter_buffer <<"\n\n";
                punctuatorsVec->push_back(letter_buffer); //punctuator collect
                punctuator = true;
                continue;
            }
            if(isConstant()){
//                std::cout << "\n[dev] constant: " << letter_buffer << "\n\n";
                constantsVec->push_back(letter_buffer);  //constants collect
                constant = true;
            }

            if (letter_buffer != ' ' && letter_buffer != '\n') //if space or new line
            {
                word_buffer += letter_buffer;
            }
            if (letter_buffer == ' ' || letter_buffer == '\n')
            {
                if (isKeyword()) //if word_buffer is keyword
                {
                    keywordsVec->push_back(word_buffer);
//                    std::cout <<"\n[dev] keyword: " << word_buffer <<"\n\n";
                    word_buffer = "";
                    constant = false;
                    punctuator = false;
                    continue;
                }
                if (!isKeyword() && !isPunctuator() &&
                        (int)word_buffer[0] != 32 &&
                        word_buffer != "" &&
                        (int)word_buffer[0] != 34 &&
                        (int)word_buffer[0] != 10){
                    if((int)word_buffer[0] > 47 && (int)word_buffer[0] < 58){
//                        std::cout << "\n[dev] invalid identifier: " << word_buffer << "\n\n";
                        invalid_identifiersVec->push_back(word_buffer);
                        word_buffer = "";
                        constant = false;
                        punctuator = false;
                    }
                    else
                    {
//                        std::cout << "\n[dev] identifier: " << word_buffer <<"\n\n";
                        identifiersVec->push_back(word_buffer);
                        word_buffer = "";
                        constant = false;
                        punctuator = false;
                    }
                }
            }
        }
    }
    else
    {
        perror("\n [Error] File opening failed. \n");
    }
    source.close();
}

bool Parse::isKeyword()
{
    if(keywords_set.count(word_buffer) != 0){
        return true;
    }
    else return false;
}

bool Parse::isOperator()
{
    if(operators_set.count(letter_buffer) != 0)
        return true;
    else return false;
}

bool Parse::isPunctuator()
{
    if(puctuators_set.count(letter_buffer) != 0)
        return true;
    else return false;
}

bool Parse::isConstant()
{
    if(constants_set.count(letter_buffer) != 0)
        return true;
    else return false;
}
void Parse::display()
{
    std::cout << " [i] Punctuator: ";
    for(auto i : *punctuatorsVec)
        std::cout << i <<" , ";

    std::cout << "\n [i] Operators: ";
    for(auto i : *operatorsVec)
        std::cout << i <<" , ";

    std::cout << "\n [i] Constants: ";
    for(auto i : *constantsVec)
        std::cout << i <<" , ";

    std::cout << " [i] Keywords: ";
    for(auto i : *keywordsVec)
        std::cout << i <<" , ";

    std::cout << " [i] identifiers: ";
    for(auto i : *identifiersVec)
        std::cout << i << " , ";

    std::cout << " [i] Errors (Inavild Identifier) : ";
    for(auto i : *invalid_identifiersVec)
        std::cout << i <<" , " <<std::endl;

    std::cout << "\n [i] Analyised Results Summary:\n";
    std::cout << "⸻⸻⸻⸻⸻⸻⸻⸻\n";
    std::cout << " Totall Puntuators: " << punctuatorsVec->size() << "\n";
    std::cout << " Totall Operatpors: " << operatorsVec->size() << "\n";
    std::cout << " Totall Constants: " << constantsVec->size() << "\n";
    std::cout << " Totall Keywords: " << keywordsVec->size() << "\n";
    std::cout << " Totall Identifiers: " <<identifiersVec->size() << "\n";
    std::cout << " Totall Errors:(Invaid Identifier)" << invalid_identifiersVec->size() << "\n";
    std::cout << "⸻⸻⸻⸻⸻⸻⸻⸻\n";

}
