#pragma once
#include "Animal.h"

class Bird : public Animal {
private:
    double wingspan;   

public:
    Bird();
    Bird(const std::string& name,
        const std::string& color,
        const std::string& diet,
        const std::string& habitat,
        const std::string& sounds,
        bool isPet,
        int age,
        double weight,
        double height,
        double wingspan);
    Bird(const Bird& other);
    virtual ~Bird() = default;

    void setWingspan(double w);
    double getWingspan() const;

    void printInfo() const override;
    std::string getType() const override;
    Animal* clone() const override;
};
