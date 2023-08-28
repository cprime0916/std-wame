#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#define KNIFE "$001"
#define SWORD "$002"
#define WBRANCH "$003"
#define AX "$004"
#define RIFLE "$005"
#define TRIDENT "$006"
#define WAND "$007"
#define EGG "$008"
#define COMMON_EGG "$009"
#define UNCOMMON_EGG "$010"
#define RARE_EGG "$011"
#define EPIC_EGG "$012"
#define LEGENDARY_EGG "$013"
#define MYTHIC_EGG "$014"
#define BIRD_EGG "$015"
#define FROG_EGG "$016"
#define RAVEN_EGG "$017"
#define EAGLE_EGG "$018"
#define PHOENIX_EGG "$019"
#define XPCANDY "$020"
#define HYDRUS "$021"
#define ALLSLAYER "$022"
#define LORDBLADE "$023"
#define BLOODAXE "$024"
#define XPPOTION "$025"
#define WAVEBOW "$026"
#define LEGENDARY_RELIC1 "$027"
#define LEGENDARY_RELIC2 "$028"
#define LEGENDARY_RELIC3 "$029"
#define LEGENDARY_RELIC4 "$030"
#define LEGENDARY_RELIC5 "$031"
#define HEAL "$032"
#define MAGIC_HEAL "$033"
#define MAGIC_MUSH "$034"
#define BOMB "$035"
#define HARM "$036"
#define MAGIC_HARM "$037"
#define SWIFT "$038"
#define MAGIC_SWIFT "$039"
#define BLOOD_DAGGER "$040"
#define HAMBURGER "$041"
#define COD "$042"

class dict{
    public:
        std::string dictionary[42] = {KNIFE, SWORD, WBRANCH, AX, RIFLE, TRIDENT, WAND, EGG, COMMON_EGG, UNCOMMON_EGG, RARE_EGG, EPIC_EGG,
        LEGENDARY_EGG, MYTHIC_EGG, BIRD_EGG, FROG_EGG, RAVEN_EGG, EAGLE_EGG, PHOENIX_EGG, XPCANDY, HYDRUS, ALLSLAYER, LORDBLADE, BLOODAXE,
        XPPOTION, WAVEBOW, LEGENDARY_RELIC1, LEGENDARY_RELIC2, LEGENDARY_RELIC3, LEGENDARY_RELIC4, LEGENDARY_RELIC5, HEAL, MAGIC_HEAL,
        MAGIC_MUSH, BOMB, HARM, MAGIC_HARM, SWIFT, MAGIC_SWIFT, BLOOD_DAGGER, HAMBURGER, COD};
};

#endif
