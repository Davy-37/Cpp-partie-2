#include "Mammal.h"
#include <iostream>

Mammal::Mammal()
    : Animal(), furColor("") {
}

Mammal::Mammal(const std::string& name,
    const std::string& color,
    const std::string& diet,
    const std::string& habitat,
    const std::string& sounds,
    bool isPet,
    int age,
    double weight,
    double height,
    const std::string& furColor)
    : Animal(name, color, diet, habitat, sounds,
        isPet, age, weight, height),
    furColor(furColor) {
}

Mammal::Mammal(const Mammal& other)
    : Animal(other), furColor(other.furColor) {
}

void Mammal::setFurColor(const std::string& c) { furColor = c; }
const std::string& Mammal::getFurColor() const { return furColor; }

void Mammal::printInfo() const {
    std::cout << "Animal of type Mammal:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Fur Color: " << furColor << std::endl;
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

std::string Mammal::getType() const {
    return "Mammal";
}

Animal* Mammal::clone() const {
    return new Mammal(*this);
}
