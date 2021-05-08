#pragma once

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {

    class Virologist : public Player 
    {
    private:
        
    public:

        Player& treat(const City &c){
            
            if(this->_player_cards.count(c) == 1 || c == this->_city){

                if (c != this->_city)//the virilogist is in the city we want to cure
                {
                    _player_cards.erase(c);  //erase the card from the playes list                
                    
                }

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
            }
            else {
                throw std::invalid_argument("this card isnt in the list of cards of this player");
            }

            return *this;
        } // can call this func for every city

        std::string role(){
            return "Virologist";
        }
        Virologist(Board &board, City city):Player(board,city){}
        ~Virologist(){}
    };
    

};
