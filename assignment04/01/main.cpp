#include <iostream>
#include "Engine.h"

int main() {
    Engine e1(150, "Diesel");
    std::cout << e1 << std::endl;

    Engine e2;
    std::cout << e2 << std::endl;

    e2.setHorsepower(200);
    e2.setFuelType("Petrol");
    std::cout << e2 << std::endl;

    try {
        Engine e3(-10, "Electric");
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
