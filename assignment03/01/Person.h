#ifndef PERSON_H
#define PERSON_H

#include <string>


class Person {

    private:
        std::string name;
        int age;

    public:
        std::string getName() const;
        int getAge() const;
        void setName(const std::string& name);
        void setAge(int age);
        Person(std::string name, int age);

        std::string toString() const;
};






#endif
