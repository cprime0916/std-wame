#include <bits/stdc++.h>
int main(){
    bool game_loop = true;
    while(game_loop){
        std::string command;
        getline(std::cin, command);
        // First Error Handling (Later will be in ErrorHandling() function)
        if(command[0] != '/') std::cout << "Error 101: Invalid Command" << std::endl;
        else{
            try{
                // game code
            } catch(const std::exception& e){
                std::cout << "Error 102: Unexecutable Console" << std::endl;
            }
        }
    }
}
