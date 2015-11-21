// Header file for anum type
#ifndef __anum_define__
#define __anum_define__

#include <vector>
#include "iostream"
#include <iomanip>

#endif

class Anum {
    std::vector <int> num;
    unsigned number;
    
public:
    Anum(unsigned num): number(num) {  };
    
    friend std::ostream& operator << (std::ostream &output, Anum const &someNum);
    friend std::istream& operator >> (std::istream &input,  Anum const &someNum);
    
    int getNum(){
        return number;
    }
    
};