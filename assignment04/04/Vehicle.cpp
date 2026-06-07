#include "Vehicle.h"
#include <string>


Vehicle::Vehicle(const std::string& brand, const std::string& model, int year, Engine engine)
    : brand(brand), model(model), year(year), engine(engine) {}


std::string Vehicle::getBrand() const {

    return brand;

}

std::string Vehicle::getModel() const {

    return model;

}

int Vehicle::getYear() const {

    return year;
}


Engine Vehicle::getEngine() const {
    return engine;
}


std::string Vehicle::toString() const {

    return "Vehicle(" + brand + ", " + model + ", " + std::to_string(year) + ", " + engine.toString() + ")";
}

Vehicle::~Vehicle() {}



