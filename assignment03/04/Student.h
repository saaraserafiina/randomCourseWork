#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>

class Student : public Person {

    private:
        std::string studentId;

    public:
        Student(std::string name, std::string studentId);
         std::string getStudentId() const;        
        std::string toString() const override;
        std::string drink() const override;
         
        };




#endif
