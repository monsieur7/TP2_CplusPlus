#include "Enigma.h"
#include <iostream>
void Enigma::Encode(){
    _cipher = "";
    for(char c : _plain){
            if(c == '\n'){
                _cipher.push_back('\n');
            }
            else if(c == ' '){
            _cipher.push_back(' ');

            }
            else {
                char new_char;
                int local_offset;
                for(int i = 0; i < _numRotor; i ++){
                if(i == 0){
                    local_offset = (c - 65 + _offset.at(i)) % 26; // everything in MAJ
                }
                else {
                    local_offset = (new_char - 65 + _offset.at(i)) % 26; // everything in MAJ

                }
                    new_char = _key.at(i)[local_offset];
                }
                char reflected = _reflector.at((int)new_char - 65);

                int offset_reverse;
                char reverse;

                for(int i =_numRotor-1; i >=0; i--){
                    
                    if(i == _numRotor - 1){
                      offset_reverse = offsetReverse(reflected, _key.at(i),0);
                    }
                    else {
                     offset_reverse = offsetReverse(reverse, _key.at(i), 0);

                    }
                    if(offset_reverse - _offset.at(i) < 0){ // because if we want to offset A => it need to be a Z
                        offset_reverse = 26 + (offset_reverse - _offset.at(i));
                    }
                    else {
                        offset_reverse = (offset_reverse - _offset.at(i));
                    }
                    reverse = (char)(65+offset_reverse); // reverse connexion
                }
                

                _cipher.push_back(reverse);
                _offset.at(0) = _offset.at(0) + 1;

                for(int i = 1; i < _numRotor; i++){
                    if(_offset.at(i-1) == 27){
                        _offset.at(i-1) = 0;
                        _offset.at(i) += 1;
                    }
                }
            }
        }
            
}
void Enigma::Decode(){
_plain = "";
    for(char c : _cipher){
            if(c == '\n'){
                _plain.push_back('\n');
            }
            else if(c == ' '){
            _plain.push_back(' ');

            }
            else {
                char new_char;
                int local_offset;
                for(int i = 0; i < _numRotor; i ++){
                if(i == 0){
                    local_offset = (c - 65 + _offset.at(i)) % 26; // everything in MAJ
                }
                else {
                    local_offset = (new_char - 65 + _offset.at(i)) % 26; // everything in MAJ

                }
                    new_char = _key.at(i)[local_offset];
                }
                char reflected = _reflector.at((int)new_char - 65);

                int offset_reverse;
                char reverse;

                for(int i =_numRotor-1; i >=0; i--){
                    
                    if(i == _numRotor - 1){
                      offset_reverse = offsetReverse(reflected, _key.at(i),0);
                    }
                    else {
                     offset_reverse = offsetReverse(reverse, _key.at(i), 0);

                    }
                    if(offset_reverse - _offset.at(i) < 0){ // because if we want to offset A => it need to be a Z
                        offset_reverse = 26 + (offset_reverse - _offset.at(i));
                    }
                    else {
                        offset_reverse = (offset_reverse - _offset.at(i));
                    }
                    reverse = (char)(65+offset_reverse); // reverse connexion
                }
                

                _plain.push_back(reverse);
                _offset.at(0) = _offset.at(0) + 1;

                for(int i = 1; i < _numRotor; i++){
                    if(_offset.at(i-1) == 27){
                        _offset.at(i-1) = 0;
                        _offset.at(i) += 1;
                    }
                }
            }
        }}   
Enigma::Enigma(std::string rotor1, std::string rotor2,  std::string rotor3){
    if(rotor1.length() != 26 || rotor2.length() != 26 ||  rotor3.length() != 26 ){
        throw std::runtime_error("not the right key lenght");
    }
    else {
        _key.push_back(rotor1);
        _key.push_back(rotor2);
        _key.push_back(rotor3);

    }
    _offset.resize(_numRotor); // one rotor
    for(int i = 0; i < _numRotor; i++){
        _offset.at(i) = 0;
    }
}


std::string& Enigma::getCipher(){
    return _cipher;
} // FOR DEBUG
std::string& Enigma::getPlain(){
    return _plain;
}
void Enigma::setPlain(std::string plain){
    _plain = plain;
}

int Enigma::offsetReverse(char c, std::string key, int offset){
    for(int i = 0; i < 26; i++){
        if(key.at(i+offset) == c){ // i + offset because we need to take into account the fact that the rotor may have rotated (by offset), so the output letter that we are searching for is not the same
            return (i);
        }
    }
    return 0; // ERROR TODO
}

void Enigma::reset(){
    for(int i = 0; i < _numRotor; i++){
        _offset.at(i) = 0;
    }
}