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
    
    // returns 1 if num is greater than the num in the argument
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
    
    // Used to remove all 0's at the front of an anum
    Anum eat(){
        for (int i = num.size()-1; i >= 0; i--) {
            if (num[i] != 0) {
                return *this;
            }
            else{
                if (num.size()>1) num.pop_back();
            }
        }
        return *this;
    }
    
    // pad with x zero's
    Anum pad(int const &x){
        for (int y = x; y>0; y--) {num.insert(num.begin(),0);}
        return *this;
    }
    
    //returns the last digit of the number
    long long last_digit(){
        return (*this).num[0];
    }
    
public:
    Anum() { num.push_back(0); isNegative = 0;};         // Default initializes to 0
    Anum(long long num1){
        num.clear();
        isNegative = 0;
        if (num1 < 0) {isNegative = 1; num1*=-1;}
        if (num1 < 10) {num.push_back(num1); return;}
        while ((num1/10) > 0) {
            num.push_back(num1%10);
            num1/=10;
        }
        // above will leave num1 as a single digit
        num.push_back(num1%10);
    }
    Anum(char const * num1){                      // Allow initialization using a string
        char buffer;
        std::vector <int> numvec;
        
        isNegative = 0;
        unsigned counter = 0;
        buffer = num1[counter];
        int i;
        
        if (buffer == '-') isNegative = 1;
        if (buffer == '-' || buffer == '+') {
            counter++;
            buffer = num1[counter];
        }
        
        while (buffer) {
            if (buffer >= '0' && buffer <= '9') i = (int)(buffer - '0');
            else if (buffer == ' ' || buffer == '\n' || buffer == '\t') {std::cout << "nl";break;}
            else throw std::invalid_argument("String initialization of Anum failed. Invalid argument");
            
            numvec.push_back(i);
            counter++;
            buffer = num1[counter];
        }
        
        num.clear();
        for (int j = numvec.size()-1; j >=0; j--) {
            num.push_back(numvec[j]);
        }
    }

    
    friend std::ostream& operator << (std::ostream &output, Anum const &someNum);
    friend std::istream& operator >> (std::istream &input,  Anum &someNum);
    friend Anum operator + (Anum num1, Anum num2);
    friend Anum operator - (Anum num1, Anum num2);
    friend Anum operator * (Anum num1, Anum num2);
    
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
    
    Anum operator = (Anum const& num1){
        num = num1.num;
        isNegative = num1.isNegative;
        return num1;
    }
    
    
};

#endif
