#include <iostream>
#include <string>

using namespace std;

// Define the Car class
class Car
{
private:
    // Private attributes
    string make;
    string model;
    int year;
    float fuelLevel;

public:
    // Constructor to initialize the car
    Car(string carMake, string carModel, int carYear)
    {
        make = carMake;
        model = carModel;
        year = carYear;
        fuelLevel = 100.0; // New cars have a full tank of fuel
    }

    // Method to display car details
    void displayCarInfo()
    {
        cout << "Car Details:" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel Level: " << fuelLevel << "%" << endl;
    }

    // Method to drive the car
    void drive(float distance)
    {
        float fuelConsumption = distance * 0.1; // Arbitrary fuel consumption rate
        if (fuelLevel >= fuelConsumption)
        {
            fuelLevel -= fuelConsumption;
            cout << "You drove " << distance << " miles." << endl;
        }
        else
        {
            cout << "Not enough fuel to drive that distance." << endl;
        }
    }

    // Method to refuel the car
    void refuel(float fuelAmount)
    {
        fuelLevel += fuelAmount;
        if (fuelLevel > 100.0)
        {
            fuelLevel = 100.0; // Maximum fuel level is 100%
        }
        cout << "Car refueled. Current fuel level: " << fuelLevel << "%" << endl;
    }
};

int main()
{
    // Create a Car object
    Car myCar("Toyota", "Corolla", 2020);

    // Display car information
    myCar.displayCarInfo();

    // Drive the car
    myCar.drive(50); // Drive 50 miles

    // Display car information after driving
    myCar.displayCarInfo();

    // Refuel the car
    myCar.refuel(20); // Add 20% fuel

    // Display car information after refueling
    myCar.displayCarInfo();

    return 0;
}
