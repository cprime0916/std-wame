#include <item.h>
#include <iostream>
#include <algorithm>
#include <thread>
// few notes before reading the functions
// 1. for the item::list(), apart from starred, I am planning to add more,
// but currently I want a simple implementation, let me know if you want 
// option apart from starred, thanks.

// types include:
// 1. weapons (w)
// 2. heal (h)
// 3. potions (p)
// 4. magnets (m)
// 5. tools (t)

void item::activate(bool& item_mode, bool can_fight){
    if(can_fight == false){
        item_mode = true;
    } else{
        std::cout << "Item Mode: null" << std::endl;
    }
}

void item::list(std::string parameter, int way, char custom_key, std::vector<std::string> items, std::vector<bool> starred, bool item_mode){
    char c = '\n';
    if(way == 0 && item_mode == true){
        if(parameter == "" || parameter == "all"){
            for(std::string item : items){
                std::cout << item << std::endl;
            }
        } else if(parameter == "starred"){
            for(int i=0;i<items.size();i++){
                if(starred[i] == true){
                    std::cout << items[i] << c;
                } else{
                    continue;
                }
            }
        }
    }
    if(way == 1 && item_mode == true){
        c = ' ';
        if(parameter == "" || parameter == "all"){
            for(std::string item : items){
                std::cout << item << c;
            }
        } else if(parameter == "starred"){
                for(int i=0;i<items.size();i++){
                    if(starred[i] == true){
                        std::cout << items[i] << c;
                    } else{
                        continue;
                    }
                }
        }
    } 
    else if((way != 0 && way != 1) && item_mode == true){
        c = custom_key;
        if(parameter == "" || parameter == "all"){
            for(std::string item : items){
                std::cout << item << c;
            }
        } else if(parameter == "starred"){
                for(int i=0;i<items.size();i++){
                    if(starred[i] == true){
                        std::cout << items[i] << c;
                    } else{
                        continue;
                    }
                }
        }
    }
    else if(item_mode == false){
        std::cout << "Error 301: Unsuccessful Listing Operation" << std::endl;
    }
}

void item::sort(std::vector<std::string>& items, std::vector<int>& time, std::vector<int>& levels, char sorting_key, bool item_mode){
    if(item_mode == true){
        std::vector<std::pair<int, int>> vec;
        if(sorting_key == 'a'){
            std::sort(items.begin(), items.end());
        } else if(sorting_key == 't'){
            for(int i=0;i<time.size();++i){
                vec.push_back(std::make_pair(time[i], i));
            }
            std::sort(vec.begin(), vec.end());
            for(int i=0;i<items.size();++i){
                items[i] = items[vec[i].second];
            }
        } else if(sorting_key == 'l'){
            for(int i=0;i<levels.size();++i){
                vec.push_back(std::make_pair(levels[i], i));
            }
            std::sort(vec.begin(), vec.end());
            for(int i=0;i<items.size();++i){
                items[i] = items[vec[i].second];
            }
        }
    } else{
        std::cout << "Error 302: Unsuccessful Sorting Operation" << std::endl;
    }
}

void item::star(std::vector<std::string> items, std::vector<bool>& starred, std::string item, bool item_mode){
    int index = 0;
    if(std::count(items.begin(), items.end(), item) > 0){
        std::vector<std::string>::iterator it = std::find(items.begin(), items.end(), item);
        if(it != items.cend()){
            index = std::distance(items.begin(), it);
            starred[index] = true;
        } else{
            std::cout << "Error 305: Index Not Found Within Inventory" << std::endl;
        }
    } else{
        std::cout << "Error 304: Can't Find Item Within Inventory" << std::endl;
    }
}

void item::del(std::vector<std::string>& items, int index, std::string item, bool item_mode){
    if(item_mode == true){
        if(index == -1){
            if(std::count(items.begin(), items.end(), item) > 0){
                std::vector<std::string>::iterator it = std::find(items.begin(), items.end(), item);
                if(it != items.cend()){
                    items.erase(items.begin()+std::distance(items.begin(), it));
                }
            }   else{
                std::cout << "Error 304: Can't Find Item Within Inventory" << std::endl;
                }
        } else if(index > 0){
            items.erase(items.begin()+index);
        }
    } else if(item_mode == false){
        std::cout << "Error 303: Unsuccessful Deleting Operation" << std::endl;
    }
}

void item::use(std::vector<std::string> items, std::vector<bool>& use, std::string item, int index, bool item_mode){
    if(index == -1){
        if(std::count(items.begin(), items.end(), item) > 0){
            std::vector<std::string>::iterator it = std::find(items.begin(), items.end(), item);
            if(it != items.cend()){
                index = std::distance(items.begin(), it);
                use[index] = true;
            } else{
                std::cout << "Error 304: Can't Find Item Within Inventory" << std::endl;
            }
        }
    }
}

void item::empty(std::vector<std::string>& items, bool item_mode, bool& game_loop){
    if(item_mode == true){
        std::cout << "Are you sure you want to empty all items? (Y/n)" << std::endl;
        std::string ans;
        if(ans == "Y"){
            items.clear();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "I am sorry for your loss..." << std::endl;
        } else if(ans == "n"){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Smart choice..." << std::endl;
        } else{
            game_loop = false;
        }
    } else{
        std::cout << "Error 303: Unsuccessful Deleting Operation" << std::endl;
    }
}
