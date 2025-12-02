#pragma once
#include <string>
#include <iostream>

class Animal {
protected:
    std::string name;    
    std::string color;  
    std::string diet;   
    std::string habitat;  
    std::string sounds;   
    bool isPet;          
    int age;              
    double weight;        
    double height;        

public:
  
    Animal();
    Animal(const std::string& name,
        const std::string& color,
        const std::string& diet,
        const std::string& habitat,
        const std::string& sounds,
        bool isPet,
        int age,
        double weight,
        double height);
    Animal(const Animal& other);
    virtual ~Animal() = default;

   
    const std::string& getName() const;
    const std::string& getColor() const;
    const std::string& getDiet() const;
    const std::string& getHabitat() const;
    const std::string& getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

   
    void setName(const std::string& n);
    void setColor(const std::string& c);
    void setDiet(const std::string& d);
    void setHabitat(const std::string& h);
    void setSounds(const std::string& s);
    void setIsPet(bool p);
    void setAge(int a);
    void setWeight(double w);
    void setHeight(double h);

    
    virtual void make_sound() const;
    virtual void printInfo() const;
    virtual std::string getType() const;      
    virtual Animal* clone() const;          
};
