// Source file for anum type
#include "anum.h"

std::ostream& operator << (std::ostream &output, Anum const& someNum){
    
    // todo: delete this section later, only used for debugging now
    output << "Your num is:   ";
    
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
    std::vector <int> numvec;
    
    // output instructions and make sure std::ostream is clear by flushing
    //std::cout.flush();
    
    // todo: delete this section later, only used for debugging for now
    std::cout << "Enter integer: ";
    std::cout.flush();
    
    // set someNum to be nonNegative
    someNum.isNegative = 0;
    
    // clear all leading whitespace
    input >> std::ws;
    
    // check if user wants positive or negative number
    // if positive or negative, eat the first char
    if (input.peek() == '-') someNum.isNegative = 1;
    if (input.peek() == '+' || input.peek() == '-') input.get();
    
    // infinite loop, adding infinite amount of numbers to numvec
    while (1){
        buffer = input.peek();
        int i;
        
        if (buffer >= '0' && buffer <= '9') i = (int)(buffer - '0');
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


Anum operator + (Anum num1, Anum num2){
    // We want the bigger one (in absolute value) to be in num1
    if (!num1.is_greater_than(num2)) std::swap(num1, num2);
    
    // since num1 now stores the largest element,
    // the return value of num1 will have the correct
    // sign (- or +)
    
    // The size of the new vector will never exceed 1+the size of the largest one
    unsigned sizevec = num1.num.size()+1;
    
    // We append 0's to the fronts of both numbers, to make the sizes equal to sizevec
    num1.num.push_back(0);
    for (unsigned i = num2.num.size(); i < sizevec; i++) {
        num2.num.push_back(0);
    }
    
    // if both are negative, just add every element to the corresponding element
    if (num1.isNegative == num2.isNegative) {
        for (int i = 0; i<=sizevec-1; i++){
            
            num1.num[i]+=num2.num[i];
            
            // If the number at the index is greater than 10, we need to carry
            if (num1.num[i] >= 10) {
                int wholes = num1.num[i]/10;
                num1.num[i+1]+= wholes;
                num1.num[i]-=(10*wholes);
            }
        }
        //num1.eat();
        return num1;
    }
    // if the signs of both are different, with the first one being larger
    else{
        for (int i = 0; i<=sizevec-1; i++){
            
            num1.num[i]-=num2.num[i];
            
            // if the number at the index is less than 10, we need to borrow
            if (num1.num[i] < 0) {
                int wholes = num1.num[i]/10+1;
                num1.num[i+1]-= wholes;;
                num1.num[i]+=wholes*10;
            }
        }
        //num1.eat();
        return num1;
    }

    return num1;
}

Anum operator - (Anum num1, Anum num2){
    // simply return the sum of num1 and negative num2, since + is already overloaded to subtract
    return num1 + -num2;
}

int main(int argc, char *argv[]){
    
    std::cout.sync_with_stdio(false);
    
    Anum someguy;
    std::cin >> someguy;
    std::cout << someguy << std::endl;
    std::cout << someguy + someguy << std::endl;
    
    return 0;
}