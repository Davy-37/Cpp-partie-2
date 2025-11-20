#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Card.h"
#include "PokemonCard.h"

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;          
    std::vector<PokemonCard*> actionCards;  

public:
    Player(const std::string& name);
    ~Player();

    const std::string& getName() const;

    void addCardToBench(Card* card);

    void activatePokemonCard(int benchIndex);
    void attachEnergyCard(int benchIndex, int actionIndex);

    void displayBench() const;
    void displayAction() const;

    void attack(int attackerIndex, int attackId,
        Player& opponent, int opponentIndex);

    void useTrainer(int benchIndex);
};

#endif
