#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class OperationsExpert: public Player
    {
    private:
        
    public:

        Player& build(){//dont throw card like the father func
            
            if (!(_board.cities_map[_city]._is_station))
            {
                
                _board.cities_map[_city]._is_station = true;

            }
            else{
                 throw std::invalid_argument("not in the player cards or already a research station");
            }
            
            return *this;

        } 

        std::string role(){
            return "OperationsExpert";
        }
        OperationsExpert(Board &board, City city):Player(board,city){}
        ~OperationsExpert(){}
    };


};