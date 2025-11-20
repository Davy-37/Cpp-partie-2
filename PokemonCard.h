#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
public:
   
    using Attack = std::tuple<int, int, std::string, int>;

private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<Attack> attacks;

public:
    PokemonCard(const std::string& name,
        const std::string& pokemonType,
        const std::string& familyName,
        int evolutionLevel,
        int maxHP,
        int attack1_cost,
        const std::string& attack1_desc,
        int attack1_damage,
        int attack2_cost,
        const std::string& attack2_desc,
        int attack2_damage);

    
    void attachEnergy();        
    void takeDamage(int dmg);
    void heal();

    
    const std::string& getPokemonType() const;
    const std::string& getFamilyName() const;
    int getEvolutionLevel() const;
    int getHP() const;
    int getMaxHP() const;

    int getNumberOfAttacks() const;
    int getAttackCost(int index) const;
    int getAttackCurrentEnergy(int index) const;
    const std::string& getAttackDescription(int index) const;
    int getAttackDamage(int index) const;

    bool isAlive() const;

 
    void displayInfo() const override;
};

#endif
