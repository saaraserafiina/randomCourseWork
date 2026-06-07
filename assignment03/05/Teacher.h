#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"


class Teacher : public Person {

    private:
        std::string subject;

    public:
        std::string drink() const override;
        std::string excuseForBeingLate() const  override;
        Teacher(std::string name, std::string subject);
        

};

#endif
