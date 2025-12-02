#pragma once
#include <string>
#include <vector>
#include "Animal.h"

class Zoo {
private:
    std::string name;           
    static int MAX_CAPACITY;       
    std::vector<Animal*> animals;   

public:
    Zoo();
    explicit Zoo(const std::string& name);
    Zoo(const Zoo& other);
    ~Zoo();


    void setName(const std::string& n);
    const std::string& getName() const;

 
    void listAnimals() const;
    bool addAnimal(Animal* animal);            
    int  searchAnimalByName(const std::string& name) const; 
    bool removeAnimalByName(const std::string& name);
    double averageAgeForType(const std::string& type) const;

    
    std::string predictTypeWithKNN(const Animal& newAnimal,
        int k,
        const std::string& infoType) const;
};
