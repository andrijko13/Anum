#include <iostream>
#include "anum.h"

int main(int argc, char *argv[]){
    
    using namespace std;
    
    cout.sync_with_stdio(false);
    
    Anum someguy =  "34712983571844132075914823651043098701479083570127349807141234";
    Anum otherguy = "-1147298307019874389719057180430140138901759037140938274723130";
    
    cout << someguy+otherguy << endl;
    
    
    return 0;
}

