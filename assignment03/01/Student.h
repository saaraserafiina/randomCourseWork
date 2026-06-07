#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {

    private:  
        std::string studentId;

    public:
        Student(std::string name, int age, std::string studentId);
        std::string getStudentId() const;
        void setStudentId(const std::string& id);

        std::string toString() const;


};










#endif
