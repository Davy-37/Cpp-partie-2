#pragma once
#include "Animal.h"
#include <string>

class Mammal : public Animal {
private:
    std::string furColor;   

public:
    Mammal();
    Mammal(const std::string& name,
        const std::string& color,
        const std::string& diet,
        const std::string& habitat,
        const std::string& sounds,
        bool isPet,
        int age,
        double weight,
        double height,
        const std::string& furColor);
    Mammal(const Mammal& other);
    virtual ~Mammal() = default;

    void setFurColor(const std::string& c);
    const std::string& getFurColor() const;

    void printInfo() const override;
    std::string getType() const override;
    Animal* clone() const override;
};
