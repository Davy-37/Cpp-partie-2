#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
private:
    std::string energyType;

public:
    EnergyCard(const std::string& type);

    const std::string& getEnergyType() const;

    void displayInfo() const override;
};

#endif
