#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include <string>

class Teacher : public Person {

    private:
        std::string subject;

    public:
        Teacher(std::string name, std::string subject);
        std::string getSubject() const;
        std::string toString() const;
        std::string drink() const;

};

#endif
