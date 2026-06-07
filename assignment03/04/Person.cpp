#include "Person.h"

#include <string>

Person::Person(const std::string& name)
    : name(name) {}

std::string Person::getName() const {
    return name;
}

std::string Person::toString() const {
    
    return "Person(" + name + ")";   

}

std::string Person::drink() const {

    return "Drinking water";

}
