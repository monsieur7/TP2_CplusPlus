#pragma once
#include "Encrypt.h"
#include <vector>
class Enigma : public Encrypt {

    private:
        std::vector<std::string> _key; // one rotor but a vector for later
        std::vector<int> _offset;
        //std::string _reflector = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        std::string _reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT"; // B REFLECTOR
        int offsetReverse(char c, std::string key, int offset);
        int _numRotor = 3;
    public:
        Enigma(std::string rotor1, std::string rotor2,  std::string rotor3); // only one rotor
        void Encode();
        void Decode();
        std::string& getCipher(); // FOR DEBUG
        std::string& getPlain();
        void setPlain(std::string plain);
        void reset(); // reset offset at 0
        void setOffset(std::vector<int> offset);

        void swap() {
            _plain = _cipher;
        }; // for debug
        
};