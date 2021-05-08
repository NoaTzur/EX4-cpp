#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class OperationsExpert: public Player
    {
    private:
        
    public:

        Player& build(){//dont throw card like the father func
            
            
                
            _board.cities_map[_city]._is_station = true;

            
         
            return *this;

        } 

        std::string role(){
            return "OperationsExpert";
        }
        OperationsExpert(Board &board, City city):Player(board,city){}
        ~OperationsExpert(){}
    };


};
