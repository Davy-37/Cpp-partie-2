#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
protected:
    std::string cardName;

public:
    Card(const std::string& name);
    virtual ~Card();

    std::string getName() const;
    void setName(const std::string& name);

    virtual void displayInfo() const = 0;
};

#endif
