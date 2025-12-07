#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string& name,
    const std::string& effect)
    : Card(name), trainerEffect(effect) {
}

const std::string& TrainerCard::getEffect() const {
    return trainerEffect;
}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName
        << ", Effect: " << trainerEffect << std::endl;
}
