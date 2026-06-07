#ifndef CAR_H
#define CAR_H


#include <string>
#include "Vehicle.h"

class Car : public Vehicle {

    private:
        int passengerCount;
    public:
        Car(const std::string& brand,
            const std::string& model,
            int year,
            const Engine& engine,
            int passengerCount);

        int getPassengerCount() const;
        std::string purpose() const override;
        Vehicle* clone() const override;
        std::string toString() const override;



};




#endif
