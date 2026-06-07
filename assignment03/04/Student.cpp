#include "Student.h"
#include <string>

Student::Student(std::string name, std::string studentId)
    : Person(name),
    studentId(studentId)
{}

std::string Student::getStudentId() const {

    return studentId;

}

std::string Student::drink() const {

    return "Drinking energy drink";
}

std::string Student::toString() const {
    
    return "Student(" + getName() + ", " + studentId + ")";

}
