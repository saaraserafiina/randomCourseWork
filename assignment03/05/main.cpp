#include "Student.h"
#include "Teacher.h"

#include <iostream>


int main() {



    Person* p1 = new Student("Alice", "s123");
    Person* p2 = new Teacher("Bob", "Math");

    std::cout << p1->getName() << ": " << p1->drink() << std::endl;
    std::cout << p1->excuseForBeingLate() << std::endl;

    std::cout << p2->getName() << ": " << p2->drink() << std::endl;
    std::cout << p2->excuseForBeingLate() << std::endl;

    delete p1;
    delete p2;

    return 0;





}
