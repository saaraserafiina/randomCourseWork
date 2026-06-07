#include "Car.h"
#include <string>



Car::Car(const std::string& brand, const std::string& model,
         int year, const Engine& engine, int passengerCount) 
   
         : Vehicle(brand, model, year, engine), passengerCount(passengerCount)
{}


int Car::getPassengerCount() const {

    return passengerCount;

}

std::string Car::purpose() const {

    return "Personal transport";
}


Vehicle* Car::clone() const {

    return new Car(*this);

}

std::string Car::toString() const {

    return "Car(" + getBrand() + ", " + getModel() + ", " + 
            std::to_string(getYear()) + ", " +      
            getEngine().toString() + ", " + 
            std::to_string(passengerCount) + ")";

}

