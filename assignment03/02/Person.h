#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {

    public:
        int age = 1;
        int getAge() const;
        int getId() const;
        std::string getName() const;
    
    protected:
        int id = 2;

    private:
        std::string name = "Alice";

    
};

#endif
