#include "Zoo.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "KNNDouble.h"
#include "KNNString.h"

#include <algorithm>
#include <iostream>
#include <map>

int Zoo::MAX_CAPACITY = 100; 

Zoo::Zoo() : name("Unnamed Zoo") {}

Zoo::Zoo(const std::string& name) : name(name) {}

Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (auto a : other.animals) {
        animals.push_back(a->clone());
    }
}

Zoo::~Zoo() {
    for (auto a : animals) {
        delete a;
    }
    animals.clear();
}

void Zoo::setName(const std::string& n) { name = n; }
const std::string& Zoo::getName() const { return name; }


void Zoo::listAnimals() const {
    std::cout << "Zoo: " << name << std::endl;
    for (auto a : animals) {
        a->printInfo();
        std::cout << "------------------------" << std::endl;
    }
}


bool Zoo::addAnimal(Animal* animal) {
    if (static_cast<int>(animals.size()) >= MAX_CAPACITY) {
        std::cout << "Zoo is full, cannot add " << animal->getName() << std::endl;
        return false;
    }

  
    if (searchAnimalByName(animal->getName()) != -1) {
        std::cout << "Animal with name '" << animal->getName()
            << "' already exists in the zoo." << std::endl;
        return false;
    }

    auto it = std::lower_bound(
        animals.begin(), animals.end(), animal,
        [](Animal* a, Animal* b) {
            return a->getName() < b->getName();
        }
    );
    animals.insert(it, animal);
    return true;
}

int Zoo::searchAnimalByName(const std::string& nom) const {
    auto it = std::lower_bound(
        animals.begin(), animals.end(), nom,
        [](Animal* a, const std::string& value) {
            return a->getName() < value;
        }
    );

    if (it != animals.end() && (*it)->getName() == nom) {
        return static_cast<int>(it - animals.begin());
    }
    return -1;
}


bool Zoo::removeAnimalByName(const std::string& nom) {
    int idx = searchAnimalByName(nom);
    if (idx == -1) {
        std::cout << "Animal '" << nom << "' does not exist in the zoo."
            << std::endl;
        return false;
    }
    delete animals[idx];
    animals.erase(animals.begin() + idx);
    return true;
}


double Zoo::averageAgeForType(const std::string& type) const {
    int totalAge = 0;
    int count = 0;

    for (auto a : animals) {
        if (a->getType() == type) {
            totalAge += a->getAge();
            ++count;
        }
    }
    if (count == 0) return 0.0;
    return static_cast<double>(totalAge) / count;
}


std::string Zoo::predictTypeWithKNN(const Animal& newAnimal,
    int k,
    const std::string& infoType) const {
    if (animals.empty()) {
        return "Unknown";
    }

    if (infoType == "numerical") {
       
        std::vector<std::pair<double, double>> trainData;
        std::vector<std::string> labels;

        for (auto a : animals) {
            trainData.emplace_back(a->getWeight(), a->getHeight());
            labels.push_back(a->getType());
        }

        std::pair<double, double> target(newAnimal.getWeight(),
            newAnimal.getHeight());

        KNNDouble knn(k);
        std::vector<int> neighbors = knn.findNearestNeighbours(trainData, target);

        
        std::map<std::string, int> votes;
        for (int idx : neighbors) {
            votes[labels[idx]]++;
        }

        std::string bestType = "Unknown";
        int bestCount = -1;
        for (const auto& p : votes) {
            if (p.second > bestCount) {
                bestCount = p.second;
                bestType = p.first;
            }
        }
        return bestType;
    }
    else if (infoType == "categorical") {
        // Préparation : [color, diet, habitat, sound]
        std::vector<std::vector<std::string>> trainData;
        std::vector<std::string> labels;

        for (auto a : animals) {
            trainData.push_back({
                a->getColor(),
                a->getDiet(),
                a->getHabitat(),
                a->getSounds()
                });
            labels.push_back(a->getType());
        }

        std::vector<std::string> target = {
            newAnimal.getColor(),
            newAnimal.getDiet(),
            newAnimal.getHabitat(),
            newAnimal.getSounds()
        };

        KNNString knn(k);
        std::vector<int> neighbors =
            knn.findNearestNeighbours(trainData, target);

        std::map<std::string, int> votes;
        for (int idx : neighbors) {
            votes[labels[idx]]++;
        }

        std::string bestType = "Unknown";
        int bestCount = -1;
        for (const auto& p : votes) {
            if (p.second > bestCount) {
                bestCount = p.second;
                bestType = p.first;
            }
        }
        return bestType;
    }

   
    return "Unknown";
}
