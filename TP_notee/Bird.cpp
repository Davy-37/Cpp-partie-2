#include "Bird.h"
#include <iostream>

Bird::Bird()
    : Animal(), wingspan(0.0) {
}

Bird::Bird(const std::string& name,
    const std::string& color,
    const std::string& diet,
    const std::string& habitat,
    const std::string& sounds,
    bool isPet,
    int age,
    double weight,
    double height,
    double wingspan)
    : Animal(name, color, diet, habitat, sounds,
        isPet, age, weight, height),
    wingspan(wingspan) {
}

Bird::Bird(const Bird& other)
    : Animal(other), wingspan(other.wingspan) {
}

void Bird::setWingspan(double w) { wingspan = w; }
double Bird::getWingspan() const { return wingspan; }

void Bird::printInfo() const {
    std::cout << "Animal of type Bird:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Wingspan: " << wingspan << "cm" << std::endl;
    std::cout << "Age: " << age << " y's old" << std::endl;
    if (isPet)
        std::cout << "This animal is a pet" << std::endl;
    else
        std::cout << "This animal is not a pet" << std::endl;
    std::cout << "Weight: " << weight << "kg" << std::endl;
    std::cout << "Height: " << height << "cm" << std::endl;
}

std::string Bird::getType() const {
    return "Bird";
}

Animal* Bird::clone() const {
    return new Bird(*this);
}
