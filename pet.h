#ifndef PET_H
#define PET_H

#include <string>
#include <map>
#include <vector>

class pet {
    bool generate(double lowerBound, double upperBound, double probability);
    void tame(const std::string& pet, char rarity, std::map<std::string, bool>& taming_list);
    void command_pet(const std::string& pet, int mode, int xp, bool& stay, bool& follow, bool& hunt, bool& add_mode);
    void utk(const std::string& pet, int pet_level, char rarity, int& o_health);
    void feed(const std::string& pet, const std::string& food, bool want_to[], bool have_in_invn[], int index, int& salv);
    void free_pet(const std::string& pet, std::map<std::string, bool>& taming_list, bool& game_loop);
};

#endif
