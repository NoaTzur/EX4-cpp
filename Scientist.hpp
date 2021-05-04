
#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist: public Player
    {
    private:
        int _n; //number of card to discover
    public:

        Player& discover_cure (const Color &color) {
            int counter = 0;
            if (_board.cities_map[_city]._is_station)
            {
                
                std::set<City> temp_cards;

                if (_n == 0)
                {
                    _board._is_cure_found[color] = true; //cure
                }
                
                for (auto card : _player_cards) //checks if there is 5 cards from the same color
                {
                    if (counter == _n)
                    {
                        _board._is_cure_found[color] = true; //cure
                        for (auto card : temp_cards) //throw n cards
                        {
                            _player_cards.erase(card);
                            // this->_board.cities_map.at(card)._card_exist = true;
                        }
                        break;
                    }
                    
                    if (_board.cities_map[card]._color == color)
                    {
                        counter++;
                        temp_cards.insert(_board.cities_map[card]._city);
                    
                    }
                    
                }       
            }
            if (counter < _n)
            {
                throw std::invalid_argument("not enough cards");
            }
            if (!(_board.cities_map[_city]._is_station))
            {
                 throw std::invalid_argument("this city is not a research station");
            }

            return *this;
        }

      std::string role(){
            return "Scientist";
        }
        
        Scientist(Board &board, City city, int n):_n(n), Player(board,city){}
        ~Scientist() {}
    };


};