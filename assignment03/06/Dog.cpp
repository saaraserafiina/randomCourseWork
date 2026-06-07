#include "Dog.h"
#include <string>


Dog::Dog(std::string name) 
    : Mammal(name)
{}

std::string Dog::makeSound() const {

    return "Woof";

}


