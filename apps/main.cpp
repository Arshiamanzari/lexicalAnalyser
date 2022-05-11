#include <iostream>
#include "parse.h"
int main()
{
    Parse *run = new Parse;
    run->init();
    run->read();
    run->display();

    return 0;
}
