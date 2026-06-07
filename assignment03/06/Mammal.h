#ifndef MAMMAL_H
#define MAMMAL_H
#include <string>

class Mammal {
    
    private:
        std::string name;
    public:
        std::string getName() const;
        void setName(std::string n);
        virtual std::string makeSound() const = 0;
        ~Mammal();
        Mammal(std::string name);


};







#endif
