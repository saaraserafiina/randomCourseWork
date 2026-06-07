#ifndef DOG_H
#define DOG_H
#include "Mammal.h"


class Dog : public Mammal {


    public:
        Dog(std::string name);
        std::string makeSound() const override;

};



#endif
