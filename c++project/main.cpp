// main.cpp
// Mara Kim

#include "main.h"
#include "Initializer.h"
#include "Options.h"
#include <iostream>


inline void printshorthelp()
{
    // output usage info
    std::cout << "Usage: " << PROGRAM_NAME << '\n';
}

void printhelp()
{
    // output help
    printshorthelp();
    std::cout << "<Description>\n"
              << "Option\t\tGNU long option\t\tMeaning\n"
              << "-h, -?\t\t--help\t\t\tShow this message\n"
              << "-v\t\t--version\t\tOutput program version\n";
}

int main(int argc, const char* argv[])
{

    // Initialize
    Initializer init(argc, argv);

    // process arguments
    bool stop = false;
    if(init.flag("version") ||
       init.flag('v')) {
        // output version
        std::cout << PROGRAM_NAME << ' ' << SOURCE_VERSION << "\n";
        stop = true;
    }
    if(init.flag("help") ||
       init.flag('h') ||
       init.flag('?')) {
        printhelp();
        stop = true;
    }

    if(stop) {
        return 0;
    }


    // run program

    std::cout << "DB_HOST = " << Options::Instance()->get(DB_HOST) << std::endl;
    std::cout << "DB_NAME = " << Options::Instance()->get(DB_NAME) << std::endl;
    std::cout << "DB_USER = " << Options::Instance()->get(DB_USER) << std::endl;

    std::cout << "AVOGADRO = " << Options::Instance()->get(AVOGADRO) << std::endl;

    return 0;
}