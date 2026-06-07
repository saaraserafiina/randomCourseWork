#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"


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
