#pragma once
#include <string>
#include <fstream>
#include <sstream>
class Encrypt {
    protected:
        std::string _plain;
        std::string _cipher;

    public:
        //Encrypt(); // no need for it
        virtual void Encode() const = 0; // YOU NEED TO REDEFINE THESE IN THE CHILD CLASS !
        virtual void Decode() const = 0;

        void read(std::string file);
        void write(std::string file);
    private:
        std::fstream _file; // file

};