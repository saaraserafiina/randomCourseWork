#include "Person.h"
#include <string>


Person::Person(std::string name, int age)
    : name(name), age(age) {}

std::string Person::getName() const {
    
    return name;
}

int Person::getAge() const {

    return age;

}

void Person::setName(const std::string& name) {

    this->name = name;

} 

void Person::setAge(int age) {

    this->age = age;

}

std::string Person::toString() const {

    return "Person(" + name + ", " + std::to_string(age) + ")";

}
