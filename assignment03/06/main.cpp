#include "Cat.h"
#include "Dog.h"

#include <string>
#include <iostream>


int main() {


    Mammal* dog = new Dog("Musti");
    Mammal* cat = new Cat("Misu");

    std::cout << dog->makeSound() << std::endl;
    std::cout << cat->makeSound() << std::endl; 








    return 0;

}
