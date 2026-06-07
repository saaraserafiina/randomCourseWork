#include "Student.h"
#include <string>


Student::Student(std::string name, int age, std::string studentId)
    : Person(name, age), studentId(studentId) {}


std::string Student::getStudentId() const {

    return studentId;

}

void Student::setStudentId(const std::string& id) {

    studentId = id;

}


std::string Student::toString() const {

    return "Student(" + getName() + ", " + std::to_string(getAge()) + ", " + studentId + ")";

}
