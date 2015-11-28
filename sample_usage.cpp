#include <iostream>
#include "anum.h"

int main(int argc, char *argv[]){
    
    using namespace std;
    
    cout.sync_with_stdio(false);
    
    Anum someguy =  "17846123578133421674174";
    Anum someguy2 = "1141263740198714907281";
    Anum ans = someguy * someguy2;
    cout << ans << endl;
    return 0;
}

