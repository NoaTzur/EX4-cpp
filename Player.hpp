#pragma once
#include <string>
#include "City.hpp"
#include <set>
#include "Color.hpp"
namespace pandemic {
class Board;
class Player
{
protected:
    std::set<City> _player_cards;
    Board& _board;
    City _city;
public:

    virtual Player& drive(const City& c);
    virtual Player& fly_direct(const City &c) ;
    virtual Player& fly_charter(const City &c) ;
    virtual Player& fly_shuttle(const City &c);
    virtual Player& build();
    virtual Player& discover_cure (const Color &color) ;
    virtual Player& treat(const City &c);

    virtual std::string role();
    Player& take_card(const City& c);

    Player(Board &board, City city);
    ~Player();



};


};