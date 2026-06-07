#include <iostream>
#include "Person.h"
#include "Student.h"


int main() {


    Person p("Alice", 22);
    Student s("Bob", 20, "S123");
    
    std::cout << p.toString() << std::endl;
    std::cout << s.toString() << std::endl;

    return 0;

}
