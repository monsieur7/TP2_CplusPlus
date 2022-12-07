#pragma once
#include "Encrypt.h"
#include <vector>
class Enigma : public Encrypt {

    private:
        std::vector<std::string> _key; // one rotor but a vector for later
        std::vector<int> _offset;
        std::string _reflector = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        int offsetReverse(char c, std::string key);
        int _numRotor = 2;
    public:
        Enigma(std::string rotor1, std::string rotor2); // only one rotor
        void Encode();
        void Decode();
        std::string getCipher(); // FOR DEBUG
        void setPlain(std::string plain);
        void reset(); // reset offset at 0
        void setOffset(std::vector<int> offset);

        void swap() {
            _plain = _cipher;
        }; // for debug
        
};