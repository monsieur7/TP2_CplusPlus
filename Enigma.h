#pragma once
#include "Encrypt.h"
#include <vector>
class Enigma : public Encrypt {

    private:
        std::vector<std::string> _key; // one rotor but a vector for later
        std::vector<int> _offset;
        std::string _reflector = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        int offsetReverse(char c, std::string key);
        int _numRotor = 1;
    public:
        Enigma(std::string key); // only one rotor
        void Encode();
        void Decode();
        std::string getCipher(); // FOR DEBUG
        void setPlain(std::string plain);
        void reset();
        void setOffset(std::vector<int> offset);

        void swap() {
            _plain = _cipher;
        }; // for debug
        
};