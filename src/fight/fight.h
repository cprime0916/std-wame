#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include <vector>

class fight {
public:
    void attack(std::string opponent, int o_health, int index, int o_level, std::vector<int> damage, char rarity, std::vector<std::string> items, bool want_to[], bool can_fight, bool& can_sharpen, bool& can_eat, std::vector<bool>& choose_weapon);
    void sharpen(int index, int player_level, std::vector<int>& damage, char rarity, bool can_fight, bool& can_sharpen);
    void heal(int& player_health, std::vector<int> hp, int index, bool want_to[], bool can_heal, bool can_fight, std::vector<std::string>& items);
    void eat(int index, int player_level, int& player_health, int& player_speed, int& player_salv, std::vector<int> add, char type, bool want_to[], bool can_fight, bool can_eat);
};

#endif
