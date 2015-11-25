// Header file for anum type
#ifndef __anum_define__
#define __anum_define__

#include <vector>       // std::vector
#include <iostream>     // std::cin, std::cout, etc...
#include <iomanip>      // used for stream manipulations
#include <cctype>       // std::isdigit

class Anum {
    
    std::vector <int> num;
    bool isNegative;
    
    bool is_greater_than(Anum num2){
        
        if (num.size() != num2.num.size()){
            if (num.size() > num2.num.size()) return 1;
            else return 0;
        }
        
        else{
            for (int i = num.size()-1; i>=0; i--) {
                if (num[i]>num2.num[i]){
                    return 1;
                }
            }
        }
        
        return 0;
    }
    
    Anum eat(){
        for (int i = num.size()-1; i >= 0; i--) {
            if (num[i] != 0) {
                return *this;
            }
            else{
                num.pop_back();
            }
        }
        return *this;
    }
    
public:
    Anum() { num.push_back(0); };
    
    friend std::ostream& operator << (std::ostream &output, Anum const &someNum);
    friend std::istream& operator >> (std::istream &input,  Anum &someNum);
    friend Anum operator + (Anum num1, Anum num2);
    friend Anum operator - (Anum num1, Anum num2);
    
    Anum operator -() {
        Anum number = *this;
        number.isNegative = !number.isNegative;
        return number;
    }
    
    Anum operator -= (Anum const &num1){
        *this = *this-num1;
        return *this;
    }
    
    Anum operator += (Anum const &num1){
        *this = *this+num1;
        return *this;
    }
    
};

#endif