#include "Card.h"

Card::Card(const std::string& name) : cardName(name) {}
Card::~Card() = default;
std::string Card::getName() const { 
	return cardName; 
}
void Card::setName(const std::string& name) { 
	cardName = name; 
}
