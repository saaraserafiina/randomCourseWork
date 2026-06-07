#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"


class Student : public Person {

    private:
        std::string studentId;

    public:
        std::string drink() const override;
        std::string excuseForBeingLate() const override;
        std::string getStudentId() const;
        Student(std::string name, std::string studentId);


};






#endif
