#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {

    private:
        std::string name;
    
    public:
        Person(const std::string& name);
        std::string getName() const;
        virtual std::string toString() const;
        virtual ~Person() = default;
       virtual  std::string drink() const;
};





#endif
