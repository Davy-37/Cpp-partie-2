#include "pokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& name,
    const std::string& type,
    const std::string& family,
    int evolutionLevel,
    int maxHP,
    int attack1_cost,
    const std::string& attack1_desc,
    int attack1_damage,
    int attack2_cost,
    const std::string& attack2_desc,
    int attack2_damage)
    : Card(name),
    pokemonType(type),
    familyName(family),
    evolutionLevel(evolutionLevel),
    maxHP(maxHP),
    hp(maxHP)
{
    attacks.push_back(Attack{ attack1_cost, 0, attack1_desc, attack1_damage });
    attacks.push_back(Attack{ attack2_cost, 0, attack2_desc, attack2_damage });
}

void PokemonCard::attachEnergy() {
    for (auto& atk : attacks) {
        std::get<1>(atk) += 1;  
    }
}

void PokemonCard::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

void PokemonCard::heal() {
    hp = maxHP;
}

const std::string& PokemonCard::getPokemonType() const { return pokemonType; }
const std::string& PokemonCard::getFamilyName() const { return familyName; }
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }
int PokemonCard::getHP() const { return hp; }
int PokemonCard::getMaxHP() const { return maxHP; }

int PokemonCard::getNumberOfAttacks() const {
    return static_cast<int>(attacks.size());
}

int PokemonCard::getAttackCost(int index) const {
    return std::get<0>(attacks.at(index));
}

int PokemonCard::getAttackCurrentEnergy(int index) const {
    return std::get<1>(attacks.at(index));
}

const std::string& PokemonCard::getAttackDescription(int index) const {
    return std::get<2>(attacks.at(index));
}

int PokemonCard::getAttackDamage(int index) const {
    return std::get<3>(attacks.at(index));
}

bool PokemonCard::isAlive() const {
    return hp > 0;
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName
        << ", Type: " << pokemonType
        << ", Evolution Level: " << evolutionLevel
        << " of the family \"" << familyName
        << ", HP: " << hp << "\"" << std::endl;

    std::cout << "Attacks:" << std::endl;
    for (int i = 0; i < static_cast<int>(attacks.size()); ++i) {
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost: " << getAttackCost(i) << std::endl;
        std::cout << "Attack current energy storage: "
            << getAttackCurrentEnergy(i) << std::endl;
        std::cout << "Attack description: "
            << getAttackDescription(i) << std::endl;
        std::cout << "Attack damage: " << getAttackDamage(i) << std::endl;
    }
}
