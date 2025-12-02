#include "Reptile.h"
#include <iostream>

Reptile::Reptile()
    : Animal(), scalePattern("") {
}

Reptile::Reptile(const std::string& name,
    const std::string& color,
    const std::string& diet,
    const std::string& habitat,
    const std::string& sounds,
    bool isPet,
    int age,
    double weight,
    double height,
    const std::string& scalePattern)
    : Animal(name, color, diet, habitat, sounds,
        isPet, age, weight, height),
    scalePattern(scalePattern) {
}

Reptile::Reptile(const Reptile& other)
    : Animal(other), scalePattern(other.scalePattern) {
}

void Reptile::setScalePattern(const std::string& p) { scalePattern = p; }
const std::string& Reptile::getScalePattern() const { return scalePattern; }

void Reptile::printInfo() const {
    std::cout << "Animal of type Reptile:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Scale Pattern: " << scalePattern << std::endl;
    std::cout << "Diet: " << diet << std::endl;
    std::cout << "Habitat: " << habitat << std::endl;
    std::cout << "Age: " << age << " y's old" << std::endl;
    if (isPet)
        std::cout << "This animal is a pet" << std::endl;
    else
        std::cout << "This animal is not a pet" << std::endl;
    std::cout << "Weight: " << weight << "kg" << std::endl;
    std::cout << "Height: " << height << "cm" << std::endl;
}

std::string Reptile::getType() const {
    return "Reptile";
}

Animal* Reptile::clone() const {
    return new Reptile(*this);
}
