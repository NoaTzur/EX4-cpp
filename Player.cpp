#include "Player.hpp"
#include "Board.hpp"
#include <algorithm>
using namespace std;
namespace pandemic {


Player& Player::fly_charter(const City &c) {
    
    if(this->_player_cards.count(_city) == 1 ){
        //erase player from the list of players of the previus city
        _board.cities_map[_city]._players_on_square.erase(this);
        _player_cards.erase(_city);
        // this->_board.cities_map.at(_city)._card_exist = true;

        _city = c;
        _board.cities_map[_city]._players_on_square.insert(this); // adding the player to the new Square(new city)
       
    }
    else{
         throw std::invalid_argument("the city player is in now is not in the players cards");
    }
    return *this;
    
}
Player& Player::fly_shuttle(const City &c){
    
    if(_board.cities_map[_city]._is_station &&  _board.cities_map[c]._is_station){
        //erase player from the list of players of the previus city
        _board.cities_map[_city]._players_on_square.erase(this);
        _city = c;
        _board.cities_map[_city]._players_on_square.insert(this); // adding the player to the new Square(new city)

    }
    else{
         throw std::invalid_argument("one of the cities is not a research station");
    }

   return *this;

}

Player& Player::build(){
    
    if (!(_board.cities_map[_city]._is_station) && _player_cards.count(_city) == 1 )
    {
        _player_cards.erase(_city);
        // this->_board.cities_map.at(_city)._card_exist = true;
        _board.cities_map[_city]._is_station = true;

    }
    else{
         throw std::invalid_argument("not in the player cards or already a research station");
    }
    
    
    return *this;
    
}
Player& Player::discover_cure (const Color &color) {
    int counter = 0;

    if (_board.cities_map[_city]._is_station)
    {

        set<City> temp_cards;

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
        throw std::invalid_argument("not enough cards for this color");
    }
    
    if (!(_board.cities_map[_city]._is_station))
    {
        throw std::invalid_argument("this city is not a research station");
    }

    return *this;
    
    }
Player& Player::treat(const City &c){
    if (_city != c)
    {
        throw std::invalid_argument("the player is not in this city !");
    }
    

    if (_board.cities_map[_city]._number_of_dice > 0)
    {   
        Color curr_color = _board.cities_map[_city]._color;
        if (_board._is_cure_found[curr_color])
        {
            _board.cities_map[_city]._number_of_dice = 0;
        }
        else{
            _board.cities_map[_city]._number_of_dice--;
        } 

    }
    else{
         throw std::invalid_argument("number of dice is already 0");
    }

    return *this;
    
    }

    std::string Player::role(){
            return "Virologist";
        }


Player& Player::take_card(const City& c){
    
    // bool temp = this->_board.cities_map.at(c)._card_exist;
    // if (temp)
    // {
    //    this->_board.cities_map.at(c)._card_exist = false; 
    this->_player_cards.insert(c);
    // }

    return *this;
    }

Player& Player::drive(const City& c){

    if (this->_board.cities_map[_city]._connected_cities.count(c) == 1){
            
        //erase player from the list of players of the previus city
        _board.cities_map[_city]._players_on_square.erase(this);
        _city = c;
        _board.cities_map[_city]._players_on_square.insert(this); // adding the player to the new Square(new city)
            
    }
    else{
         throw std::invalid_argument("cant drive to this city because it is not connected");
    }
    return *this; 
}

Player& Player::fly_direct(const City &c) {
    
    if(this->_player_cards.count(c) == 1 ){
        //erase player from the list of players of the previus city
        _board.cities_map[_city]._players_on_square.erase(this);
        // this->_board.cities_map.at(c)._card_exist = true;

        _city = c;
        _board.cities_map[_city]._players_on_square.insert(this); // adding the player to the new Square(new city)
        _player_cards.erase(c);
    }
    else{
         throw std::invalid_argument("this city is not in the players cards");
    }
    return *this;
}

Player::Player(Board &board, City city): _board(board), _city(city){
    
}

Player::~Player() {}

};