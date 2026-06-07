#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {

    private:
        std::string name;
    public:
        std::string getName() const;
        virtual std::string drink() const;
        virtual std::string excuseForBeingLate() const = 0;
        virtual ~Person();
        Person(std::string name);
};



#endif
