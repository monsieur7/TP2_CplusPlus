#include "Encrypt.h"


std::string& Encrypt::getCipher(){
    return _cipher;
} // FOR DEBUG
std::string& Encrypt::getPlain(){
    return _plain;
}


void Encrypt::read(std::string file){
    _file.open(file, std::ios::in);
    std::stringstream reading;
    reading << _file.rdbuf(); // reading entire file at once
    _plain = reading.str();
}

void Encrypt::write(std::string file){
    _file.open(file, std::ios::out);
    _file << _cipher; // writing entire string
}



