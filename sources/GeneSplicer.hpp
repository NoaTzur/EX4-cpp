#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

class GeneSplicer : public Player
{
private:
    /* data */
public:

    Player& discover_cure (const Color &color) {
        int counter = 0;
        if (_board.cities_map[_city]._is_station)
        {
            std::set<City> temp_cards;
            for (auto card : _player_cards) 
            {
                if (counter == 5)
                {
                    break;
                }
                
                counter++;
                temp_cards.insert(card); 
                  
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
        
        if (!(_board.cities_map[_city]._is_station))
        {
            throw std::invalid_argument("this city is not a research station");
        }

        return *this;


    } //can throw any 5 cards 


    std::string role(){
            return "GeneSplicer";
        }
    GeneSplicer(Board &board, City city):Player(board,city){}
    ~GeneSplicer(){}
};

};