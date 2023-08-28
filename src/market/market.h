#ifndef MARKT_H
#define MARKT_H

#include <string>
#include <vector>
#include <map>

namespace markt{
    void shop(bool& entered_shop);
    void instruct(bool entered_shop, std::vector<std::string>& items, std::vector<int>& price, bool& can_purchase, bool& can_trade, bool& can_sell);
    void purchase(int index, int wallet, std::vector<int>& price, std::vector<std::string>& items, bool can_purchase, std::vector<bool>& want_to);
    void trade(std::vector<std::string>& items, std::string item1, std::string item2, int index1, int index2, std::map<std::string, int> worth_value, bool can_trade, std::vector<bool>& want_to);
    void sell(int index, int& wallet, std::vector<int>& price, std::vector<std::string>& items, bool can_purchase, bool can_sell, std::vector<bool>& want_to);
}

#endif
