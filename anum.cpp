// Source file for anum type
#include "anum.h"

std::ostream& operator << (std::ostream &output, Anum const &someNum){
    output << "Your num is: ";
    output << someNum.number;
    output << "\n";
    
    return output;
}

std::istream& operator >> (std::istream &input, Anum const &someNum){
    char buffer[101];
    std::cout << "Enter number (max 100 digits): ";
    input.getline(buffer, 101);
    std::cout << "Input is: " << buffer << ". Size of input:  " << input.gcount()-1 << std::endl;
    return input;
}

int main(int argc, char *argv[]){
    
    Anum someNumber(300);
    std::cout << someNumber;
    std::cin >> someNumber;
    
    return 0;
}