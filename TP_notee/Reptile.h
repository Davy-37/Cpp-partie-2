#pragma once
#include "Animal.h"
#include <string>

class Reptile : public Animal {
private:
    std::string scalePattern;  

public:
    Reptile();
    Reptile(const std::string& name,
        const std::string& color,
        const std::string& diet,
        const std::string& habitat,
        const std::string& sounds,
        bool isPet,
        int age,
        double weight,
        double height,
        const std::string& scalePattern);
    Reptile(const Reptile& other);
    virtual ~Reptile() = default;

    void setScalePattern(const std::string& p);
    const std::string& getScalePattern() const;

    void printInfo() const override;
    std::string getType() const override;
    Animal* clone() const override;
};
