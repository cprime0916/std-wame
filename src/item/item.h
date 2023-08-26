#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
class item{
    public:
        void activate(bool& item_mode, bool can_fight);
        void list(std::string parameter, int way, char custom_key, std::vector<std::string> items, std::vector<bool> starred, bool item_mode);
        void sort(std::vector<std::string>& items, std::vector<int>& time, std::vector<int>& levels, char sorting_key, bool item_mode);
        void star(std::vector<std::string> items, std::vector<bool>& starred, std::string item, bool item_mode);
        void del(std::vector<std::string>& items, int index, std::string item, bool item_mode);
        void use(std::vector<std::string> items, std::vector<bool>& use, std::string item, int index, bool item_mode);
        void empty(std::vector<std::string>& items, bool item_mode, bool& game_loop);
        void end(bool& item_mode);
};  

#endif
