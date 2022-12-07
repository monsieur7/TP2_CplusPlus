#include "Enigma.h"

void Enigma::Encode(){
    _cipher = "";
    for(char c : _plain){
        for(int i = 0; i < 1; i ++){
            if(c == '\n'){
                _cipher.push_back('\n');
            }
            else {
                int local_offset = (c - 65 + _offset.at(i)) % 26; // everything in MAJ
                int new_offset = _key.at(i)[local_offset];
                char new_char = (char) (new_offset+65);
                _cipher.push_back(new_char);
                _offset.at(i) = (_offset.at(i) + 1)%27;
            }
        }
            
    }
}
    
Enigma::Enigma(std::string key){
    if(key.length() != 26){
        throw std::runtime_error("not the right key lenght");
    }
    else {
        _key.push_back(key);

    }
    _offset.resize(1); // one rotor
    _offset.clear(); // set it at 0 if not already done 
}


std::string Enigma::getCipher(){
    return _cipher;
} // FOR DEBUG

void Enigma::setPlain(std::string plain){
    _plain = plain;
}