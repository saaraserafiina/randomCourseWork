#include "Teacher.h"
#include "Person.h"

Teacher::Teacher(std::string name, std::string subject)
    : Person(name),
     subject(subject) 
{}


std::string Teacher::getSubject() const {

    return subject;
}

std::string Teacher::drink() const {

    return "Drinking tea";
    
}

std::string Teacher::toString() const {


    return "Teacher(" + getName() + ", " +  subject + ")";
}
