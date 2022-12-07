#include <iostream>
#include "Enigma.h"
int main(int argc, char ** argv){
    Enigma e1("DMTWSILRUYQNKFEJCAZBPGXOHV", "HQZGPJTMOBLNCIFDYAWVEUSRKX");
    e1.setPlain("ABC");
    e1.Encode();
    std::cout << "result " << e1.getCipher() << std::endl;
    e1.swap();
    e1.reset();
    e1.Encode();
    std::cout << "decoded " << e1.getCipher();
    return 0;
}
