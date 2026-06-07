#include "Person.h"
#include "Student.h"

#include <string>
#include <iostream>


int main() {


    Person person;
    std::cout <<  person.age << std::endl;
   std::cout <<  person.getName() << std::endl;
    std::cout << person.getId() << std::endl;




    return 0;

}
