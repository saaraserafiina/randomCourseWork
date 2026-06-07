#ifndef CAT_H
#define CAT_H
#include "Mammal.h"

#include <string>

class Cat : public Mammal {

    public:
        Cat(std::string name);
        std::string makeSound() const override;

};








#endif
