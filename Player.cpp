#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"

#include <iostream>

Player::Player(const std::string& name)
    : playerName(name) {
}

Player::~Player() {
    for (Card* c : benchCards) {
        delete c;
    }
    for (PokemonCard* p : actionCards) {
        delete p;
    }
}

const std::string& Player::getName() const {
    return playerName;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size()))
        return;

    PokemonCard* p = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
    if (!p) return;

    std::cout << playerName << " is activating a Pokemon Card: "
        << p->getName() << std::endl;

    actionCards.push_back(p);
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size()))
        return;
    if (actionIndex < 0 || actionIndex >= static_cast<int>(actionCards.size()))
        return;

    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    if (!energy) return;

    PokemonCard* target = actionCards[actionIndex];

    std::cout << playerName << " is attaching Energy Card of type "
        << energy->getEnergyType()
        << " to the Pokemon " << target->getName() << std::endl;

    target->attachEnergy();

    delete energy; 
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":" << std::endl;
    for (Card* c : benchCards) {
        c->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":" << std::endl;
    for (PokemonCard* p : actionCards) {
        p->displayInfo();
    }
}

void Player::attack(int attackerIndex, int attackId,
    Player& opponent, int opponentIndex) {
    if (attackerIndex < 0 || attackerIndex >= static_cast<int>(actionCards.size()))
        return;
    if (opponentIndex < 0 || opponentIndex >= static_cast<int>(opponent.actionCards.size()))
        return;

    PokemonCard* attacker = actionCards[attackerIndex];
    PokemonCard* defender = opponent.actionCards[opponentIndex];

    std::cout << "Only " << attacker->getNumberOfAttacks()
        << " attacks exist." << std::endl;

    if (attackId < 0 || attackId >= attacker->getNumberOfAttacks())
        return;

    int damage = attacker->getAttackDamage(attackId);

    std::cout << playerName << " attacking " << opponent.playerName
        << "'s Pokemon " << defender->getName()
        << " with the Pokemon " << attacker->getName()
        << " with its attack: "
        << attacker->getAttackDescription(attackId)
        << std::endl;

    std::cout << "Reducing " << damage
        << " from " << opponent.playerName
        << "'s Pokemon's HP" << std::endl;

    defender->takeDamage(damage);

    if (defender->isAlive()) {
        std::cout << "Pokemon " << defender->getName()
            << " is still alive" << std::endl;
    }
    else {
        std::cout << "Pokemon " << defender->getName()
            << " has fainted" << std::endl;
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= static_cast<int>(benchCards.size()))
        return;

    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
    if (!trainer) return;

    std::cout << playerName << " is using the Trainer Card to \""
        << trainer->getEffect() << "\"" << std::endl;

 
    if (trainer->getEffect() == "heal all your action pokemon") {
        for (PokemonCard* p : actionCards) {
            p->heal();
        }
    }

    delete trainer; 
    benchCards.erase(benchCards.begin() + benchIndex);
}
