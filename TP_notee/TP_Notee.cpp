#include <iostream>

#include "Zoo.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"

int main() {
    Zoo zoo("ENSISA Zoo");

    
    Animal* leo = new Mammal("Leo", "Golden", "Carnivore",
        "Grassland", "Roar",
        false, 5, 180.5, 350.0, "Tawny");

    Animal* flash = new Bird("Flash", "Black", "Carnivore",
        "Mountains", "Screech",
        false, 9, 9.9, 18.0, 120.0);

    Animal* sly = new Reptile("Sly", "Green", "Carnivore",
        "Desert", "Hiss",
        false, 4, 12.0, 40.0, "Striped");

    zoo.addAnimal(leo);
    zoo.addAnimal(flash);
    zoo.addAnimal(sly);

    zoo.listAnimals();

  
    std::cout << "Average age of Reptiles: "
        << zoo.averageAgeForType("Reptile") << std::endl;

    
    Mammal unknown("Unknown", "Golden", "Carnivore",
        "Grassland", "Roar",
        false, 3, 150.0, 340.0, "Golden");

    std::string typeNum =
        zoo.predictTypeWithKNN(unknown, 3, "numerical");
    std::cout << "Predicted type (numerical KNN): "
        << typeNum << std::endl;

    std::string typeCat =
        zoo.predictTypeWithKNN(unknown, 3, "categorical");
    std::cout << "Predicted type (categorical KNN): "
        << typeCat << std::endl;

    return 0;
}
