#include "Cat.h"
#include <string>


Cat::Cat(std::string name) 
    : Mammal(name)
{}

std::string Cat::makeSound() const {

    return "Meow";

}
