// test.cpp
#include "adhesive.h"

std::string f()
{
    return "Hello";
}

int main(int argc, char** argv)
{
    adhesive::a thing;
    thing.bind("thing",f);
    thing.handle(argc,argv);
    return 0;
}