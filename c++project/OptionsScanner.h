// Generated by Flexc++ V0.98.00 on Thu, 02 Aug 2012 10:24:42 -0500

#ifndef OptionsScanner_H_INCLUDED_
#define OptionsScanner_H_INCLUDED_

// $insert baseclass_h
#include "OptionsScannerbase.h"

#include "OptionsParserbase.h"

// $insert namespace-open
namespace OPTIONS
{

// $insert classHead
class OptionsScanner: public OptionsScannerBase
{
    public:
        explicit OptionsScanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

        OptionsScanner(std::string const &infile, std::string const &outfile);

        // $insert lexFunctionDecl
        int lex();

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must
                            // be exec'ed before the patternmatching starts
};

// $insert scannerConstructors
inline OptionsScanner::OptionsScanner(std::istream &in, std::ostream &out)
:
    OptionsScannerBase(in, out)
{}

inline OptionsScanner::OptionsScanner(std::string const &infile, std::string const &outfile)
:
    OptionsScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int OptionsScanner::lex()
{
    return lex__();
}

inline void OptionsScanner::preCode()
{
    // optionally replace by your own code
}

inline void OptionsScanner::print()
{
    print__();
}

// $insert namespace-close
}

#endif // OptionsScanner_H_INCLUDED_

