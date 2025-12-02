#include "Animal.h"


Animal::Animal()
    : name(""), color(""), diet(""), habitat(""),
    sounds(""), isPet(false), age(0), weight(0.0), height(0.0) {
}


Animal::Animal(const std::string& name,
    const std::string& color,
    const std::string& diet,
    const std::string& habitat,
    const std::string& sounds,
    bool isPet,
    int age,
    double weight,
    double height)
    : name(name), color(color), diet(diet), habitat(habitat),
    sounds(sounds), isPet(isPet), age(age),
    weight(weight), height(height) {
}


Animal::Animal(const Animal& other)
    : name(other.name), color(other.color), diet(other.diet),
    habitat(other.habitat), sounds(other.sounds),
    isPet(other.isPet), age(other.age),
    weight(other.weight), height(other.height) {
}


const std::string& Animal::getName() const { return name; }
const std::string& Animal::getColor() const { return color; }
const std::string& Animal::getDiet() const { return diet; }
const std::string& Animal::getHabitat() const { return habitat; }
const std::string& Animal::getSounds() const { return sounds; }
bool Animal::getIsPet() const { return isPet; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
double Animal::getHeight() const { return height; }


void Animal::setName(const std::string& n) { name = n; }
void Animal::setColor(const std::string& c) { color = c; }
void Animal::setDiet(const std::string& d) { diet = d; }
void Animal::setHabitat(const std::string& h) { habitat = h; }
void Animal::setSounds(const std::string& s) { sounds = s; }
void Animal::setIsPet(bool p) { isPet = p; }
void Animal::setAge(int a) { age = a; }
void Animal::setWeight(double w) { weight = w; }
void Animal::setHeight(double h) { height = h; }


void Animal::make_sound() const {
    std::cout << name << " makes sound: " << sounds << std::endl;
}

void Animal::printInfo() const {
    std::cout << "Animal of unknown type:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Color: " << color << std::endl;
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

std::string Animal::getType() const {
    return "Animal";
}

Animal* Animal::clone() const {
    return new Animal(*this);
}
