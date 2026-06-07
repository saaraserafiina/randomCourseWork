#include "Truck.h"
#include <string>



Truck::Truck(const std::string& brand, const std::string& model,
            int year, const Engine& engine, int cargoCapacity)
        : Vehicle(brand, model, year, engine), cargoCapacity(cargoCapacity)

{}

int Truck::getCargoCapacity() const {

    return cargoCapacity;

}

std::string Truck::purpose() const {

    return "Cargo transport";

}

Vehicle* Truck::clone() const {

    return new Truck(*this);

}

std::string Truck::toString() const {

    return "Truck(" + getBrand() + ", " + getModel() + ", " +
            std::to_string(getYear()) + ", " +
            getEngine().toString() + ", " + 
            std::to_string(cargoCapacity) + ")";

}

 
