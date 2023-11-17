#include <iostream>

class Vehicle {
protected:
    double totalDistance;
    double fuelLevel;
    double fuelConsumption;
    double maxFuel;

public:
    Vehicle(double fuelConsumption, double maxFuel)
        : totalDistance(0.0), fuelLevel(0.0), fuelConsumption(fuelConsumption), maxFuel(maxFuel) {}

    void drive(int kilometers) {
        double requiredFuel = (kilometers * fuelConsumption) / 100;
        if (fuelLevel < requiredFuel) {
            std::cout << "Недостаточно топлива для прохождения дистанции." << std::endl;
        }
        else {
            totalDistance += kilometers;
            fuelLevel -= requiredFuel;
        }
    }

    void refuel() {
        fuelLevel = maxFuel;
        std::cout << "Бак заполнен" << std::endl;
    }

    void printStatus() {
        std::cout << "Общий пробег: " << totalDistance << " км" << std::endl;
        std::cout << "Остаток топлива в баке: " << fuelLevel << " литров" << std::endl;
    }
};

class Sedan : public Vehicle {
public:
    Sedan()
        : Vehicle(8.0, 60.0)
    {}
};

class SUV : public Vehicle {
public:
    SUV()
        : Vehicle(10.0, 70.0)
    {}
};

class Bus : public Vehicle {
public:
    Bus()
        : Vehicle(15.0, 150.0)
    {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    Vehicle* vehicles[3] = { new Sedan, new SUV, new Bus };
    for (int i = 0; i < 3; i++)
    {
        Vehicle* vehicle = vehicles[i];
        vehicle->refuel();
        vehicle->printStatus();
        vehicle->drive(120);
        vehicle->printStatus();
        vehicle->drive(420);
        vehicle->printStatus();
        vehicle->drive(300);
        vehicle->printStatus();
        vehicle->refuel();
        vehicle->drive(300);
        vehicle->printStatus();
        delete vehicle;
        std::cout << std::endl;
    }

    return 0;
}