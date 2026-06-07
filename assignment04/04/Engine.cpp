#include "Engine.h"
#include <string>
#include <stdexcept>


Engine::Engine()
    : horsepower(0), fuelType("Unknown") {}


Engine::Engine(int horsepower, const std::string& fuelType)
    : horsepower(horsepower), fuelType(fuelType) {

    if (horsepower < 0) {

        throw std::invalid_argument("Horsepower cannot be negative");
    }
}


int Engine::getHorsepower() const {

    return horsepower;

}

std::string Engine::getFuelType() const {

    return fuelType;

}

void Engine::setHorsepower(int hp) {

    if (hp < 0) {
        throw std::invalid_argument("Horsepower cannot be negative");
}

    horsepower = hp;

}


void Engine::setFuelType(const std::string& type) {

    fuelType = type;

}

std::string Engine::toString() const {

    return "Engine(" + std::to_string(horsepower) + ", " + fuelType + ")";

}


std::ostream& operator<<(std::ostream& os, const Engine& engine) {

    os << engine.toString();
    return os;

}


