#include "fight.h"
#include <iostream>
#include <thread>

// formula for damage caused to boss
// dmg = (damage[index] + o_level) / int(rarity)
// s = (sharpen_time + int(rarity) + play_level)
// 
void fight::attack(std::string opponent, int o_health, int index, int o_level, std::vector<int> damage, char rarity, std::vector<std::string> items, bool want_to[], bool can_fight, bool& can_sharpen, bool& can_eat, std::vector<bool>& choose_weapon){
    int dmg = 0;
    int r = 0;
    if(rarity == 'c') r = 20;
    else if(rarity == 'u') r = 15;
    else if(rarity == 'r') r = 10;
    else if(rarity == 'e') r = 8;
    else if(rarity == 'l') r = 5;
    else if(rarity == 'm') r = 2;

    if(want_to[index]==true && can_fight == true){
        choose_weapon[index] = true;
        can_sharpen = true;
        dmg = (damage[index] + o_level) / r;
        choose_weapon[index] = false;
    }
    o_health-=dmg;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "You successfully damaged " << opponent << " " << dmg << "HP!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Continue to fight..." << std::endl;
}

void fight::sharpen(int index, int player_level, std::vector<int>& damage, char rarity, bool can_fight, bool& can_sharpen){
    int sharpen_time = 0;
    if(can_fight && can_sharpen){
        int d = damage[index];
        int r = 0;
        int s = 0;
        if(rarity == 'c') r = 2;
        else if(rarity == 'u') r = 5;
        else if(rarity == 'r') r = 8;
        else if(rarity == 'e') r = 10;
        else if(rarity == 'l') r = 15;
        else if(rarity == 'm') r = 20;
        sharpen_time++;
        s = sharpen_time + r + player_level;
        if(sharpen_time > 2){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "sharpen.max() = 2" << std::endl;
            s = 0;
            can_sharpen = false;
        } else{
            std::this_thread::sleep_for(std::chrono::seconds(60));
            damage[index] += s;
            std::cout << "Sharpened to total damage " << d << " +" << s << "!" << std::endl;
        }
    }
}

void fight::heal(int& player_health, std::vector<int> hp, int index, bool want_to[], bool can_heal, bool can_fight, std::vector<std::string>& items){
    if(want_to[index] == true && can_fight == true && can_heal == true){
        player_health += hp[index];
        std::cout << "You have successfully healed yourself " << hp[index] << " HP." << std::endl;
        items.erase(items.begin()+index);
    }
}

void fight::eat(int index, int player_level, int& player_health, int& player_speed, int& player_salv, std::vector<int> add, char type, bool want_to[], bool can_fight, bool can_eat){
    if(want_to[index] == true && can_fight && can_eat){
        if(type == 'h'){
            player_health+=(player_level)%10+add[index];
        } else if(type == 's'){
            player_speed+=(player_level)%10+add[index];
        } else if(type == 'S'){
            player_salv+=(player_level)%10+add[index];
        }
    }
}
