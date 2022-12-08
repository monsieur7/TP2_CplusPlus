#include <iostream>
#include "Enigma.h"
int main(int argc, char ** argv){

    //Enigma e1("DMTWSILRUYQNKFEJCAZBPGXOHV", "HQZGPJTMOBLNCIFDYAWVEUSRKX");
    Enigma e1("EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO"); // THREE ROTORS ENIGMA => https://en.wikipedia.org/wiki/Enigma_rotor_details
    // B REFLECTOR IS USED
    // THE MACHINE IS SYMETRIC SO DECODE AND ENCODE DO THE SAME THING EXCEPTED THAT encode goes from plain to text and decode does the reverse
    e1.read("../test.txt");
    e1.Encode();
    std::cout << "result " << e1.getCipher() << std::endl;
    e1.reset(); // RESET STATE (rotors offset)
    e1.Decode();
    std::cout << "decoded " << e1.getPlain();
    
    return 0;
}
