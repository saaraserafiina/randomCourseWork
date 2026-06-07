#include "Teacher.h"
#include <iostream>


Teacher::Teacher(std::string name, std::string subject) 
    : Person(name), subject(subject) {}

std::string Teacher::drink() const {
    
    return "Drinking tea";


}

std::string Teacher::excuseForBeingLate() const {

    return "I was looking for the classroom";

}


