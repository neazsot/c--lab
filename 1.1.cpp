#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int maxHealth;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d), maxHealth(h) {}

    int getHealth() const { return health; }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for "
                << damage << " damage!" << std::endl;
        } else {
            std::cout << name << " attacks " << enemy.name
                << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        if (amount <= 0) {
            std::cout << "Cannot heal by non-positive amount!" << std::endl;
            return;
        }

        int oldHealth = health;
        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }

        std::cout << name << " healed for " << (health - oldHealth)
            << " HP! Current health: " << health << std::endl;
    }

    void takeDamage(int amount) {
        if (amount <= 0) {
            std::cout << "Damage must be positive!" << std::endl;
            return;
        }

        health -= amount;
        if (health < 0) {
            health = 0;
        }

        std::cout << name << " took " << amount << " damage! "
            << "Remaining health: " << health << std::endl;
    }
};

int main() {
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    std::cout << "Initial stats:" << std::endl;
    hero.displayInfo();
    monster.displayInfo();
    std::cout << std::endl;

    hero.attackEnemy(monster);
    std::cout << "After hero's attack:" << std::endl;
    monster.displayInfo();
    std::cout << std::endl;

    monster.attackEnemy(hero);
    std::cout << "After monster's attack:" << std::endl;
    hero.displayInfo();
    std::cout << std::endl;

    hero.heal(30);
    hero.displayInfo();
    std::cout << std::endl;

    monster.takeDamage(25);
    monster.displayInfo();
    std::cout << std::endl;

    monster.heal(100);
    monster.displayInfo();

    monster.takeDamage(100);
    monster.displayInfo();

    return 0;
}
