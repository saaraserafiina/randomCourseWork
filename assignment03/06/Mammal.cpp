#include "Mammal.h"


Mammal::Mammal(std::string name) 
    : name(name) {}


std::string Mammal::getName() const {

    return name;
}

void  Mammal::setName(std::string n) {

    name = n;

}

Mammal::~Mammal() 
{}



