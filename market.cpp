#include "market.h"
#include <iostream>

// Note that index1 and index2 in markt::trade() are for the respective items' indices in the Dictionary (basically an official, in-game ID System)
// the want_to[] arrays must be seperated for each function (i.e. the want_to[] in purchase will be want_to_purchase[])

void markt::shop(bool entered_shop){
    std::cout << "You've entered the shop" << std::endl;
    entered_shop = true;
}

void instruct(bool entered_shop, std::vector<std::string> items, std::vector<int> price, bool can_purchase, bool can_trade, bool can_sell){
    if(entered_shop){
        can_purchase = true;
        can_trade = true;
        can_sell = true;
        std::cout << "Which item would you like to purchase?" << std::endl;
        for(int i=0;i<sizeof(items)/sizeof(items[0]);i++){
            std::cout << "(" << i+1 << ") " << items[i] << " ";
        }
    }
}

void purchase(int index, int wallet, std::vector<int> price, std::vector<std::string> items, bool can_purchase, std::vector<bool> want_to){
     if(can_purchase && want_to[index]==true && wallet >= price[index]){
        wallet-=price[index];
        std::cout << "You have successfully purchased " << items[index] << "!" << std::endl;
     } else if(wallet < price[index]){
        std::cout << "You don't have enough money for the item " << items[index] << std::endl;
     }
}

void trade(std::vector<std::string> items, std::string item1, std::string item2, int index1, int index2, std::vector<int> worth_value, bool can_trade, std::vector<bool> want_to){
    if(can_trade && want_to[index2]==true && worth_value[index1]==worth_value[index2]){
        std::cout << "You have successfully traded " << item1 << " for " << item2 << std::endl;
    }
}

void sell(int index, int wallet, std::vector<int> price, std::vector<std::string> items, bool can_purchase, bool can_sell, std::vector<bool> want_to){
    if(can_sell && want_to[index]==true){
        wallet+=price[index];
        items.erase(items.begin()+index);
    }
}