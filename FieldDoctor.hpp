#pragma once

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

class FieldDoctor : public Player
{
private:
    /* data */
public:
    Player& treat(const City &c){
        
        if (_board.cities_map[_city]._connected_cities.count(c) == 1 || _city == c)
        {
            if (_board.cities_map[c]._number_of_dice > 0)
            {   
                Color curr_color = _board.cities_map[c]._color;
                if (_board._is_cure_found[curr_color])
                {
                    _board.cities_map[c]._number_of_dice = 0;
                }
                else{
                    _board.cities_map[c]._number_of_dice--;
                } 

            }
            else{
                 throw std::invalid_argument("number of dice is already 0");
            }
        }

        return *this;
        
    } //can treat any city that is connected to the specific City without throwing card

    std::string role(){
            return "FieldDoctor";
        }
    FieldDoctor(Board &board, City city):Player(board,city){}
    ~FieldDoctor(){}
};


};