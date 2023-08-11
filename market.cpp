#include "market.h"
#include <iostream>

// Note that index1 and index2 in markt::trade() are for the respective items' indices in the Dictionary (basically an official, in-game ID System)
// the want_to[] arrays must be seperated for each function (i.e. the want_to[] in purchase will be want_to_purchase[])
// considering to use C dynamic array...
void markt::shop(bool entered_shop){
    std::cout << "You've entered the shop" << std::endl;
    entered_shop = true;
}

void markt::instruct(bool entered_shop, char items[][1000], int price[], bool can_purchase, bool can_trade, bool can_sell){
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

void markt::purchase(int index, int wallet, int price[], char items[][1000], bool can_purchase, bool want_to[]){
     if(can_purchase && want_to[index]==true && wallet >= price[index]){
        wallet-=price[index];
        std::cout << "You have successfully purchased " << items[index] << "!" << std::endl;
     } else if(wallet < price[index]){
        std::cout << "You don't have enough money for the item " << items[index] << std::endl;
     }
}

void trade(char items[][1000], char item1[], char item2[], int index1, int index2, int worth_value[], bool can_trade, bool want_to[]){
    if(can_trade && want_to[index2]==true && worth_value[index1]==worth_value[index2]){
        for(int i=0;i<sizeof(item1)/sizeof(item1[0]);i++){
            std::cout << "You have successfully traded " << item1[i];
        }
        for(int j=0;j<sizeof(item2)/sizeof(item2[0]);j++){
            std::cout << " for " << item2[j];
        }
        std::cout << std::endl;
    }
}

void markt::sell(int index, int wallet, int price[], char items[][1000], bool can_sell, bool want_to[]){
    if(can_sell && want_to[index]==true){
        wallet+=price[index];
        for(int i=0;i<1000;i++){
            items[index][i]='\0';
        }
    }
}