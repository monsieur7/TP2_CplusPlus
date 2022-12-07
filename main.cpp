#include <iostream>
#include "Enigma.h"
int main(int argc, char ** argv){
    Enigma e1("DMTWSILRUYQNKFEJCAZBPGXOHV");
    e1.setPlain("A");
    e1.Encode();
    std::cout << "result " << e1.getCipher() << std::endl;
    e1.swap();
    e1.Encode();
    std::cout << "decoded " << e1.getCipher();
    return 0;
}
