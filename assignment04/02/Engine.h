#ifndef ENGINE_H
#define ENGINE_H


#include <string>

class Engine {

    private:
        int horsepower;
        std::string fuelType;

    public:
        Engine(int horsepower, const std::string& fuelType);
        Engine();
        int getHorsepower() const;
        std::string getFuelType() const;
        void setHorsepower(int hp);
        void setFuelType(const std::string& type);
        std::string toString()  const;

        friend std::ostream& operator<<(std::ostream& os, const Engine& engine);

};

#endif
