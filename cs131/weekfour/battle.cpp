#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Pokemon {
public:
	string name;
	int hp;
    int attack;
    int defense;
    int speed;

    Pokemon(const string& name, int hp, int attack, int defense, int speed)
        : name(name), hp(hp), attack(attack), defense(defense), speed(speed) {}

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }
    
	int calcDamage(int att_attack, int def_defense) const {
        int damage = att_attack - def_defense;
        if (damage < 0) {
            damage = 0;
        }
        return damage;
    }

    bool isAlive() const {
        return hp > 0;
    }

    virtual void performMove(Pokemon& opponent) {
        cout << name << " used basic move" << endl;
        int damage = calcDamage(attack, opponent.defense);
        opponent.takeDamage(damage);
        cout << opponent.name << " took " << damage << " damage." << endl;
    }
};

class PlayerPokemon : public Pokemon {
public:
    struct Move {
        string name;
        int damage;
    };

    vector<Move> moves;

    PlayerPokemon(const string& name, int hp, int attack, int defense, int speed,
                   const vector<Move>& moves)
        : Pokemon(name, hp, attack, defense, speed), moves(moves) {}

    void performMove(Pokemon& opponent) override {
        cout << "Choose a move " <<endl;
        for (size_t i = 0; i < moves.size(); ++i) {
            cout << i + 1 << ". " << moves[i].name  << moves[i].damage << endl;
        }

        int move_choice;
        cin >> move_choice;

        if (move_choice >= 1 && move_choice <= static_cast<int>(moves.size())) {
            Move sel_move = moves[move_choice - 1];
            cout << name << " used " << sel_move.name << endl;
            int damage = calcDamage(sel_move.damage, opponent.defense);
            opponent.takeDamage(damage);
            cout << opponent.name << " took " << damage << endl;
        } else {
            cout << "invalid choice. using base move" << endl;
            Pokemon::performMove(opponent);
        }
    }
};

class EnemyPokemon : public Pokemon {
public:
    struct Move {
        string name;
        int damage;
    };

    vector<Move> moves;

    EnemyPokemon(const string& name, int hp, int attack, int defense, int speed,
                 const vector<Move>& moves)
        : Pokemon(name, hp, attack, defense, speed), moves(moves) {}

    void performMove(Pokemon& opponent) override {
        int randomMoveIndex = rand() % moves.size();
        Move selectedMove = moves[randomMoveIndex];

        cout << name << " used " << selectedMove.name << "!" << endl;
        int damage = calcDamage(selectedMove.damage, opponent.defense);
        opponent.takeDamage(damage);
        cout << opponent.name << " took " << damage << " damage." << endl;
    }
};

bool isPokemonFaster(const Pokemon& p1, const Pokemon& p2) {
    return p1.speed > p2.speed;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<PlayerPokemon::Move> charmander_moves = {
        {"Ember", 70},
        {"Scratch", 40},
        {"Growl", 0},
        {"Flamethrower", 80}
    };

    PlayerPokemon charmander("Charmander", 42, 52, 44, 67, charmander_moves);

    vector<EnemyPokemon::Move> enemy_moves_pikachu = {
        {"Thunder Shock", 60},
        {"Quick Attack", 40},
        {"Tail Whip", 0}
    };

    EnemyPokemon enemy("Pikachu", 38, 31, 48, 40, enemy_moves_pikachu);

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
        cout << "you win" << endl;
    } else {
        cout << "you lose" << endl;
    }

    return 0;
}

