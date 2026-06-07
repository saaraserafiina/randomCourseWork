#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <string>
#include <iostream>


int main() {

   
    Teacher teacher("Charlie", "C++");
    std::cout << teacher.drink() << std::endl;    
    std::cout << teacher.toString() << std::endl;

    return 0;


}
