#pragma once
#include "Encrypt.h"
#inclde <vector>
class Enigma : public Encrypt {

    private:
        std::vector<std::string> key; // one rotor but a vector for later
    public:
        Enigma(std::string key); // only one rotor
        void Encrypt() override;
        void Decryp() override;
        
}