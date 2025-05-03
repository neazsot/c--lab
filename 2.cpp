#include <iostream>
#include <string>
#include <vector>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Character " << name << " created!" << std::endl;
    }

    ~Character() {
        std::cout << "Character " << name << " destroyed!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

class Monster {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Monster(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Monster " << name << " created!" << std::endl;
    }

    ~Monster() {
        std::cout << "Monster " << name << " destroyed!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

class Weapon {
private:
    std::string name;
    int damage;
    double weight;

public:
    Weapon(const std::string& n, int d, double w)
        : name(n), damage(d), weight(w) {
        std::cout << "Weapon " << name << " created!" << std::endl;
    }

    ~Weapon() {
        std::cout << "Weapon " << name << " destroyed!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Weapon: " << name << ", Damage: " << damage
            << ", Weight: " << weight << " kg" << std::endl;
    }

    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    double getWeight() const { return weight; }
};

int main() {
    std::cout << "Creating characters and monsters:" << std::endl;
    {
        Character hero("Hero", 100, 20, 10);
        Monster goblin("Goblin", 50, 15, 5);


        std::cout << "\nCharacter info:" << std::endl;
        hero.displayInfo();

        std::cout << "\nMonster info:" << std::endl;
        goblin.displayInfo();

        std::cout << "\nExiting inner scope..." << std::endl;
    } 

    std::cout << "\nCreating weapons:" << std::endl;

    std::vector<Weapon> weapons;
    weapons.emplace_back("Sword", 15, 2.5);
    weapons.emplace_back("Bow", 12, 1.0);
    weapons.emplace_back("Axe", 20, 4.0);
    weapons.emplace_back("Staff", 8, 1.5);

    std::cout << "\nWeapons info:" << std::endl;
    for (const auto& weapon : weapons) {
        weapon.displayInfo();
    }

    int maxDamageIndex = 0;
    for (size_t i = 1; i < weapons.size(); ++i) {
        if (weapons[i].getDamage() > weapons[maxDamageIndex].getDamage()) {
            maxDamageIndex = i;
        }
    }

    std::cout << "\nWeapon with highest damage:" << std::endl;
    weapons[maxDamageIndex].displayInfo();

    int lightestWeaponIndex = 0;
    for (size_t i = 1; i < weapons.size(); ++i) {
        if (weapons[i].getWeight() < weapons[lightestWeaponIndex].getWeight()) {
            lightestWeaponIndex = i;
        }
    }

    std::cout << "\nLightest weapon:" << std::endl;
    weapons[lightestWeaponIndex].displayInfo();

    std::cout << "\nExiting main function..." << std::endl;
    return 0;
}
