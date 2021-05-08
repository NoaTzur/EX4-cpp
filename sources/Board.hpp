#pragma once
#include "Player.hpp"
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include <list>
#include <set>

namespace pandemic {

class Square
{

    private:
        
    public:
        City _city; //what city in the specific sqaure
        Color _color; //the color of the city   
        int _number_of_dice; // the level of the disease - Dynamic
        bool _is_station; //is the city in a research station - Dynamic
        std::set<City> _connected_cities; //all cities that connected to the major city
        std::set<Player *> _players_on_square; // all players that in the square - Dynamic
        //bool _card_exist;

    
        Square(){}
        Square(City city, Color c, int number_of_dice, std::set<City> connected_cities):_city(city), _color(c), _number_of_dice(number_of_dice){
            // _card_exist = true;
            _players_on_square.clear(); // no players in the square in the beginning
            _is_station = false;//all cities begin as a non-research station 

            // copy the list of cities that connected to the major city
            for (City run: connected_cities)
            {
                _connected_cities.insert(run);
            } 
            

        }
        ~Square();
};

class Board
{
    private:
        
    public:
    std::map<Color, bool> _is_cure_found;
    std::map <City, Square> cities_map;
    void create_board();
    bool is_clean();
    void remove_cures();
    void remove_stations();

    int& operator[](City c){
        
        return (this->cities_map[c]._number_of_dice);
    }

    friend std::ostream& operator<< (std::ostream& output,const Board& b);
    

    Board(){

        create_board();
    }
    ~Board();

};

};