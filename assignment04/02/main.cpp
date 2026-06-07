#include <iostream>
#include "Vehicle.h"
#include "Engine.h"

int main() {
    Engine e1(250, "Diesel");
    Engine e2(150, "Petrol");

    Vehicle v1("Volvo", "XC90", 2024, e1);
    Vehicle v2("Toyota", "Corolla", 2023, e2);
    Vehicle v3("Volvo", "XC90", 2024, e1);

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    std::cout << "v1 == v3? " << (v1 == v3) << std::endl;
    std::cout << "v1 == v2? " << (v1 == v2) << std::endl;

    return 0;
}
