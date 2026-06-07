#include "Vehicle.h"


Vehicle::Vehicle(const std::string& brand, const std::string& model, int year, const Engine& engine) 
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

    return "Vehicle(" + brand + ", " + model + ", " +
            std::to_string(year) + ", " + engine.toString() + ")";

}


std::ostream& operator<<(std::ostream& os, const Vehicle& v) {

    os << v.toString();
    return os;

}

bool Vehicle::operator==(const Vehicle& other) const {

    return brand == other.brand && 
            model == other.model &&
          year == other.year;

}



