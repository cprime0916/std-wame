#include "pet.h"
#include <iostream>
#include <random>
#include <thread>

// helper function
bool generate(double lowerBound, double upperBound, double probability) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double randomNum = dis(gen);

    if (randomNum >= lowerBound && randomNum <= upperBound) {
        return true;
    } else {
        return false;
    }
}

void pet::tame(const std::string& pet, char rarity, std::map<std::string, bool>& taming_list) {
    bool generation = true;
    if (rarity == 'c') {
        generation = generate(0.6, 0.8, 0.6);
    } else if (rarity == 'u') {
        generation = generate(0.5, 0.7, 0.3);
    } else if (rarity == 'r') {
        generation = generate(0.4, 0.7, 0.2);
    } else if (rarity == 'e') {
        generation = generate(0.3, 0.6, 0.1);
    } else if (rarity == 'l') {
        generation = generate(0.15, 0.2, 0.1);
    } else if (rarity == 'm') {
        generation = generate(0, 0.05, 0.005);
    }

    if (generation) {
        taming_list[pet] = true;
        std::cout << "Congrats! You have successfully obtained pet " << pet << std::endl;
    } else {
        std::cout << "Better luck next time" << std::endl;
    }
}

void pet::command_pet(const std::string& pet, int mode, int xp, bool& stay, bool& follow, bool& hunt, bool& add_mode) {
    if (mode == 1) {
        stay = true;
        std::cout << "Pet " << pet << " is staying beside you." << std::endl;
    } else if (mode == 2) {
        follow = true;
        std::cout << "Pet " << pet << " is following you." << std::endl;
    } else if (mode == 3) {
        hunt = true;
        std::cout << "Pet " << pet << " is hunting for food." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 10);
        int rand = dis(gen);
        std::cout << "Pet " << pet << " hunted " << rand << " for you!" << std::endl;
    } else {
        std::cout << "Add mode..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Type 0 to quit..." << std::endl;
        add_mode = true;
        std::string custom_mode;
        std::cin >> custom_mode;
        if (custom_mode == "0") {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "." << std::endl;
            add_mode = false;
        } else {
            std::cout << "Maybe you can suggest it in the next update..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "The developer is trash, he is not able to fulfill your suggestion anyway" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "So why bother?" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "." << std::endl;
            add_mode = false;
        }
    }
}

void pet::utk(const std::string& pet, int pet_level, char rarity, int& o_health) {
    int r = 0, dmg = 0;
    if (rarity == 'c') r = 20;
    else if (rarity == 'u') r = 15;
    else if (rarity == 'r') r = 10;
    else if (rarity == 'e') r = 8;
    else if (rarity == 'l') r = 5;
    else if (rarity == 'm') r = 2;

    dmg = (100 * pet_level) / r;
    std::cout << "Your pet " << pet << " is dealing " << dmg << " in its UTK!" << std::endl;
    o_health -= dmg;
}

void pet::feed(const std::string& pet, const std::string& food, bool want_to[], bool have_in_invn[], int index, int& salv) {
    int f = food[0] - '0';
    if (want_to[index] && have_in_invn[index]) {
        salv += f;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "You have fed your pet " << pet << " " << food << "." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Salvation +" << f << std::endl;
    }
}

void pet::free_pet(const std::string& pet, std::map<std::string, bool>& taming_list, bool& game_loop) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Are you sure you want to free " << pet << "?" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(y / n)" << std::endl;
    std::string ans;
    std::cin >> ans;
    if (ans == "y") {
        taming_list[pet] = false;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "... At least you liberated the pet from your desires" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "." << std::endl;
    } else if (ans == "n") {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "." << std::endl;
    } else {
        std::cout << "Don't ever play this game again." << std::endl;
        game_loop = false;
    }
}
