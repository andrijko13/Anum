// Source file for anum type
#include "anum.h"

std::ostream& operator << (std::ostream &output, Anum const& someNum){
    
    // todo: delete this section later, only used for debugging now
    output << "Your num is: ";
    
    // print negative sign if negative number
    if (someNum.isNegative) output.put('-');
    
    // print the digits. num vector sequence is tail to head
    for (int i = someNum.num.size()-1; i >= 0; i--) {
        output.put('0'+someNum.num[i]);
    }
    
    return output;
}

std::istream& operator >> (std::istream &input, Anum& someNum){
    
    // declare variables
    char buffer;
    std::vector <unsigned> numvec;
    
    // output instructions and make sure std::ostream is clear by flushing
    // todo: delete this section later, only used for debugging for now
    std::cout << "Enter integer: ";
    std::cout.flush();
    
    // set someNum to be nonNegative
    someNum.isNegative = 0;
    
    // clear all leading whitespace
    input >> std::ws;
    
    // check if user wants positive or negative number
    // if negative, eat the first char
    if (input.peek() == '-') someNum.isNegative = 1;
    if (input.peek() == '+' || input.peek() == '-') input.get();
    
    // infinite loop, adding infinite amount of numbers to numvec
    while (1){
        buffer = input.peek();
        unsigned i;
        
        if (buffer >= '0' && buffer <= '9') i = (unsigned)(buffer - '0');
        else if (buffer == ' ' || buffer == '\n' || buffer == '\t') break;
        else{
            input.setstate(std::ios_base::failbit);
            
            return input;
        }
        
        input.get();
        numvec.push_back(i);
    }
    
    // no failbit set,
    someNum.num.clear();
    
    // store each unsigned in numvec into num vector
    for (int i = numvec.size()-1; i>=0; i--) {
        someNum.num.push_back(numvec[i]);
    }
    
    return input;
}

int main(int argc, char *argv[]){
    
    Anum someNumber;
    std::cin >> someNumber;
    std::cout << someNumber << std::endl;
    return 0;
}