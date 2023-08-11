#ifndef MARKT_H
#define MARKT_H

#include <string>
#include <vector>
class markt{
    public:
        void shop(bool entered_shop);
        void instruct(bool entered_shop, std::string items[], int price[], bool can_purchase, bool can_trade, bool can_sell);
        void purchase(int index, int wallet, int price[], std::string items[], bool can_purchase, bool want_to[]);
        void trade(std::string items[], std::string item1, std::string item2, int index1, int index2, int worth_value[], bool can_trade, bool want_to[]);
        void sell(int index, int wallet, int price[], std::string items[], bool can_purchase, bool want_to[]);
};

#endif