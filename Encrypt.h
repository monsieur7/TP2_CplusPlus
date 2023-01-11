#pragma once
#include <string>
#include <fstream>
#include <sstream>
class Encrypt {
    protected:
        std::string _plain;
        std::string _cipher;

    public:
        std::string& getCipher(); // FOR DEBUG
        std::string& getPlain();
        virtual void Encode() = 0; // YOU NEED TO REDEFINE THESE IN THE CHILD CLASS !
        virtual void Decode() = 0;
        void read(std::string file);
        void write(std::string file);
    private:
        std::fstream _file; // file

};