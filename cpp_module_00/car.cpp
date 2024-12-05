#include <iostream>

class Car
{
    public:
        Car(); // Constructor declaration
        Car(std::string pbrand, std::string pmodel, int pyear); // second constructor
        std::string brand;
        std::string model;
        int year;
};

Car::Car(void)
{
    std::cout << "Hello world !" << std::endl;
    brand = "";
    model = "";
    year = 0;
}

Car::Car(std::string pbrand, std::string pmodel, int pyear)
{
    brand = pbrand;
    model = pmodel;
    year = pyear;
}

int main() {
  // Create Car objects and call the constructor with different values
  Car car1; // Corrected instantiation of car1
  Car car2("Ford", "Mustang", 1969);

  car1.brand = "BMW";
  car1.model = "X5";
  car1.year = 1999;

  // Print values
  std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
  std::cout << car2.brand << " " << car2.model << " " << car2.year << std::endl;
  return 0;
}