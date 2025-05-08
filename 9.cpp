
#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int level;
    int experience;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d), level(1), experience(0) {}

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        } else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        health += amount;
        if (health > 100) health = 100;
        std::cout << name << " heals for " << amount << " HP!" << std::endl;
    }

    void gainExperience(int exp) {
        experience += exp;
        if (experience >= 100) {
            level++;
            experience -= 100;
            std::cout << name << " leveled up to level " << level << "!" << std::endl;
        }
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health << ", Attack: " << attack
                  << ", Defense: " << defense << ", Level: " << level << ", Experience: " << experience << std::endl;
    }

    std::string getName() const { return name; }
    int getHealth() const { return health; }
};

int main() {
    Character hero("Hero", 100, 20, 5);
    Character enemy("Goblin", 50, 10, 2);
    hero.attackEnemy(enemy);
    hero.gainExperience(120);
    hero.heal(20);
    hero.displayInfo();
    enemy.displayInfo();
    return 0;
}
