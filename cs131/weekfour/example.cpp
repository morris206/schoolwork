#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Pokemon {
public:
    std::string name;
    int hp;
    int attack;
    int defense;
    int speed;

    Pokemon(const std::string& name, int hp, int attack, int defense, int speed)
        : name(name), hp(hp), attack(attack), defense(defense), speed(speed) {}

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) {
            hp = 0;
        }
    }

    bool isAlive() const {
        return hp > 0;
    }

    virtual void performMove(Pokemon& opponent) {
        std::cout << name << " used a basic move!" << std::endl;
        int damage = attack - opponent.defense;
        if (damage < 0) {
            damage = 0;
        }
        opponent.takeDamage(damage);
        std::cout << opponent.name << " took " << damage << " damage." << std::endl;
    }
};

class StarterPokemon : public Pokemon {
public:
    std::vector<std::string> moves;

    StarterPokemon(const std::string& name, int hp, int attack, int defense, int speed,
                   const std::vector<std::string>& moves)
        : Pokemon(name, hp, attack, defense, speed), moves(moves) {}

    void performMove(Pokemon& opponent) override {
        std::cout << "Choose a move for " << name << ":" << std::endl;
        for (size_t i = 0; i < moves.size(); ++i) {
            std::cout << i + 1 << ". " << moves[i] << std::endl;
        }

        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(moves.size())) {
            std::cout << name << " used " << moves[choice - 1] << "!" << std::endl;
            int damage = attack - opponent.defense;
            if (damage < 0) {
                damage = 0;
            }
            opponent.takeDamage(damage);
            std::cout << opponent.name << " took " << damage << " damage." << std::endl;
        } else {
            std::cout << "Invalid choice. Using a basic move." << std::endl;
            Pokemon::performMove(opponent);
        }
    }
};

class EnemyPokemon : public Pokemon {
public:
    EnemyPokemon(const std::string& name, int hp, int attack, int defense, int speed)
        : Pokemon(name, hp, attack, defense, speed) {}

    void performMove(Pokemon& opponent) override {
        std::cout << name << " used a basic move!" << std::endl;
        int damage = attack - opponent.defense;
        if (damage < 0) {
            damage = 0;
        }
        opponent.takeDamage(damage);
        std::cout << opponent.name << " took " << damage << " damage." << std::endl;
    }
};

bool isPokemonFaster(const Pokemon& p1, const Pokemon& p2) {
    return p1.speed > p2.speed;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Create an array of starter Pokemon
    std::vector<std::string> charmanderMoves = {"Ember", "Scratch", "Growl"};
    StarterPokemon charmander("Charmander", 39, 52, 43, 65, charmanderMoves);

    // Create an array of enemy Pokemon
    EnemyPokemon enemy("Pikachu", 35, 55, 40, 90);

    std::cout << "You chose " << charmander.name << std::endl;
    std::cout << "You're up against " << enemy.name << std::endl;

    while (charmander.isAlive() && enemy.isAlive()) {
        if (isPokemonFaster(charmander, enemy)) {
            charmander.performMove(enemy);
            if (enemy.isAlive()) {
                enemy.performMove(charmander);
            }
        } else {
            enemy.performMove(charmander);
            if (charmander.isAlive()) {
                charmander.performMove(enemy);
            }
        }
    }

    if (charmander.isAlive()) {
        std::cout << "Congratulations! " << charmander.name << " wins!" << std::endl;
    } else {
        std::cout << "Oh no! " << enemy.name << " wins!" << std::endl;
    }

    return 0;
}

