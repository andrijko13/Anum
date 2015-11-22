// Header file for anum type
#ifndef __anum_define__
#define __anum_define__

#include <vector>       // std::vector
#include <iostream>     // std::cin, std::cout, etc...
#include <iomanip>      // used for stream manipulations
#include <cctype>       // std::isdigit

class Anum {
    
    std::vector <unsigned> num;
    unsigned number;
    bool isNegative;
    
public:
    
    Anum(unsigned num): number(num) {  };
    Anum() { num.push_back(0); };
    
    friend std::ostream& operator << (std::ostream &output, Anum const &someNum);
    friend std::istream& operator >> (std::istream &input,  Anum &someNum);
    
};

#endif