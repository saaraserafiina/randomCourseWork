#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "Engine.h"
#include <iostream>



class Vehicle {
    
    private:
        std::string brand;
        std::string model;
        int year;
        Engine engine;
        
    public:
        Vehicle(const std::string& brand, const std::string& model,
                int year, const Engine& engine);
        std::string toString() const;
        
        std::string getBrand() const;
        std::string getModel() const;
        int getYear() const;
        Engine getEngine() const;

        friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
        bool operator==(const Vehicle& other) const;
};




#endif
