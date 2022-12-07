#include <iostream>
#include "Enigma.h"
int main(int argc, char ** argv){
    Enigma e1("DMTWSILRUYQNKFEJCAZBPGXOHV");
    e1.setPlain("A");
    e1.Encode();
<<<<<<< HEAD
    std::cout << "result " << e1.getCipher() << std::endl;
    e1.swap();
    e1.Encode();
    std::cout << "decoded " << e1.getCipher();
=======
    std::cout << "result: " << e1.getCipher() << "\n";
>>>>>>> e8cca6eb05d787e26646860da1737beda6fd1f6d
    return 0;
}
