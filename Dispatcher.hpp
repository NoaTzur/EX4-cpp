
#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Dispatcher: public Player
    {
    private:

    public:

        Player& fly_direct(const City &c) {//if he is in research station - dont throw card
            if(_board.cities_map[_city]._is_station){
 
                _city = c;
                _board.cities_map[_city]._players_on_square.insert(this); // adding the player to the new Square(new city)
            }
            else{
                Player::fly_direct(c);
            }
            return *this;
        } 
        std::string role(){
            return "Dispatcher";
        }

        Dispatcher(Board &board, City city):Player(board,city){}
        ~Dispatcher(){}
    };


};