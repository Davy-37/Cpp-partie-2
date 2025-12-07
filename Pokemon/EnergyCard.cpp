#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& type)
    : Card("Energy"), energyType(type) {
}

const std::string& EnergyCard::getEnergyType() const {
    return energyType;
}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card of type " << energyType << std::endl;
}