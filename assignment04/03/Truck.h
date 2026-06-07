#ifndef TRUCK_H
#define TRUCK_H
#include <string>
#include "Vehicle.h"

class Truck : public Vehicle {

        private:
            int cargoCapacity;
        public:
            Truck(const std::string& brand, const std::string& model,
                    int year, const Engine& engine, int cargoCapacity);
           
            int getCargoCapacity() const;
            std::string purpose() const override;
            Vehicle* clone() const override;
            std::string toString() const override;
    
};


#endif
