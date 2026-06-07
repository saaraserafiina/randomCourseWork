#include "Student.h"

#include <string>

Student::Student(std::string name, std::string studentId) 
    : Person(name),
      studentId(studentId)
{}

std::string Student::drink() const {
    return "Drinking energy drink";
}

std::string Student::excuseForBeingLate() const {

    return "My alarm didn't go off";

}
