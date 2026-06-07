#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Engine.h"

int main() {
    Car car("Volvo", "XC90", 2024, Engine(250, "Diesel"), 5);
    Truck truck("Scania", "R500", 2023, Engine(500, "Diesel"), 25);

    Vehicle* vehicles[] = {&car, &truck};

    for (Vehicle* v : vehicles) {
        std::cout << v->toString() << std::endl;
        std::cout << "Purpose: " << v->purpose() << std::endl;
    }

    return 0;
}
