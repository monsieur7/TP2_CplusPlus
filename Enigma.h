#pragma once
#include "Encrypt.h"
#include <vector>
class Enigma : public Encrypt {

    private:
        std::vector<std::string> _key; // one rotor but a vector for later
        std::vector<int> _offset;
    public:
        Enigma(std::string key); // only one rotor
        void Encode();
        void Decode();
        std::string getCipher(); // FOR DEBUG
        void setPlain(std::string plain);
        
};