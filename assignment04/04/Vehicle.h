#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "Engine.h"


class Vehicle {

    private:
        std::string brand;
        std::string model;
        int year;
        Engine engine;

    public:
        Vehicle(const std::string& brand,
                const std::string& model,
                int year,
                Engine engine);
        std::string getBrand() const;
        std::string getModel() const;
        int getYear() const;
        Engine getEngine() const;
        
        virtual std::string purpose() const = 0;
        virtual Vehicle* clone() const = 0;
        virtual std::string toString() const;
       virtual  ~Vehicle();

};





#endif
