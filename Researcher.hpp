#pragma once

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {


    class Researcher : public Player
    {
    private:
        
    public:

        Player& discover_cure (const Color &color) {
            int counter = 0;
            if (!(_board._is_cure_found[color]))
            {

                
                std::set<City> temp_cards;

                for (auto card : _player_cards) //checks if there is 5 cards from the same color
                {
                    if (counter == 5)
                    {
                        break;
                    }
                    
                    if (_board.cities_map[card]._color == color)
                    {
                        counter++;
                        temp_cards.insert(_board.cities_map[card]._city);
                    
                    }   
                }

                if (counter == 5)
                {
                    _board._is_cure_found[color] = true; //cure
                    for (auto card : temp_cards) //throw 5 cards
                    {
                        _player_cards.erase(card);
                        // this->_board.cities_map.at(card)._card_exist = true;
                    }
                }       
            }
            if (counter < 5)
            {
                throw std::invalid_argument("this city is not a research station");
            }
            

            return *this; 
        
        } //dont need to be in a research station

        std::string role(){
            return "Researcher";
        }
        
        Researcher(Board &board, City city):Player(board,city){}
        ~Researcher(){}
    };
    
    
};